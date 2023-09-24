#include "interfaz.h"
#include <iostream>
#include <sstream>
#include "colors.h"
#include "juego/elementos-juego.h"
#include "juego/elementos-partida.h"

#include <string>
#include <iostream>
#include <queue>





struct EstadoJuego {
    bool juegoInicializado = false;
    bool juegoTerminado = false;
    int turnoActual = 1;
};

// Funciones para el Componente 1

void DistribuirUnidades(EstadoJuego &estado) {
}

void ObtenerUnidades(Jugador &Jugador) {
}

void RealizarAtaques(EstadoJuego &estado, Jugador &Jugador) {
}

void FortificarTerritorios(Jugador &Jugador) {
}








Partida InicializarJuego(EstadoJuego &estado) {
    // Verifica si el juego ya ha sido inicializado previamente
    if (estado.juegoInicializado) {
        std::cout << "El juego ya ha sido inicializado." << std::endl;
        return;
    }

    // Crea una nueva partida
    Partida nuevaPartida = Partida();
    


    // Solicita al usuario la cantidad de Jugadores para esta partida
    int numJugadores;
    std::queue<Jugador> jugadores;
    std::cout << "Ingrese la cantidad de Jugadores: ";
    std::cin >> numJugadores;



    // Para cada Jugador, solicita su nombre y lo agrega al estado del juego
    for (int i = 1; i <= numJugadores; ++i) {
        Jugador jugador;
        std::string nombreJugador;
        std::string colorJugador;
        jugador.setId(i);
        std::cout << "Ingrese el nombre del Jugador " << i << ": ";
        std::cin >> nombreJugador;
        std::cout << "Ingrese el color del Jugador " << i << ": ";
        std::cin >> colorJugador;
        jugador.setNombre(nombreJugador);
        jugador.setColor(colorJugador);
        jugadores.push(jugador);
    }

    // Asigna los Jugadores al estado del juego

    nuevaPartida.setJugadores(jugadores);

    // Partida crea un nuevo tablero y lo asigna a la partida

    nuevaPartida.crearTablero();

    // crea las unidades y las tarjetas y las asigna al tablero

    nuevaPartida.getTablero().crearUnidades();
    nuevaPartida.getTablero().crearTarjetas();

    //asigna a los jugadores las unidades y las tarjetas

    nuevaPartida.repartirElementos();

    // Marca el juego como inicializado y muestra un mensaje de éxito

    bool inicio = nuevaPartida.iniciarPartida();
    if (inicio == true){
    estado.juegoInicializado = true;
    std::cout << "Inicialización satisfactoria. El juego está listo para comenzar." << std::endl;
    return nuevaPartida;
    } else {
    std::cout << "Inicialización fallida. El juego no está listo para comenzar." << std::endl;
    }

    // Marca el juego como inicializado y muestra un mensaje de éxito
    
}











void RealizarTurno(EstadoJuego &estado, int idJugador) {
    // Verifica si el juego ha sido inicializado correctamente
    if (!estado.juegoInicializado) {
        std::cout << "Esta partida no ha sido inicializada correctamente." << std::endl;
        return;
    }

    // Busca al Jugador actual en el estado del juego
    Jugador *JugadorActual = nullptr;
    for (Jugador &Jugador : estado.Jugadores) {
        if (Jugador.getId() == idJugador) {
            JugadorActual = &Jugador;
            break;
        }
    }

    // Verifica si el Jugador actual existe en la partida
    if (!JugadorActual) {
        std::cout << "El Jugador " << idJugador << " no forma parte de esta partida." << std::endl;
        return;
    }

    // Verifica si el juego ha terminado
    if (estado.juegoTerminado) {
        std::cout << "Esta partida ya ha tenido un ganador." << std::endl;
        return;
    }

    // Verifica si es el turno del Jugador actual
    if (idJugador != estado.turnoActual) {
        std::cout << "No es el turno del Jugador " << idJugador << "." << std::endl;
        return;
    }

    // Calcula y asigna las unidades adicionales al Jugador actual
    ObtenerUnidades(*JugadorActual);

    // Realiza los ataques y actualiza el estado del juego
    RealizarAtaques(estado, *JugadorActual);

    // Permite al Jugador fortificar sus territorios
    FortificarTerritorios(*JugadorActual);

    // Actualiza el turno para el próximo Jugador
    estado.turnoActual = (estado.turnoActual % estado.Jugadores.size()) + 1;

    // Muestra un mensaje indicando que el turno ha terminado
    std::cout << "Turno del Jugador " << idJugador << " terminado." << std::endl;
}










