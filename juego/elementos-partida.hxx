#include "elementos-juego.h"
#include <vector>
#include <algorithm>
#include <random>

//Partida

Partida::Partida() {
    this->cantJugadores = 0;
    this->turno = Turno();
    this->tablero = Tablero();
}

Partida::Partida(int cantJugadores, std::queue<Jugador> Jugadores, Turno turno) {
    this->cantJugadores = cantJugadores;
    this->Jugadores = Jugadores;
    this->turno = turno;
}

int Partida::getCantJugadores() {
    return this->cantJugadores;
}

std::queue<Jugador> Partida::getJugadores() {
    return this->Jugadores;
}

Turno Partida::getTurno() {
    return this->turno;
}

void Partida::setCantJugadores() {
    int numJugadores = this->Jugadores.size();
    this->cantJugadores = numJugadores;
}

void Partida::setJugadores(std::queue<Jugador> JugadoresAgregar) {
    this->Jugadores = JugadoresAgregar;
}

void Partida::setTurno(Turno turno) {
    this->turno = turno;
}

void Partida::guardarPartida() {
}


Tablero Partida::getTablero() {
    return this->tablero;
}

void Partida::setTablero(Tablero tablero) {
    this->tablero = tablero;
}

void Partida::crearTablero() {
    Tablero tablero = Tablero();

    setTablero(tablero);
    std::cout << "tablero Creado"<< std::endl;
}

bool Partida::cargarPartida() {
}

bool Partida::ganador() {
}

bool Partida::terminarPartida(Jugador Jugador) {
}

void Partida::repartirElementos(){
    //reparte las unidades, las tarjetas y los territorios a los jugadores

    //reparte los territorios

    int numJugagores = getCantJugadores();

    int numTerritorios = getTablero().getTerritorios().size();

    int numTerritoriosPorJugador = numTerritorios/numJugagores;

    std::vector<Territorio> territorios = getTablero().getTerritorios();



   // Baraja aleatoriamente la lista de territorios
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(territorios.begin(), territorios.end(), g);

    int territoriosPorJugador = numTerritorios / numJugagores;
    int territoriosRestantes = numTerritorios % numJugagores;

    std::queue<Jugador> jugadores = getJugadores();  // Usamos un vector para almacenar a los jugadores
    Jugador jugadorTemp;  


    for (size_t i = 0; i < numTerritorios; i++) {
        jugadorTemp = jugadores.front();
        jugadores.pop();
        jugadorTemp.reclamar(territorios[i]);

        // Avanzar al siguiente jugador
        if (i == territoriosPorJugador - 1 && territoriosRestantes > 0) {
            territoriosRestantes--;
        }

        jugadores.push(jugadorTemp);
    }

    std::cout << "Territorios repartidos"<< std::endl;
  

    //reparte las unidades

    //si hay 6 jugador, cada jugador recibe 20 unidades
    //si hay 5 jugadores, cada jugador recibe 25 unidades
    //si hay 4 jugadores, cada jugador recibe 30 unidades
    //si hay 3 jugadores, cada jugador recibe 35 unidades
    //si hay 2 jugadores, cada jugador recibe 40 unidades

   

        
    // Agregar unidades de acuerdo al numero de jugadores
    // en una partida de 6 jugadores cada uno recibe 5 infanterias, 1 caballerias y 1 artillerias
    // en una partida de 5 jugadores cada uno recibe 5 infanterias, 2 caballerias y 1 artillerias
    // en una partida de 4 jugadores cada uno recibe 5 infanterias, 3 caballerias y 1 artillerias
    // en una partida de 3 jugadores cada uno recibe 5 infanterias, 2 caballerias y 2 artillerias
    // en una partida de 2 jugadores cada uno recibe 5 infanterias, 3 caballerias y 2 artillerias

            
    int infanteria = 0;
    int caballeria = 0;
    int artilleria = 0;

    if (numJugagores == 6)
    {
        infanteria = 20;
        caballeria = 1;
        artilleria = 1;
    }

    if (numJugagores == 5)
    {
        infanteria = 25;
        caballeria = 2;
        artilleria = 1;
    }

    if (numJugagores == 4)
    {
        infanteria = 30;
        caballeria = 3;
        artilleria = 1;
    }

    if (numJugagores == 3)
    {
        infanteria = 35;
        caballeria = 2;
        artilleria = 2;
    }

    if (numJugagores == 2)
    {
        infanteria = 40;
        caballeria = 3;
        artilleria = 2;
    }

    for(int i = 0; i < numJugagores ; i++) //nunca seran mas de 6 jugadores
    {
        Jugador jugador = this->Jugadores.front();

        this->Jugadores.pop();
        int infanteriaActual = 0;
        int caballeriActual = 0;
        int artilleriaActual = 0;


        for (int i = 0; i< this->tablero.getUnidadesInfanteria().size(); i++){

                if(this->tablero.getUnidadesInfanteria()[i].getColor() == jugador.getColor() && infanteriaActual < infanteria){
                    jugador.agregarUnidad(this->tablero.getUnidadesInfanteria()[i]);
                }

                if(this->tablero.getUnidadesCaballeria()[i].getColor() == jugador.getColor() && caballeriActual < caballeria){
                    jugador.agregarUnidad(this->tablero.getUnidadesCaballeria()[i]);
                }

                if(this->tablero.getUnidadesArtilleria()[i].getColor() == jugador.getColor() && artilleriaActual < artilleria){
                    jugador.agregarUnidad(this->tablero.getUnidadesArtilleria()[i]);
                }
            
        }
        
        
        this->Jugadores.push(jugador);
    
    {
        
    }

}

    std::cout << "Elementos repartidos"<< std::endl;
}

