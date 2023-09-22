// en este archivo estan los encabezados de todos los elementos usado en el juego, tales como las unidades

#ifndef ELEMENTOS_JUEGO_H
#define ELEMENTOS_JUEGO_H

#include <string>

template <class T>
class Unidad {
    public:
        Unidad();
        Unidad(std::string tipoUnidad, std::string color, T valorUnidad);
        std::string getTipoUnidad();
        std::string getColor();
        T getValorUnidad();
        void setTipoUnidad(std::string tipoUnidad);
        void setColor(std::string color);
        void setValorUnidad(T valorUnidad);
    private:
        std::string tipoUnidad;
        std::string color;
        T valorUnidad
};

template <class T>
class jugador {
    public:
        jugador();
        jugador(std::string nombre, std::string color, int id, int numUnidades, std::vector<Unidad> unidades, std::list<Unidad> tarjetas, std::list<T> territorios, int numTarjetas, int numConquistas);
        std::string getNombre();
        std::string getColor();
        int getId();
        int getNumUnidades();
        std::list<Unidad> getUnidades();
        std::list<tarjetas> getTarjetas();
        std::list<territorio> getTerritorios();
        int getNumTarjetas();
        int getNumConquistas();
        void setNombre(std::string nombre);
        void setColor(std::string color);
        void setId(int id);
        void setNumUnidades(int numUnidades);
        void setUnidades(std::list<Unidad> unidades);
        void setTarjetas(std::list<Unidad> tarjetas);
        void setTerritorios(std::list<T> territorios);
        void setNumTarjetas(int numTarjetas);
        void setNumConquistas(int numConquistas);
        void infoJugador();
        int reclamables();
        void reclamar(territorio territorio);
        void restarUnidad();
        void agregarUnidad(Unidad unidad);
        tarjetas ObtenerTarjetasTerritorio();
        tarjetas ObtenerTarjetasUnidad();
    private:
        std::string nombre;
        std::string color;
        int id;
        int numUnidades;
        std::list<tarjetas> unidades;
        std::list<Unidad> tarjetas;
        std::list<territorio> territorios;
        int numTarjetas;
        int numConquistas;
};

template <class T>
class territorio {
    public:
        territorio();
        territorio(std::string nombre, std::string continente, int id, int numUnidades);
        std::string getNombre();
        std::string getContinente();
        std::list<territorio> getVecinos();
        int getId();
        int getNumUnidades();
        void setNombre(std::string nombre);
        void setContinente(std::string continente);
        void setVecinos(std::list<territorio> vecinos);
        void setId(int id);
        void setNumUnidades(int numUnidades)
        void restarUnidad(int numUnidades);
        void agregarUnidad(int numUnidades);

    private:
        std::string nombre;
        std::string continente;
        std::list::<territorio> vecinos;
        int id;
        int numUnidades;
};

template <class T>
class tarjetas {
    public:
        tarjetas();
        tarjetas(std::string tipo, std::string territorio, std::string unidad);
        std::string getTipo();
        std::string getTerritorio();
        std::string getUnidad();
        void setTipo(std::string tipo);
        void setTerritorio(std::string territorio);
        void setUnidad(std::string unidad);
    private:
        std::string tipo;
        std::string territorio;
        std::string unidad;
};


#endif // ELEMENTOS_JUEGO_H