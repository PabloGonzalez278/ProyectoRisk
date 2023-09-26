//archivo que contiene la bases del juego, tablero, partida, etc

#ifndef ELEMENTOS_PARTIDA_H
#define ELEMENTOS_PARTIDA_H

#include "elementos-juego.h"
#include <queue>
#include <iostream>


class Partida {
    private:
    int cantJugadores;
    std::queue<Jugador> Jugadores;
    Turno turno;
    Tablero tablero;
    public:
    Partida();
    Partida(int cantJugadores, std::queue<Jugador> Jugadores, Turno turno);
    int getCantJugadores();
    std::queue<Jugador> getJugadores();
    Turno getTurno();
    void setCantJugadores(int cantJugadores);
    void setJugadores(std::queue<Jugador> Jugadores);
    void setTurno(Turno turno);
    void guardarPartida();
    void setTablero(Tablero tablero);
    Tablero crearTablero();
    Tablero getTablero();
    bool cargarPartida();
    bool ganador();
    bool terminarPartida(Jugador Jugador);
    void repartirElementos();
    bool iniciarPartida();
};


class Tablero{
    private:
    std::vector<Territorio> Territorios;
    std::vector<Tarjeta> Tarjetas;
    std::vector<Unidad> unidadesInfanteria;
    std::vector<Unidad> unidadesArtilleria;
    std::vector<Unidad> unidadesCaballeria;
    public:
    Tablero();
    Tablero(std::vector<Territorio> Territorios, Partida partida, std::vector<Tarjeta> Tarjetas, std::vector<Unidad> unidadesInfanteria, std::vector<Unidad> unidadesArtilleria, std::vector<Unidad> unidadesCaballeria);
    std::vector<Territorio> getTerritorios();
    std::vector<Tarjeta> getTarjetas();
    std::vector<Unidad> getUnidadesInfanteria();
    std::vector<Unidad> getUnidadesArtilleria();
    std::vector<Unidad> getUnidadesCaballeria();
    void setTerritorios(std::vector<Territorio> Territorios);
    void setTarjetas(std::vector<Tarjeta> Tarjetas);
    void setUnidadesInfanteria(std::vector<Unidad> unidades);
    void setUnidadesArtilleria(std::vector<Unidad> unidades);
    void setUnidadesCaballeria(std::vector<Unidad> unidades);
    void crearUnidades();
    void crearTarjetas(std::vector<Territorio> territorios);
    void crearTerritorios();

};


class Turno{
    private:
    Jugador jugador;
    Jugador defensor;
    int numAtaque;
    int numDefensa;
    int numTurno;
    public:
    Turno();
    Turno(Jugador jugador, Jugador defensor, int numAtaque, int numDefensa, int numTurno);
    Jugador getJugador();
    Jugador getDefensor();
    int getNumAtaque();
    int getNumDefensa();
    int getNumTurno();
    void setJugador(Jugador jugador);
    void setDefensor(Jugador defensor);
    void setNumAtaque(int numAtaque);
    void setNumDefensa(int numDefensa);
    void setNumTurno(int numTurno);
    void atacar();
    void fortificar();
    int costoConquista();
    std::string conquistaBarata();
    void iniciarTurno();
    int tiraDados(int numDados);
    
};

#include "elementos-partida.hxx"

#endif