bool Partida::iniciarPartida() {

    this->setCantJugadores();

    std::cout << "repartiendo"<< std::endl;
    this->repartirElementos();
    this->turno = Turno();
    this->turno.setNumTurno(1);
    this->turno.setJugador(this->Jugadores.front());
    this->Jugadores.pop();
    this->turno.setDefensor(this->Jugadores.front());
    this->Jugadores.push(this->turno.getJugador());
    this->turno.iniciarTurno();

    return true;
}


//Tablero

Tablero::Tablero() {
    this->crearTerritorios();
    this->crearUnidades();
    this->crearTarjetas();

}

Tablero::Tablero(std::vector<Territorio> Territorios, std::vector<Tarjeta> Tarjetas, std::vector<Unidad> unidadesInfanteria, std::vector<Unidad> unidadesArtilleria, std::vector<Unidad> unidadesCaballeria) {
    this->Territorios = Territorios;
    this->Tarjetas = Tarjetas;
    this->unidadesInfanteria = unidadesInfanteria;
    this->unidadesArtilleria = unidadesArtilleria;
    this->unidadesCaballeria = unidadesCaballeria;
}

std::vector<Territorio> Tablero::getTerritorios() {
    return this->Territorios;
}

std::vector<Tarjeta> Tablero::getTarjetas() {
    return this->Tarjetas;
}

std::vector<Unidad> Tablero::getUnidadesInfanteria() {
    return this->unidadesInfanteria;
}

std::vector<Unidad> Tablero::getUnidadesArtilleria() {
    return this->unidadesArtilleria;
}

std::vector<Unidad> Tablero::getUnidadesCaballeria() {
    return this->unidadesCaballeria;
}

void Tablero::setTerritorios(std::vector<Territorio> Territorios) {
    this->Territorios = Territorios;
}

void Tablero::setTarjetas(std::vector<Tarjeta> Tarjetas) {
    this->Tarjetas = Tarjetas;
}

void Tablero::setUnidadesInfanteria(std::vector<Unidad> unidades) {
    this->unidadesInfanteria = unidades;
}

void Tablero::setUnidadesArtilleria(std::vector<Unidad> unidades) {
    this->unidadesArtilleria = unidades;
}

void Tablero::setUnidadesCaballeria(std::vector<Unidad> unidades) {
    this->unidadesCaballeria = unidades;
}

