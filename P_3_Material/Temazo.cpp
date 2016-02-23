/** 
 * @brief Implementación de los métodos de la clase Temazo
 * @file Temazo.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 12 de octubre de 2015, 17:08
 */
#include "Temazo.h"
#include "ParametroNoValido.h"
/**
 * @brief Constructor por defecto de la clase
 * @post Crea un objeto de tipo Temazo
 */
Temazo::Temazo() {
  this->titulo= "";
  this->interprete= "";
  this->duracion = 0; 
  this->puntuacion = 0;
  this->numTemazos = 0;
  this->puntuacionTotal = 0;

}

/**
 * @brief Constructor parametrizado
 * @param titulo Título del temazo
 * @param interprete Persona o grupo que lo interpreta
 * @param duracion Duración en segundos
 * @param puntuacion Puntuación otorgada por el público
 * @post Crea un objeto de tipo Temazo
 */
Temazo::Temazo(std::string titulo, std::string interprete, int duracion, int puntuacion) :
titulo(titulo)
, interprete(interprete)
, duracion(duracion)
, puntuacion(puntuacion) {
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

void Temazo::incrementarPuntuacion(int puntos){
    if(puntos < 0){
        ParametroNoValido parametro("Temazo.cpp","incrementarPuntuacion","puntos < 0");
        throw parametro.QueOcurre();
    }else{
        if(puntos+this->puntuacionTotal >10){
            ParametroNoValido parametro("Temazo.cpp","incrementarPuntuacion","puntos+this->puntuacionTotal >10");
            throw parametro.QueOcurre();
        }else{
            this->puntuacionTotal = this->puntuacionTotal + puntos;
        }
    }
}

void Temazo::decrementarPuntuacionTotal(int puntos){
    if(puntos < 0){
        ParametroNoValido parametro("Temazo.cpp","decrementarPuntuacionTotal","puntos < 0");
        throw parametro.QueOcurre();
    }else{
        if(this->puntuacionTotal-puntos <0){
            ParametroNoValido parametro("Temazo.cpp","decrementarPuntuacionTotal","puntuacionTotal-puntos <0");
            throw parametro.QueOcurre();
        }else{
            this->puntuacionTotal = this->puntuacionTotal - puntos;
        }
    }
}