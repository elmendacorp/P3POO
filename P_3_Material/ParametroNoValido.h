/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParametroNoValido.h
 * Author: Fran
 *
 * Created on 23 de febrero de 2016, 22:09
 */

#ifndef PARAMETRONOVALIDO_H
#define PARAMETRONOVALIDO_H

#include <string>
using namespace std;

class ParametroNoValido {
public:
    ParametroNoValido(string fichero, string funcion, string descripcion);
    ParametroNoValido(const ParametroNoValido& orig);
    virtual ~ParametroNoValido();
    string QueOcurre();
private:
    string fichero, funcion, descripcion;

};

#endif /* PARAMETRONOVALIDO_H */

