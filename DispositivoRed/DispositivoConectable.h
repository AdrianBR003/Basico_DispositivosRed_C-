//
// Created by benro on 24/03/2024.
//

// Dipositivo Conenctable van a ser aquellos que tenga una dirección IP o MAC,
// indepnedientemente de su rol en la infraestructura


#ifndef DISPOSITIVORED_DISPOSITIVOCONECTABLE_H
#define DISPOSITIVORED_DISPOSITIVOCONECTABLE_H
#include <iostream>
#include <string>
#include <sstream>

class DispositivoConectable{
protected:
    std::string IP;
    std::string MAC;

public:

    // Constructores

    DispositivoConectable(std::string IP, std::string MAC){
        this->IP = IP;
        this->MAC = MAC;
    }

    bool comprobarIPcon(DispositivoConectable dis,int parte){
        std::string IP1 = extraer(this->IP,parte);
        std::string IP2 = extraer(dis.IP,parte);
        if(std::equal(IP1.begin(), IP1.end(),IP2.begin(),IP2.end())){
            return true;
        }else{
            return false;
        }
    }

    std::string extraer(std::string IP, int parte){ // Vamos a extraerlo dividiendo la cadena por puntos y luego extrañedo el componente necesario
        std::stringstream ss(IP); // El objeto ss se crea para dividir la cadena 'IP'
        std::string componente; // En esta varibale guardaremos el componente
        int cont=0; // El contador nos determinará la parte

        while(std::getline(ss,componente,'.')){ // El primer componente es el método al que apunta el while, el segundo donde se guardará y el tercero la condición de corte
            cont++;
            if(cont == parte){ // Cuando el contador llegue a la parte, que lo guarde
                break; // Para no coger más la parte.
            }
        }
        return componente;
    }

    // GETTER AND SETTER

    const std::string &getIp() const {
        return this->IP;
    }

    void setIp(const std::string &ip) {
        this->IP = ip;
    }

    const std::string &getMac() const {
        this->MAC;
    }

    void setMac(const std::string &mac) {
        this->MAC = mac;
    }
};
#endif //DISPOSITIVORED_DISPOSITIVOCONECTABLE_H
