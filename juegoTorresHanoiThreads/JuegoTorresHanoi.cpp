
#include "JuegoTorresHanoi.h"
#include <chrono>
template<class t>
JuegoTorresHanoi<t>::~JuegoTorresHanoi() {
    delete torre_uno;
    delete torre_dos;
    delete torre_tres;
}

template<class t>
JuegoTorresHanoi<t>::JuegoTorresHanoi() {
    torre_uno = new PilaLista<t>;
    torre_dos = new PilaLista<t>;
    torre_tres = new PilaLista<t>;
}

template<class t>
void JuegoTorresHanoi<t>::jugar() {
    int opcion = 1;
    int clave = 0;
    do {
        std::cout << "-----------------Menu Principal------------------------" << std::endl;
        std::cout << "( 1 )  Ingresar al Juego" << std::endl;
        std::cout << "( 2 )  Mostrar el minimo numero de movimientos para ganar" << std::endl;
        std::cout << "( 3 )  Mostrar el algoritmo completo paso a paso de la solucion" << std::endl;
        cout << "( 4 )  Realizar todos los movimientos y medir el tiempo total" << endl; // New option
        std::cout << "( 0 )  Salir  " << std::endl << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << "Digite una opcion del menu:  ";
        std::cin >> opcion;
        switch (opcion){
            case 1 :
                std::cout << std::endl;
                menuSecundario();
                break;
            case 2 :
                std::cout << "MOVIMIENTOS MINIMOS PARA GANAR: 15"<< std::endl;
                break;
            case 3 :
                std::cout << "Digite clave: ";
                std::cin >> clave;
                opc3Principal(clave);
                break;
            case 4:
                realizarTodosLosMovimientos(); // Perform all moves
                break;

            default:
                std::cout << "Opcion incorrecta"<< std::endl;
                break;
        }
    } while ( opcion != 0);
}

template<class t>
void JuegoTorresHanoi<t>::realizarTodosLosMovimientos() {
    generarNumeros();
    int contador = 0;
    auto start = std::chrono::steady_clock::now();

    auto realizarMovimientosEnRango = [&](int inicio, int fin) {
        for (int i = inicio; i <= fin; ++i) {
            cout << "Movimiento " << i << ":" << endl;
            switch (i) {
                case 1:
                    realizarMovimiento(torre_uno, torre_dos);
                    break;
                case 2:
                    realizarMovimiento(torre_uno, torre_tres);
                    break;
                case 3:
                    realizarMovimiento(torre_dos, torre_tres);
                    break;
                case 4:
                    realizarMovimiento(torre_uno, torre_dos);
                    break;
                case 5:
                    realizarMovimiento(torre_tres, torre_uno);
                    break;
                case 6:
                    realizarMovimiento(torre_tres, torre_dos);
                    break;
                case 7:
                    realizarMovimiento(torre_uno, torre_dos);
                    break;
                case 8:
                    realizarMovimiento(torre_uno, torre_tres);
                    break;
                case 9:
                    realizarMovimiento(torre_dos, torre_tres);
                    break;
                case 10:
                    realizarMovimiento(torre_dos, torre_uno);
                    break;
                case 11:
                    realizarMovimiento(torre_tres, torre_uno);
                    break;
                case 12:
                    realizarMovimiento(torre_dos, torre_tres);
                    break;
                case 13:
                    realizarMovimiento(torre_uno, torre_dos);
                    break;
                case 14:
                    realizarMovimiento(torre_uno, torre_tres);
                    break;
                case 15:
                    realizarMovimiento(torre_dos, torre_tres);
                    break;
            }
            contador++;
            dibujar();
        }
    };

    // Inicia los hilos en orden y espera a que cada uno termine antes de iniciar el siguiente
    std::thread hilo_uno(realizarMovimientosEnRango, 1, 5);
    hilo_uno.join();
    std::thread hilo_dos(realizarMovimientosEnRango, 6, 10);
    hilo_dos.join();
    std::thread hilo_tres(realizarMovimientosEnRango, 11, 15);
    hilo_tres.join();

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    cout << "Total de movimientos realizados: " << contador << endl;
    std::cout << "Tiempo total: " << elapsed_seconds.count() << "s\n";
}

template<class t>
void JuegoTorresHanoi<t>::realizarMovimiento(PilaLista<t>* origen, PilaLista<t>* destino) {
    lock_guard<mutex> lock(mtx);  // Bloquear el mutex durante la operación de movimiento
    if (!origen->empty()) {
        destino->push(origen->top());
        origen->pop();
    } else {
        cout << "No se puede realizar el movimiento" << endl;
    }
}




