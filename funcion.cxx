#include "interfaz.h"
#include <iostream>
#include <sstream>
#include "colors.h"


// Definición de TADs

struct Territorio {
    int identificador;
    std::string nombre;
};

struct Dado {
    int numero;
};

struct Ejercito {
    std::string tipo;
    std::string color;
};

struct Tarjeta {
    std::string tipo;
    std::string dibujo;
};

struct Jugador {
    int id;
    std::string nombre;
    std::vector<Territorio> territorios;
    std::vector<Ejercito> unidades;
    int numeroUni;
    std::string color;
    std::vector<Tarjeta> tarjetas;
    int numtarjetas;
};

struct Continente {
    std::string nombre;
    Jugador *jugador;
};

struct EstadoJuego {
    bool juegoInicializado = false;
    bool juegoTerminado = false;
    int turnoActual = 1;
    std::vector<Jugador> jugadores;
};

// Funciones para el Componente 1

void DistribuirUnidades(EstadoJuego &estado) {
}

void ObtenerUnidades(Jugador &jugador) {
}

void RealizarAtaques(EstadoJuego &estado, Jugador &jugador) {
}

void FortificarTerritorios(Jugador &jugador) {
}

void InicializarJuego(EstadoJuego &estado) {
    // Verifica si el juego ya ha sido inicializado previamente
    if (estado.juegoInicializado) {
        std::cout << "El juego ya ha sido inicializado." << std::endl;
        return;
    }

    // Solicita al usuario la cantidad de jugadores para esta partida
    int numJugadores;
    std::cout << "Ingrese la cantidad de jugadores: ";
    std::cin >> numJugadores;

    // Para cada jugador, solicita su nombre y lo agrega al estado del juego
    for (int i = 1; i <= numJugadores; ++i) {
        Jugador jugador;
        jugador.id = i;
        std::cout << "Ingrese el nombre del jugador " << i << ": ";
        std::cin >> jugador.nombre;
        estado.jugadores.push_back(jugador);
    }

    // Asigna unidades iniciales a los territorios de los jugadores
    DistribuirUnidades(estado);

    // Marca el juego como inicializado y muestra un mensaje de éxito
    estado.juegoInicializado = true;
    std::cout << "Inicialización satisfactoria. El juego está listo para comenzar." << std::endl;
}


void RealizarTurno(EstadoJuego &estado, int idJugador) {
    // Verifica si el juego ha sido inicializado correctamente
    if (!estado.juegoInicializado) {
        std::cout << "Esta partida no ha sido inicializada correctamente." << std::endl;
        return;
    }

    // Busca al jugador actual en el estado del juego
    Jugador *jugadorActual = nullptr;
    for (Jugador &jugador : estado.jugadores) {
        if (jugador.id == idJugador) {
            jugadorActual = &jugador;
            break;
        }
    }

    // Verifica si el jugador actual existe en la partida
    if (!jugadorActual) {
        std::cout << "El jugador " << idJugador << " no forma parte de esta partida." << std::endl;
        return;
    }

    // Verifica si el juego ha terminado
    if (estado.juegoTerminado) {
        std::cout << "Esta partida ya ha tenido un ganador." << std::endl;
        return;
    }

    // Verifica si es el turno del jugador actual
    if (idJugador != estado.turnoActual) {
        std::cout << "No es el turno del jugador " << idJugador << "." << std::endl;
        return;
    }

    // Calcula y asigna las unidades adicionales al jugador actual
    ObtenerUnidades(*jugadorActual);

    // Realiza los ataques y actualiza el estado del juego
    RealizarAtaques(estado, *jugadorActual);

    // Permite al jugador fortificar sus territorios
    FortificarTerritorios(*jugadorActual);

    // Actualiza el turno para el próximo jugador
    estado.turnoActual = (estado.turnoActual % estado.jugadores.size()) + 1;

    // Muestra un mensaje indicando que el turno ha terminado
    std::cout << "Turno del jugador " << idJugador << " terminado." << std::endl;
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
            std::cout << "Ingrese el ID del jugador: ";
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
