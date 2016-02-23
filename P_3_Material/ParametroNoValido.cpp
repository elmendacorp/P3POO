/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParametroNoValido.cpp
 * Author: Fran
 * 
 * Created on 23 de febrero de 2016, 22:09
 */

#include "ParametroNoValido.h"

ParametroNoValido::ParametroNoValido(string fichero, string funcion, string descripcion) {
}

ParametroNoValido::ParametroNoValido(const ParametroNoValido& orig) {
}

ParametroNoValido::~ParametroNoValido() {
}

string ParametroNoValido::QueOcurre(){
    string resumen;
    resumen = this->fichero + this->funcion + this->descripcion;
    return resumen;
}