void Tablero::crearUnidades() {
    std::vector<Unidad> unidadesInfanteria;
    std::vector<Unidad> unidadesArtilleria;
    std::vector<Unidad> unidadesCaballeria;

    // habran 6 ciclo for, uno por cada color de unidad
    // cada ciclo for creara 3 unidades del mismo color
    // cada ciclo creara una unidad de cada tipo de unidad

    //En total habran 18 unidades por cada color de unidad
    //En total habran 108 unidades
    //20 de infanteria
    //20 de caballeria
    //20 de artilleria

    for (size_t i = 0; i < 20; i++)
    {
        Unidad unidad = Unidad("Infanteria", "Rojo", 1);
        unidadesInfanteria.push_back(unidad);

        unidad = Unidad("Infanteria", "Azul", 1);
        unidadesInfanteria.push_back(unidad);

        unidad = Unidad("Infanteria", "Amarillo", 1);
        unidadesInfanteria.push_back(unidad);

        unidad = Unidad("Infanteria", "Verde", 1);
        unidadesInfanteria.push_back(unidad);

        unidad = Unidad("Infanteria", "Morado", 1);
        unidadesInfanteria.push_back(unidad);

        unidad = Unidad("Infanteria", "Cafe", 1);
        unidadesInfanteria.push_back(unidad);



      
        unidad = Unidad("Caballeria", "Rojo", 5);
        unidadesCaballeria.push_back(unidad);
        
        unidad = Unidad("Caballeria", "Azul", 5);
        unidadesCaballeria.push_back(unidad);

        unidad = Unidad("Caballeria", "Amarillo", 5);
        unidadesCaballeria.push_back(unidad);

        unidad = Unidad("Caballeria", "Verde", 5);
        unidadesCaballeria.push_back(unidad);

        unidad = Unidad("Caballeria", "Morado", 5);
        unidadesCaballeria.push_back(unidad);

        unidad = Unidad("Caballeria", "Cafe", 5);
        unidadesCaballeria.push_back(unidad);




        unidad = Unidad("Artilleria", "Rojo", 10);
        unidadesArtilleria.push_back(unidad);
        
        unidad = Unidad("Artilleria", "Azul", 10);
        unidadesArtilleria.push_back(unidad);

        unidad = Unidad("Artilleria", "Amarillo", 10);
        unidadesArtilleria.push_back(unidad);

        unidad = Unidad("Artilleria", "Verde", 10);
        unidadesArtilleria.push_back(unidad);

        unidad = Unidad("Artilleria", "Morado", 10);
        unidadesArtilleria.push_back(unidad);

        unidad = Unidad("Artilleria", "Cafe", 10);
        unidadesArtilleria.push_back(unidad);
    }

    setUnidadesInfanteria(unidadesInfanteria);
    setUnidadesCaballeria(unidadesCaballeria);
    setUnidadesArtilleria(unidadesArtilleria);
    
    std::cout << "Unidades creadas"<< std::endl;
}


