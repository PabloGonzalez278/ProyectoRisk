#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <string>
#include <vector>

//mostrar el indicador de linea de comando ($)
extern void mostrarPrompt();

//ejecutar comando de ayuda
extern void ejecutarAyuda();

//Funcion para inicializar el juego
extern void ejecutarInicializar();

//funcion para cargar las partidas existentes 
extern void ejecutarCargar();

//funcion para ejecutar texto de bienvenida
extern void bienvenido();


// Funcion para obtener los parametros de un comando
extern std::vector<std::string> obtenerParametros(const std::string& lineaComando);

// Funcion para ejecutar la interfaz
extern void ejecutarInterfaz();
#endif