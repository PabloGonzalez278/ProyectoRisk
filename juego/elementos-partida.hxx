#include "../juego/elementos-juego.h"

//Partida

Partida::Partida() {
    this->cantJugadores = 0;
    this->Jugadores = {};
    this->turno = {};
    this->tablero = {};
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

void Partida::setCantJugadores(int cantJugadores) {
    this->cantJugadores = cantJugadores;
}

void Partida::setJugadores(std::queue<Jugador> Jugadores) {
    this->Jugadores = Jugadores;
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

Tablero Partida::crearTablero() {
    Tablero tablero = Tablero();

    setTablero(tablero);
}

bool Partida::cargarPartida() {
}

bool Partida::ganador() {
}

bool Partida::terminarPartida(Jugador Jugador) {
}



//Tablero

Tablero::Tablero() {
    this->Territorios = {};
    this->Tarjetas = {};
    this->unidadesInfanteria = {};
    this->unidadesArtilleria = {};
    this->unidadesCaballeria = {};
}

Tablero::Tablero(std::vector<Territorio> Territorios, Partida partida, std::vector<Tarjeta> Tarjetas, std::vector<Unidad> unidadesInfanteria, std::vector<Unidad> unidadesArtilleria, std::vector<Unidad> unidadesCaballeria) {
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
    std::vector<Unidad> unidades = {};

    // habran 6 ciclo for, uno por cada color de unidad
    // cada ciclo for creara 3 unidades del mismo color
    // cada ciclo creara una unidad de cada tipo de unidad

    //En total habran 18 unidades por cada color de unidad
    //En total habran 108 unidades
    //10 de infanteria
    //6 de caballeria
    //2 de artilleria

    for (size_t i = 0; i < 19; i++)
    {
        Unidad unidad = Unidad("Infanteria", "Rojo", 1);
        unidades.push_back(unidad);
    }
    
}

void Tablero::crearTarjetas() {
}



