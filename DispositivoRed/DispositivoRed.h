//
// Created by benro on 24/03/2024.
//

// Dispositivos que realizan funciones en la infraestructura, tales como los routers y los switch


#ifndef BASICO_DISPOSITIVOSRED_C_DISPOSITIVORED_H
#define BASICO_DISPOSITIVOSRED_C_DISPOSITIVORED_H
#include <iostream>
#include <string>
#include <list>


class DispositivoRed{
protected:
    std::string nombreD;
    bool estado;
    std::list<std::string> interfaces;
    std::string interfazE;

public:

    // COnstructor

    DispositivoRed(std::string nombreD,std::string InterfazP){
        this->estado = false;
        this->nombreD = nombreD;
        interfaces.push_front(InterfazP);
        this->interfazE = InterfazP; // La interfaz añadida sea la elegida por defecto
    }

    void encender(){
        this->estado=true;
    }
    void apagado(){
        this->estado=false;
    }

    void cambiarInterfaz(){
        if(!this->interfaces.empty()){ // Comprobación para poder cambiar a otra interfaz
            int cont=0;
            int ele;
            for(const std::string& i : interfaces){
                std::cout << "[" << cont <<"]  " << i << std::endl;
                cont++;
            }
            std::cin >> ele; // Guardamos la eleccion
            auto it = interfaces.begin();
            std::advance(it,ele);
            this->interfazE = *it; // Guardamos de manera segura todos los datos del elemento

        }else{
            throw std::runtime_error("No hay más interfaces para cambiar");
        }
    }

    // Metodos LIST

    void addInterfaz(const std::string& nInterfaz){
        this->interfaces.push_front(nInterfaz);
    }

    void delInterfaz(const std::string& nInterfaz){
        this->interfaces.remove(nInterfaz);
    }



    // GETTER AND SETTER:

    const std::string &getNombreD() const {
        return nombreD;
    }

    void setNombreD(const std::string &nombreD) {
        DispositivoRed::nombreD = nombreD;
    }

    bool isEstado() const {
        return estado;
    }

    void setEstado(bool estado) {
        DispositivoRed::estado = estado;
    }
};


#endif //BASICO_DISPOSITIVOSRED_C_DISPOSITIVORED_H
