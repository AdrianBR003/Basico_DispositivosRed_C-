#include <iostream>
#include <string>
#include <list>
#include "DispositivoRed.h"
#include "DispositivoConectable.h"

int main() {

    DispositivoRed router1("Router1","192.168.0.1");
    DispositivoRed router2("Router1","192.168.0.13");
    DispositivoConectable dis1("192.168.5.1","0");
    DispositivoConectable dis2("192.168.5.3","0");

    bool comp = dis1.comprobarIPcon(dis2,3);
    std::cout << comp; // 1 = true






    return 0;
}
