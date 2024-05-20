
#ifndef EXAMEN_DATOS_JUEGOTORRESHANOI_H
#define EXAMEN_DATOS_JUEGOTORRESHANOI_H

#include "PilaLista.cpp"
#include "math.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>


template <class t>
class JuegoTorresHanoi {
private:
    PilaLista<t> *torre_uno;
    PilaLista<t> *torre_dos;
    PilaLista<t> *torre_tres;
    std::mutex mtx; // Mutex para proteger el acceso a las torres
public:
    JuegoTorresHanoi();
    ~JuegoTorresHanoi();
    void jugar();
    void menuSecundario();
    void opc3Principal(int clave);
    void dibujar();
    void generarNumeros();
    void moverTorre(PilaLista<t>* origen, PilaLista<t>* destino, int& contador);
    void realizarTodosLosMovimientos();
    void realizarMovimiento(PilaLista<t>* origen, PilaLista<t>* destino);
};





#endif //EXAMEN_DATOS_JUEGOTORRESHANOI_H