template<class t>
void JuegoTorresHanoi<t>::menuSecundario() {
    generarNumeros();
    int opc = 1;
    int contador = 0;
    do {
        dibujar();
        std::cout << "CANTIDAD DE MOVIMIENTOS REALIZADOS: "<< contador << std::endl;
        std::cout << "-----------------Menu Juego------------------------" << std::endl;
        std::cout << "( 1 )  De la pila 1 a la pila 2 " << std::endl;
        std::cout << "( 2 )  De la pila 1 a la pila 3 " << std::endl;
        std::cout << "( 3 )  De la pila 2 a la pila 1 " << std::endl;
        std::cout << "( 4 )  De la pila 2 a la pila 3 " << std::endl;
        std::cout << "( 5 )  De la pila 3 a la pila 1 " << std::endl;
        std::cout << "( 6 )  De la pila 3 a la pila 2 " << std::endl;
        std::cout << "( 7 )  Reiniciar el juego  "  << std::endl;
        std::cout << "( 0 )  Salir  "  << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << "Digite una opcion del menu:  ";
        std::cin >> opc;
        std::cout << std::endl;
        switch (opc){
            case 0:
                exit(0);
            case 1 :
                // Crea un hilo que ejecuta el método moverTorre de la clase JuegoTorresHanoi.
                // Pasamos las pilas torre_uno y torre_dos como argumentos, junto con una referencia al contador.
                // Esto permite que el hilo mueva una ficha de la torre_uno a la torre_dos de manera asíncrona.
                std::thread(&JuegoTorresHanoi::moverTorre, this, torre_uno, torre_dos, std::ref(contador)).detach();
                break;
            case 2 :
                std::thread(&JuegoTorresHanoi::moverTorre, this, torre_uno, torre_tres, std::ref(contador)).detach();
                break;
            case 3 :
                std::thread(&JuegoTorresHanoi::moverTorre, this, torre_dos, torre_uno, std::ref(contador)).detach();
                break;
            case 4 :
                std::thread(&JuegoTorresHanoi::moverTorre, this, torre_dos, torre_tres, std::ref(contador)).detach();
                break;
            case 5 :
                std::thread(&JuegoTorresHanoi::moverTorre, this, torre_tres, torre_uno, std::ref(contador)).detach();
                break;
            case 6 :
                std::thread(&JuegoTorresHanoi::moverTorre, this, torre_tres, torre_dos, std::ref(contador)).detach();
                break;
            case 7 :
                for(int i = 0; i <4; i++){
                    if(!torre_uno->empty()){
                        torre_uno->pop();
                    }
                    if(!torre_dos->empty()){
                        torre_dos->pop();
                    }
                    if(!torre_tres->empty()) {
                        torre_tres->pop();
                    }
                }
                menuSecundario();
                break;
            default:
                std::cout << "Opcion incorrecta"<< std::endl;
                break;
        }
    } while ( opc != 0);
}

template<class t>
void JuegoTorresHanoi<t>::opc3Principal(int clave) {
    if(clave == 123){
        std::cout <<" 1)   De la Pila 1 a la Pila 2\n"
                    "  2)   De la Pila 1 a la Pila 3\n"
                    "  3)   De la Pila 2 a la Pila 3\n"
                    "  4)   De la Pila 1 a la Pila 2\n"
                    "  5)   De la Pila 3 a la Pila 1\n"
                    "  6)   De la Pila 3 a la Pila 2\n"
                    "  7)   De la Pila 1 a la Pila 2\n"
                    "  8)   De la Pila 1 a la Pila 3\n"
                    "  9)   De la Pila 2 a la Pila 3\n"
                    "  10)  De la Pila 2 a la Pila 1\n"
                    "  11)  De la Pila 3 a la Pila 1\n"
                    "  12)  De la Pila 2 a la Pila 3\n"
                    "  13)  De la Pila 1 a la Pila 2\n"
                    "  14)  De la Pila 1 a la Pila 3\n"
                    "  15)  De la Pila 2 a la Pila 3\n";
    } else {
        std::cout <<" CLAVE INCORRECTA"<<std::endl;
    }
}

template<class t>
void JuegoTorresHanoi<t>::dibujar(){
    std::cout << "\n====================================" << std::endl;
    std::cout<< "                       ||"<<std::endl;
    torre_uno->imprimir();
    std::cout<< "||Torre 1"<<std::endl;
    std::cout<< "                       ||";std::cout << std::endl; std::cout <<std::endl;

    std::cout<< "                       ||"<<std::endl;
    torre_dos->imprimir();
    std::cout<< "||Torre 2"<<std::endl;
    std::cout<< "                       ||";std::cout << std::endl; std::cout <<std::endl;

    std::cout<< "                       ||"<<std::endl;
    torre_tres->imprimir();
    std::cout<< "||Torre 3"<<std::endl;
    std::cout<< "                       ||";std::cout << std::endl; std::cout <<std::endl;
    std::cout << "\n====================================" << std::endl;
}

template<class t>
void JuegoTorresHanoi<t>::generarNumeros(){
    for(int h = 3 ; h >= 0; h--){
        torre_uno->push(new int((h + 4)* pow((h + 9),h+1)));
    }
}

template<class t>
void JuegoTorresHanoi<t>::moverTorre(PilaLista<t>* origen, PilaLista<t>* destino, int& contador) {
    std::lock_guard<std::mutex> lock(mtx); // Bloquear el mutex para evitar condiciones de carrera
    auto start = std::chrono::steady_clock::now(); // Inicio del temporizador
    if (!origen->empty()) {
        destino->push(origen->top());
        origen->pop();
        contador++;
    } else {
        contador++;
        std::cout << "No se puede realizar el movimiento" << std::endl;
    }
    auto end = std::chrono::steady_clock::now(); // Fin del temporizador
    std::chrono::duration<double> elapsed_seconds = end - start; // Tiempo transcurrido
    std::cout << "Tiempo de iteración: " << elapsed_seconds.count() << "s\n"; // Imprimir el tiempo transcurrido
}

