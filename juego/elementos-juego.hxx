# include <iostream>
# include <sstream>
# include "colors.h"
# include "elementos-juego.h"
# include "elementos-partida.h"

// Unidad

Unidad::Unidad() {
    this->tipoUnidad = "";
    this->valorUnidad = 0;
    this->color = "";
}

Unidad::Unidad(std::string tipoUnidad, std::string color, int valorUnidad) {
    this->tipoUnidad = tipoUnidad;
    this->valorUnidad = valorUnidad;
    this->color = color;
}

std::string Unidad::getTipoUnidad() {
    return this->tipoUnidad;
}

std::string Unidad::getColor() {
    return this->color;
}

int Unidad::getValorUnidad() {
    return this->valorUnidad;
}

void Unidad::setTipoUnidad(std::string tipoUnidad) {
    this->tipoUnidad = tipoUnidad;
}

void Unidad::setColor(std::string color) {
    this->color = color;
}

void Unidad::setValorUnidad(int valorUnidad) {
    this->valorUnidad = valorUnidad;
}

// Jugador

Jugador::Jugador() {
    this->nombre = "";
    this->color = "";
    this->id = 0;
    this->numUnidades = 0;
    this->unidades = {};
    this->tarjetas = {};
    this->Territorios = {};
    this->numTarjetas = 0;
    this->numConquistas = 0;
}

Jugador::Jugador(std::string nombre, std::string color, int id, int numUnidades, std::vector<Unidad> unidades, std::vector<Tarjeta> tarjetas, std::vector<Territorio> Territorios, int numTarjetas, int numConquistas) {
    this->nombre = nombre;
    this->color = color;
    this->id = id;
    this->numUnidades = numUnidades;
    this->unidades = unidades;
    this->tarjetas = tarjetas;
    this->Territorios = Territorios;
    this->numTarjetas = numTarjetas;
    this->numConquistas = numConquistas;
}

std::string Jugador::getNombre() {
    return this->nombre;
}

std::string Jugador::getColor() {
    return this->color;
}

int Jugador::getId() {
    return this->id;
}

int Jugador::getNumUnidades() {
    return this->numUnidades;
}

std::vector<Unidad> Jugador::getUnidades() {
    return this->unidades;
}

std::vector<Tarjeta> Jugador::getTarjetas() {
    return this->tarjetas;
}

std::vector<Territorio> Jugador::getTerritorios() {
    return this->Territorios;
}

int Jugador::getNumTarjetas() {
    return this->numTarjetas;
}

int Jugador::getNumConquistas() {
    return this->numConquistas;
}

void Jugador::setNombre(std::string nombre) {
    this->nombre = nombre;
}

void Jugador::setColor(std::string color) {
    this->color = color;
}

void Jugador::setId(int id) {
    this->id = id;
}

void Jugador::setNumUnidades(int numUnidades) {
    this->numUnidades = numUnidades;
}

void Jugador::setUnidades(std::vector<Unidad> unidades) {
    this->unidades = unidades;
}

void Jugador::setTarjetas(std::vector<Tarjeta> tarjetas) {
    this->tarjetas = tarjetas;
}

void Jugador::setTerritorios(std::vector<Territorio> Territorios) {
    this->Territorios = Territorios;
}

void Jugador::setNumTarjetas(int numTarjetas) {
    this->numTarjetas = numTarjetas;
}

void Jugador::setNumConquistas(int numConquistas) {
    this->numConquistas = numConquistas;
}

void Jugador::infoJugador() {
    std::cout << "Nombre: " << this->nombre << std::endl;
    std::cout << "Color: " << this->color << std::endl;
    std::cout << "Id: " << this->id << std::endl;
    std::cout << "Numero de Unidades: " << this->numUnidades << std::endl;
    std::cout << "Numero de Tarjetas: " << this->numTarjetas << std::endl;
    std::cout << "Numero de Conquistas: " << this->numConquistas << std::endl;
}

int Jugador::reclamables() {

}

void Jugador::reclamar(Territorio territorio) {

}

void Jugador::restarUnidad() {

}

void Jugador::agregarUnidad(Unidad unidad) {

}

Tarjeta Jugador::ObtenerTarjetasTerritorio() {

}

Tarjeta Jugador::ObtenerTarjetasUnidad() {

}

// Territorio

Territorio::Territorio() {
    this->nombre = "";
    this->continente = "";
    this->vecinos = {};
    this->id = 0;
    this->numUnidades = 0;
}

Territorio::Territorio(std::string nombre, std::string continente, int id, int numUnidades) {
    this->nombre = nombre;
    this->continente = continente;
    this->vecinos = {};
    this->id = id;
    this->numUnidades = numUnidades;
}

std::string Territorio::getNombre() {
    return this->nombre;
}

std::string Territorio::getContinente() {
    return this->continente;
}

std::vector<Territorio> Territorio::getVecinos() {
    return this->vecinos;
}

int Territorio::getId() {
    return this->id;
}

int Territorio::getNumUnidades() {
    return this->numUnidades;
}

void Territorio::setNombre(std::string nombre) {
    this->nombre = nombre;
}

void Territorio::setContinente(std::string continente) {
    this->continente = continente;
}

void Territorio::setVecinos(std::vector<Territorio> vecinos) {
    this->vecinos = vecinos;
}

void Territorio::setId(int id) {
    this->id = id;
}

void Territorio::setNumUnidades(int numUnidades) {
    this->numUnidades = numUnidades;
}

void Territorio::restarUnidad(int numUnidades) {
    this->numUnidades -= numUnidades;
}

void Territorio::agregarUnidad(int numUnidades) {
    this->numUnidades += numUnidades;
}



// Tarjeta

Tarjeta::Tarjeta() {
    this->tipo = "";
    this->Territorio = "";
    this->unidad = "";
}

Tarjeta::Tarjeta(std::string tipo, std::string Territorio, std::string unidad) {
    this->tipo = tipo;
    this->Territorio = Territorio;
    this->unidad = unidad;
}

std::string Tarjeta::getTipo() {
    return this->tipo;
}

std::string Tarjeta::getTerritorio() {
    return this->Territorio;
}

std::string Tarjeta::getUnidad() {
    return this->unidad;
}

void Tarjeta::setTipo(std::string tipo) {
    this->tipo = tipo;
}

void Tarjeta::setTerritorio(std::string Territorio) {
    this->Territorio = Territorio;
}

void Tarjeta::setUnidad(std::string unidad) {
    this->unidad = unidad;
}

