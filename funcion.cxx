#include "interfaz.h"
#include <iostream>
#include <sstream>
#include "colors.h"
//Implementacion de la funcion para mostrar el indicador de linea
void mostrarPrompt() {
    std::cout << "$ ";
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
    std::cout << ORANGE <<"CargarPartida: Ejecuta el comando Cargar.\n"<< RESET;
    std::cout << LBLUE <<"Salir: Ejecuta el comando Cargar.\n" <<RESET;
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

//Implementa la funcion para ejecutar el comando Inicializar
void ejecutarInicializar() {
  system("cls");
  std::cout << "\n";
  std::cout << GREEN <<"----------------------------\n";
  std::cout << "Juego Iniciado! \n";	
  std::cout <<"----------------------------\n";
  std::cout << RESET;
}

//Implementa la funcion para cargar partida
void ejecutarCargar() {
	std::cout << "\n";
  std::cout << ORANGE <<"----------------------------\n";
  std::cout << "Partida Cargada! \n";	
  std::cout <<"----------------------------\n";
  std::cout << RESET;
}

void bienvenido() {
  std::cout << "\n";
  std::cout << CYAN <<"----------------------------\n";
  std::cout << "Bienvenido al juego de Risk \n";	
  std::cout <<"----------------------------\n";
      std::cout <<"\n Para iniciar el juego escriba 'Inicializar'\n Para cargar una partida ya existente escriba 'CargarPartida' \n Si necesita conocer otros comandos escriba 'Ayuda'.\n";
      std::cout <<"----------------------------\n";
      std::cout << RESET;
}

//Implementa la funcion para ejecutar la interfaz
void ejecutarInterfaz() {
    std::string lineaComando;
  

    while (true) {
        mostrarPrompt();
        std::getline(std::cin, lineaComando);

        if (lineaComando == "Ayuda") {
            ejecutarAyuda();
        } else if (lineaComando == "Inicializar") {
            ejecutarInicializar();
        } else if (lineaComando == "CargarPartida") {
            ejecutarCargar();
        } else if (lineaComando == "Salir") {
            std::cout<< LGREEN << "Gracias por jugar. \n" ;
            std::cout << RESET;
            exit(0);
        }
        else {
            std::cout << RED << "Comando no reconocido. Ingrese 'Ayuda' para ver la lista de comandos disponibles.\n";
            std::cout << RESET;
        }
    }
}
