/** 
 * @brief Fichero principal de la práctica 2 de POO
 * @file main.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 12 de octubre de 2015, 17:08
 */

#include <iostream>
#include <cstdlib>

#include "Temazo.h"
#include "Garito.h"
#include "Fecha.h"
#include "djutils.h"
#include "ParametroNoValido.h"
#include<fstream>

using namespace std;

/**
 * @brief Función principal
 * @argc Número de argumentos pasados por línea de órdenes
 * @argc Caractares pasados como argumentos por línea de órdenes
 * @return 0 si todo funciona bien; distinto de 0 en otro caso.
 */
int main(int argc, char** argv) {
    try{

    cout << "POO: Práctica 3 resuelta" << endl;
    // 2 temazos: uno usando el constructor por defecto y otro usando el parametrizado
    Temazo temas[20];
    Garito * pMiCasa= new Garito();
        
    // 2 garitos: uno usando el constructor parametrizado y otro  usando el constructor de copia
    Garito * garitos=new Garito[10];
    garitos[0]=Garito("Bar Felipe Sanchez", "C/ Besugo nº 4, 72123, Alcornarejo");
    garitos[1]=garitos[0];

    *pMiCasa= garitos[0];
    
    temas[0]=Temazo("Vaya torito", "El Fari", 194, 0,pMiCasa->getDireccion(),Fecha(24,5,2014));
    temas[1]=Temazo("entradaTriunfal","El Fari", 195,0,garitos[0].getDireccion(),Fecha(6,6,2015));
    temas[2]=temas[1];
    // 2 fechas: una usando el constructor por defecto y otra el constructor parametrizado.
    Fecha fecha1;
    Fecha fecha2(12, 10, 2016);
    
    
    djutils::mostrarTemazo(temas[2]);
    for(int i=0;i<10;i++){
        djutils::mostrarGarito(garitos[i]);
    }
    for(int i=0;i<3;i++){
        djutils::mostrarTemazo(temas[i]);
    }
    for(int i=0;i<3;i++){
        temas[i].incrementarPuntuacion((i+1));
    }
    for(int i=0;i<3;i++){
        if(temas[i].debeEstarEnLaLista()){
            djutils::mostrarTemazo(temas[i]);
            cout << "debe estar en lista." <<endl;
        }
    }
    Temazo tema1("Vaya torito", "El Fari", 194, 0,"aldeavieja",Fecha(24,5,2014)),tema2("Vaya torito", "El Fari2", 194, 0,"aldeavieja",Fecha(24,5,2014));
    Garito garito1("Bar Felipe Sanchez1", "C/ Besugo nº 4, 72123, Alcornarejo"),garito2("Bar Felipe Sanchez2", "C/ Besugo nº 4, 72123, Alcornarejo"),garito3("Bar Felipe Sanchez3", "C/ Besugo nº 4, 72123, Alcornarejo");
    Fecha fecha11(12, 10, 2016),fecha21(13, 10, 2016),fecha3(14, 10, 2016),fecha4(15, 10, 2016);
    
    ofstream f;
    string archivo = "temazos.txt";
    f.open(archivo.c_str());
    if(f.good()){
        f <<"comienzo de datos"<<endl;
        f << tema1.toCVS()<<endl;
        f << tema2.toCVS()<<endl;
        f << garito1.toCVS()<<endl;
        f << garito2.toCVS()<<endl;
        f << fecha11.toCVS()<<endl;
        f << fecha21.toCVS()<<endl;
        f << fecha3.toCVS()<<endl;
        f << fecha4.toCVS()<<endl;
        f.close();
        
    }else{
        cout << "error al abrir";
    }
    
    /*

            6. (Opcional) Crear un menú que permita al usuario decidir si quiere : a) mostrar los datos de los Temazos;
    b) mostrar los datos de los garitos;
    c) mostrar los datos de las fechas;
    d) modificar los datos del segundo garito;
    e) terminar el programa.
     */

    cout << endl << endl 
            << "En segundo lugar mostramos datos USANDO un menú." 
            << endl << endl;
    int opcion = 0;
    do {
        cout << "Indique la opción que desea ejecutar: " << endl;
        cout << " [1] Mostrar datos de temazos " << endl;
        cout << " [2] Mostrar datos de garitos " << endl;
        cout << " [3] Mostrar datos de fechas " << endl;
        cout << " [4] Modificar los datos del garito x" << endl;
        cout << endl;
        cout << " [0] Salir del programa" << endl;
        cin >> opcion;
        cin.ignore(1);

        switch (opcion) {
            case 0:
            {
                cout << "Saliendo de la aplicación" << endl;
                break;
            }
            case 1:
            {
               
                break;
            }
            case 2:
            {
                
                break;
            }
            case 3:
            {
                djutils::mostrarFecha(fecha1);
                djutils::mostrarFecha(fecha2);
                break;
            }
            case 4:
            {
                int x;
                cout<< "garito: ";
                cin >> x;
                djutils::pedirGarito(garitos[x]);
                break;
            }
            default:
            {
                cout << "La opción pulsada: " << opcion << " NO es válida" << endl;
            }

        }
        if (opcion >= 1 && opcion <= 4) {
            string tmp;
            cout << "Pulse enter para continuar..." << endl;
            getline(cin, tmp);
        }
    } while (opcion != 0);

    return 0;
    }catch (ParametroNoValido &parametro){
        cout << "excepcion en: " << parametro.QueOcurre() << endl;
    }

    }