void Tablero::crearTerritorios() {
    
        std::vector<Territorio> territorios;
    
        //Territorios de America del Norte
        Territorio territorio = Territorio("Alaska", "America del Norte", 1, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Territorio del Noroeste", "America del Norte", 2, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Groenlandia", "America del Norte", 3, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Alberta", "America del Norte", 4, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Ontario", "America del Norte", 5, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Canada del este", "America del Norte", 6, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Estados Unidos del Este", "America del Norte", 7, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Estados Unidos del Oeste", "America del Norte", 8, 0);
        territorios.push_back(territorio);
        territorio = Territorio("America Central", "America del Norte", 9, 0);
        territorios.push_back(territorio);
    
        //Territorios de America del Sur
        territorio = Territorio("Venezuela", "America del Sur", 10, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Peru", "America del Sur", 11, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Argentina", "America del Sur", 12, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Brasil", "America del Sur", 13, 0);
        territorios.push_back(territorio);
    
        //Territorios de Europa
        territorio = Territorio("Islandia", "Europa", 14, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Gran Bretaña", "Europa", 15, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Escandinavia", "Europa", 16, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Rusia", "Europa", 17, 1);
        territorios.push_back(territorio);
        territorio = Territorio("Europa del Norte", "Europa", 18, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Europa del Sur", "Europa", 19, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Europa del Oeste", "Europa", 20, 0);
        territorios.push_back(territorio);

        //Territorios de Africa
        territorio = Territorio("Egipto", "Africa", 21, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Africa del Norte", "Africa", 22, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Africa central", "Africa", 23, 0);
        territorios.push_back(territorio);
        territorio = Territorio("surafrica", "Africa", 24, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Madagascar", "Africa", 25, 0);

        //Territorios de Asia
        territorio = Territorio("Oriente Medio", "Asia", 26, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Afganistan", "Asia", 27, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Ural", "Asia", 28, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Siberia", "Asia", 29, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Yakutia", "Asia", 30, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Chita", "Asia", 31, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Kamchatka", "Asia", 32, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Mongolia", "Asia", 33, 0);
        territorios.push_back(territorio);
        territorio = Territorio("China", "Asia", 34, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Siam", "Asia", 35, 0);
        territorios.push_back(territorio);
        territorio = Territorio("India", "Asia", 36, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Japon", "Asia", 37, 0);
        territorios.push_back(territorio);

        //Territorios de Oceania

        territorio = Territorio("Indonesia", "Oceania", 38, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Nueva Guinea", "Oceania", 39, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Australia Occidental", "Oceania", 40, 0);
        territorios.push_back(territorio);
        territorio = Territorio("Australia Oriental", "Oceania", 41, 0);
        territorios.push_back(territorio);

        std::cout << "Territorios creados"<< std::endl;
        
}

void Tablero::crearTarjetas() {

std::vector<Tarjeta> tarjetas;



//cartas comodin
Tarjeta tarjeta = Tarjeta("Comodin", "", "");
tarjetas.push_back(tarjeta);
tarjetas.push_back(tarjeta);

//cartas de territorio

for (size_t i = 0; i < this->getTerritorios().size(); i++)
{

    //variable que aleatoriamente escoge el tipo de unidad
    int tipoUnidad = rand() % 10 + 1;

    if (tipoUnidad <= 5)
    {
        tarjeta = Tarjeta("Territorio", this->getTerritorios()[i].getNombre(), "Infanteria");
    }

    if (tipoUnidad > 5 && tipoUnidad <= 8)
    {
        tarjeta = Tarjeta("Territorio", this->getTerritorios()[i].getNombre(), "Caballeria");
    }

    if (tipoUnidad > 8)
    {
        tarjeta = Tarjeta("Territorio", this->getTerritorios()[i].getNombre(), "Artilleria");
    }


    tarjetas.push_back(tarjeta);
}

setTarjetas(tarjetas);
std::cout << "Tarjetas creadas"<< std::endl;

}

//Turno

Turno::Turno() {
    this->jugador =  Jugador();
    this->defensor = Jugador();
    this->numAtaque = 0;
    this->numDefensa = 0;
    this->numTurno = 0;
}

Turno::Turno(Jugador jugador, Jugador defensor, int numAtaque, int numDefensa, int numTurno) {
    this->jugador = jugador;
    this->defensor = defensor;
    this->numAtaque = numAtaque;
    this->numDefensa = numDefensa;
    this->numTurno = numTurno;
}

Jugador Turno::getJugador() {
    return this->jugador;
}

Jugador Turno::getDefensor() {
    return this->defensor;
}

int Turno::getNumAtaque() {
    return this->numAtaque;
}

int Turno::getNumDefensa() {
    return this->numDefensa;
}

int Turno::getNumTurno() {
    return this->numTurno;
}

void Turno::setJugador(Jugador jugador) {
    this->jugador = jugador;
}

void Turno::setDefensor(Jugador defensor) {
    this->defensor = defensor;
}

void Turno::setNumAtaque(int numAtaque) {
    this->numAtaque = numAtaque;
}

void Turno::setNumDefensa(int numDefensa) {
    this->numDefensa = numDefensa;
}

void Turno::setNumTurno(int numTurno) {
    this->numTurno = numTurno;
}

// Por Hacer

void Turno::atacar() {
}

void Turno::fortificar() {
}

int Turno::costoConquista() {
}

std::string Turno::conquistaBarata() {
}





void Turno::iniciarTurno() {


    std::cout << "Turno del Jugador " << this->getJugador().getId() << " iniciado." << std::endl;

    // Busca al Jugador actual en el estado del juego
    Jugador jugadorActual = this->getJugador();

    
    // Calcula y asigna las unidades adicionales al Jugador actual
    

    // Realiza los ataques y actualiza el estado del juego
    atacar();

    // Permite al Jugador fortificar sus territorios
    fortificar();

    // Actualiza el turno para el próximo Jugador
    this->numTurno = this->numTurno +1;

    // Muestra un mensaje indicando que el turno ha terminado
    std::cout << "Turno del Jugador " << jugadorActual.getId() << " terminado." << std::endl;

}

int Turno::tiraDados(int numDados) {
}