//Implementacion de la funcion para ejecutar el comando de ayuda
void ejecutarAyuda() {
    
  //Se imprime en pantalla la lista de comandos disponibles 
    std::cout << "\n";
    std::cout << MAGENTA <<"--------------------------------------------\n";
    std::cout << MAGENTA <<"          Comandos disponibles\n";
    std::cout << MAGENTA <<"--------------------------------------------\n"<< RESET;
    std::cout << "\n";
    std::cout << YELLOW<<"Ayuda: Muestra la lista de comandos disponibles.\n"<< RESET;
    std::cout << GREEN <<"Inicializar: Ejecuta el comando Inicializar.\n"<< RESET;
    std::cout << CYAN <<"Turno: Ejecuta el comando Turno.\n"<< RESET;
    std::cout << LGREEN <<"Guardar: Ejecuta el comando Guardar.\n"<< RESET;
    std::cout << LGREEN <<"Guardar_comprimido: Ejecuta el comando Guardar_comprimido.\n"<< RESET;
    std::cout << WHITE <<"Costo_conquista: Ejecuta el comando Costo_conquista.\n"<< RESET;
    std::cout << WHITE <<"Conquista_mas_barata: Ejecuta el comando Costo_mas_barata.\n"<< RESET;
    std::cout << ORANGE <<"CargarPartida: Ejecuta el comando Cargar.\n"<< RESET;
    std::cout << LBLUE <<"Salir: Ejecuta el comando Salir.\n" <<RESET;
    std::cout << MAGENTA <<"--------------------------------------------\n";
    std::cout << RESET;
}

//Implementacion de la funcion para obtener los parametros de un comando
std::vector<std::string> obtenerParametros(const std::string& lineaComando) {
    std::vector<std::string> parametros;
    std::istringstream iss(lineaComando);

    std::string parametro;
    while (iss >> parametro) {
        parametros.push_back(parametro);
    }

    return parametros;
}

//Implementa la funcion para cargar partida
void ejecutarCargar() {
	std::string NomPartida;
	std::string partidaguardada="partida1"; //Cuando se involucre el componente 2 se reemplazara por el nombre de la partida que se a guardado.S
	std::cout << "\n";
	std::cout << "Introduzca el nombre de la partida guardada: ";
	std::cin >> NomPartida;
	if(NomPartida != partidaguardada){
	std::cout << RED << "Lo lamento no encuentro esa partida, intente nuevamente.";
	return;	
	} else if(NomPartida == partidaguardada) {
  std::cout << ORANGE <<"----------------------------\n";
  std::cout << "Partida Cargada! \n";	
  std::cout <<"----------------------------\n";
  std::cout << RESET;
  }
}
//Implementa la funcion de bienvenida al juego
void bienvenido() {
  std::cout << "\n";
  std::cout << CYAN <<"----------------------------\n";
  std::cout << "Bienvenido al juego de Risk \n";	
  std::cout <<"----------------------------\n";
      std::cout <<"\n Para iniciar el juego escriba 'Inicializar'\n Para jugar un Turno escriba 'Turno'\n Para cargar una partida ya existente escriba 'CargarPartida' \n Si necesita conocer otros comandos escriba 'Ayuda'.\n";
      std::cout <<"----------------------------\n";
      std::cout << RESET;
}

//Implementa la funcion para ejecutar la interfaz
void ejecutarInterfaz() {
    std::string lineaComando;
    EstadoJuego estado; // Creación de la instancia del estado del juego
    while (true) {
        std::string comando;
        std::cout << "$ "; // Prompt
        std::cin >> comando;
	        if (comando == "Ayuda") {
            ejecutarAyuda();
        }else if (comando == "Inicializar") { // Comando para inicializar el juego
            InicializarJuego(estado); // Llama a la función para inicializar el juego
        } else if (comando == "Turno") { // Comando para realizar un turno
            int idJugador;
            std::cout << "Ingrese el ID del Jugador: ";
            std::cin >> idJugador;
            RealizarTurno(estado, idJugador); // Llama a la función para realizar el turno
        }else if (comando == "Guardar") { // Comando para guardar la partida en archivo de texto
        	//GuardarPartidatxt();
        }else if (comando == "Guardar_comprimido") { // Comando para guardar la partida en archivo bin
        	//GuardarPartidabin();
	}else if (comando == "Costo_conquista") { // Comando para calcular el costo de la conquista
        	//CostoConquista();
        }else if (comando == "Conquista_mas_barata:") { // Comando para calcular el la conquista mas barata
        	//CostoConquista();			
        } else if (comando == "Salir") { // Comando para salir del juego
            exit(1);
            break; // Termina el bucle y finaliza el juego
        } else if (comando == "CargarPartida") {
            ejecutarCargar();   
        } else { // Comando no válidoS
            std::cout << RED << "Comando no reconocido. Ingrese 'Ayuda' para ver la lista de comandos disponibles\n";
            std::cout << RESET;
        }
    }
}



//Guardado de partida en archivo de texto
