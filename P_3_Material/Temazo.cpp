/** 
 * @brief Implementación de los métodos de la clase Temazo
 * @file Temazo.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 12 de octubre de 2015, 17:08
 */
#include "Temazo.h"
#include "ParametroNoValido.h"
#include <iostream>
#include <sstream>
/**
 * @brief Constructor por defecto de la clase
 * @post Crea un objeto de tipo Temazo
 */
int Temazo::numTemazos=0;
int Temazo::puntuacionTotal=0;
Temazo::Temazo() {
  this->titulo= "";
  this->interprete= "";
  this->duracion = 0; 
  this->puntuacion = 0;
  this->nombreUltimoGarito=Garito();
  this->fecha=Fecha();
  numTemazos++;
  
}

/**
 * @brief Constructor parametrizado
 * @param titulo Título del temazo
 * @param interprete Persona o grupo que lo interpreta
 * @param duracion Duración en segundos
 * @param puntuacion Puntuación otorgada por el público
 * @post Crea un objeto de tipo Temazo
 */
Temazo::Temazo(std::string titulo, std::string interprete, int duracion, int puntuacion, string ultimoGarito, Fecha fecha) :
titulo(titulo)
, interprete(interprete)
, duracion(duracion)
, puntuacion(puntuacion) {
    this->incrementarPuntuacionTotal(puntuacion);
    this->nombreUltimoGarito = ultimoGarito;
    this->fecha= fecha;
    numTemazos++;
}

/**
 * @brief Constructor de copia de la clase
 * @param orig Objeto de tipo Temazo que se pasa para copiar sus datos
 * @post Crea un nuevo objeto por copia
 */

Temazo::Temazo(const Temazo& orig) :
titulo(orig.titulo)
, interprete(orig.interprete)
, duracion(orig.duracion)
, puntuacion(orig.puntuacion) {
}

/**
 * @brief Destructor de clase
 * @post Destruye el objeto
 */
Temazo::~Temazo() {
    numTemazos--;
    decrementarPuntuacionTotal(this->puntuacion);
}


/**
 * @brief Devuelve la puntuación del temazo
 * @post  Devuelve la puntuación del temazo
 */
int Temazo::getPuntuacion() const {
    return puntuacion;
}

/**
 * @brief Modifica la duración del Temazo
 * @param duracion Nueva duración
 * @post Modifica la duración del Temazo
 */
void Temazo::setDuracion(int duracion) {
    this->duracion = duracion;
}

/**
 * @brief Devuelve la duración del temazo
 * @post  Devuelve la duración del temazo
 */
int Temazo::getDuracion() const {
    return duracion;
}

/**
 * @brief Modifica el intérprete del Temazo
 * @param interprete Nuevo intérprete
 * @post Modifica el intérprete del Temazo
 */
void Temazo::setInterprete(std::string interprete) {
    this->interprete = interprete;
}

/**
 * @brief Devuelve el intérprete del temazo
 * @post  Devuelve el intérprete del temazo
 */
std::string Temazo::getInterprete() const {
    return interprete;
}

/**
 * @brief Modifica el título del Temazo
 * @param titulo Nuevo título
 * @post Modifica el título del Temazo
 */
void Temazo::setTitulo(std::string titulo) {
    this->titulo = titulo;
}

/**
 * @brief Devuelve el título del temazo
 * @post  Devuelve el título del temazo
 */
std::string Temazo::getTitulo() const {
    return titulo;
}

Garito Temazo::getNombreUltimoGarito(){
    return this->nombreUltimoGarito;
}

Fecha Temazo::getFecha(){
    return this->fecha;
}

void Temazo::setFecha(Fecha fecha){
    this->fecha = fecha;
}

void Temazo::setUltimoGarito(Garito ultimoGarito){
    this->nombreUltimoGarito = Garito(ultimoGarito);
}

void Temazo::incrementarPuntuacionTotal(int puntos){
    if(puntos < 0){
        ParametroNoValido parametro("Temazo.cpp","incrementarPuntuacion","puntos < 0");
        throw parametro;
    }else{
        if(puntos>10){
            ParametroNoValido parametro("Temazo.cpp","incrementarPuntuacion","puntos>10");
            throw parametro;
        }else{
            this->puntuacionTotal = this->puntuacionTotal + puntos;
        }
    }
}

void Temazo::decrementarPuntuacionTotal(int puntos){
    if(puntos < 0){
        ParametroNoValido parametro("Temazo.cpp","decrementarPuntuacionTotal","puntos < 0");
        throw parametro;
    }else{
        if(puntos <0){
            ParametroNoValido parametro("Temazo.cpp","decrementarPuntuacionTotal","puntos <0");
            throw parametro;
        }else{
            this->puntuacionTotal = this->puntuacionTotal - puntos;
        }
    }
}

bool Temazo::debeEstarEnLaLista(){
    int media;
    media = puntuacionTotal/numTemazos;
    if(this->getPuntuacion() >= media){
        return true;
    }else{
        return false;
    }
}

void Temazo::incrementarPuntuacion(int puntos){
    if((puntos>10)||(puntos<0)){
        throw ParametroNoValido("Temazo.cpp","incrementrarPuntuacion","puntos>10)||(puntos<0");
    }else{
    this->puntuacion=+puntos;
    }
}

string Temazo::toCVS(){
    string cadena;
    stringstream cadena1;
    cadena1 << this->getTitulo()<<";"<<this->getInterprete()<<";"<<this->getDuracion()<<";"<<this->getPuntuacion()<<";"<<this->getNombreUltimoGarito().toCVS()<<";"<<this->getFecha().toCVS();
    cadena = cadena1.str();
    return(cadena);
}