//archivo que contiene la bases del juego, tablero, partida, etc

#ifndef ELEMENTOS_PARTIDA_H
#define ELEMENTOS_PARTIDA_H

#include "juego/elemenetos-juego.h"



template <class T>
class Partida {
    private:
    int cantJugadores;
    std::queue<jugador> jugadores;
    Turno turno;
    public:
    Partida();
    Partida(int cantJugadores, std::queue<jugador> jugadores, Turno turno);
    int getCantJugadores();
    std::queue<jugador> getJugadores();
    Turno getTurno();
    void setCantJugadores(int cantJugadores);
    void setJugadores(std::queue<jugador> jugadores);
    void setTurno(Turno turno);
    void guardarPartida();
    void cargarPartida();
    bool ganador();
    void terminarPartida(jugador jugador);

};

template <class T>
class Tablero{
    private:
    std::vector<territorio> territorios;
    Partida partida;
    std::vector<tarjeta> tarjetas;
    std::vector<Unidad> unidades;
    public:
    Tablero();
    Tablero(std::vector<territorio> territorios, Partida partida, std::vector<tarjeta> tarjetas, std::vector<Unidad> unidades);
    std::vector<territorio> getTerritorios();
    Partida getPartida();
    std::vector<tarjeta> getTarjetas();
    std::vector<Unidad> getUnidades();
    void setTerritorios(std::vector<territorio> territorios);
    void setPartida(Partida partida);
    void setTarjetas(std::vector<tarjeta> tarjetas);
    void setUnidades(std::vector<Unidad> unidades);

};

template <class T>
class Turno{
    private:
    
    public:
    
};

#endif

