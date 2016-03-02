/**
 * @file Temazo.h
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @desc Clase Temazo para las prácticas de POO
 * @date 12 de octubre de 2015, 17:08
 */

#include <string>
#include "ParametroNoValido.h"
#include "Fecha.h"
#ifndef TEMAZO_H
#define	TEMAZO_H

/**
 @brief Clase que guarda los datos de un temazo
 */
class Temazo {
public:
    Temazo();
    Temazo(std::string titulo, std::string interprete, int duracion, int puntuacion,string ultimoGarito, Fecha fecha);
    Temazo(const Temazo& orig);
    virtual ~Temazo();
    int getPuntuacion() const;
    void setDuracion(int duracion);
    int getDuracion() const;
    void setInterprete(std::string interprete);
    std::string getInterprete() const;
    void setTitulo(std::string titulo);
    std::string getTitulo() const;
    Fecha getFecha();
    string getNombreUltimoGarito();
    void setFecha(Fecha fecha);
    void setUltimoGarito(string ultimoGarito);
    void incrementarPuntuacionTotal(int puntos);
    void decrementarPuntuacionTotal(int puntos);
    bool debeEstarEnLaLista();
    void incrementarPuntuacion(int puntos);
private:
    std::string titulo; ///< Título de la canción
    std::string interprete; ///< Intérprete
    int duracion; ///< Duración en segundos
    int puntuacion; ///< Puntuación en función de cómo la acoge el público
    static int numTemazos;
    static int puntuacionTotal;
    string nombreUltimoGarito;
    Fecha fecha;
    
    
};

#endif	/* TEMAZO_H */

