/**
 * @file Garito.h
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @desc Clase Garito para las prácticas de POO
 * @date 12 de octubre de 2015, 17:08
 */


#include <string>

using namespace std;

#ifndef GARITO_H
#define	GARITO_H
/**
 * @brief Clase para almacenar los datos de un local en el que actúa el DJ  
 */
class Garito {
public:
    Garito(std::string nombre="", std::string direccion="");
    Garito(const Garito& orig);
    virtual ~Garito();
    void setDireccion(std::string direccion);
    std::string getDireccion() const;
    void setNombre(std::string nombre);
    std::string getNombre() const;
    string toCVS();
private:
    std::string nombre; ///< Nombre del local
    std::string direccion; ///< Dirección del local
};

#endif	/* GARITO_H */

