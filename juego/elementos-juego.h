// en este archivo estan los encabezados de todos los elementos usado en el juego, tales como las unidades

#ifndef ELEMENTOS_JUEGO_H
#define ELEMENTOS_JUEGO_H

#include <string>


class Unidad {
    public:
        Unidad();
        Unidad(std::string tipoUnidad, std::string color, int valorUnidad);
        std::string getTipoUnidad();
        std::string getColor();
        int getValorUnidad();
        void setTipoUnidad(std::string tipoUnidad);
        void setColor(std::string color);
        void setValorUnidad(int valorUnidad);
    private:
        std::string tipoUnidad;
        std::string color;
        int valorUnidad;
};


class Jugador {
    public:
        Jugador();
        Jugador(std::string nombre, std::string color, int id, int numUnidades, std::vector<Unidad> unidades, std::vector<Tarjeta> tarjetas, std::vector<Territorio> Territorios, int numTarjetas, int numConquistas);
        std::string getNombre();
        std::string getColor();
        int getId();
        int getNumUnidades();
        std::vector<Unidad> getUnidades();
        std::vector<Tarjeta> getTarjetas();
        std::vector<Territorio> getTerritorios();
        int getNumTarjetas();
        int getNumConquistas();
        void setNombre(std::string nombre);
        void setColor(std::string color);
        void setId(int id);
        void setNumUnidades(int numUnidades);
        void setUnidades(std::vector<Unidad> unidades);
        void setTarjetas(std::vector<Tarjeta> tarjetas);
        void setTerritorios(std::vector<Territorio> Territorios);
        void setNumTarjetas(int numTarjetas);
        void setNumConquistas(int numConquistas);
        void infoJugador();
        int reclamables();
        void reclamar(Territorio territorio);
        void restarUnidad();
        void agregarUnidad(Unidad unidad);
        Tarjeta ObtenerTarjetasTerritorio();
        Tarjeta ObtenerTarjetasUnidad();
    private:
        std::string nombre;
        std::string color;
        int id;
        int numUnidades;
        std::vector<Unidad> unidades;
        std::vector<Tarjeta> tarjetas;
        std::vector<Territorio> Territorios;
        int numTarjetas;
        int numConquistas;
};


class Territorio {
    public:
        Territorio();
        Territorio(std::string nombre, std::string continente, int id, int numUnidades);
        std::string getNombre();
        std::string getContinente();
        std::vector<Territorio> getVecinos();
        int getId();
        int getNumUnidades();
        void setNombre(std::string nombre);
        void setContinente(std::string continente);
        void setVecinos(std::vector<Territorio> vecinos);
        void setId(int id);
        void setNumUnidades(int numUnidades);
        void restarUnidad(int numUnidades);
        void agregarUnidad(int numUnidades);

    private:
        std::string nombre;
        std::string continente;
        std::vector<Territorio> vecinos;
        int id;
        int numUnidades;
};


class Tarjeta {
    public:
        Tarjeta();
        Tarjeta(std::string tipo, std::string Territorio, std::string unidad);
        std::string getTipo();
        std::string getTerritorio();
        std::string getUnidad();
        void setTipo(std::string tipo);
        void setTerritorio(std::string Territorio);
        void setUnidad(std::string unidad);
    private:
        std::string tipo;
        std::string Territorio;
        std::string unidad;
};

#include "elementos-juego.hxx"

#endif // ELEMENTOS_JUEGO_H