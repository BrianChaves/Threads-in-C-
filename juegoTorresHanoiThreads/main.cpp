#include <iostream>
#include <thread>
#include "JuegoTorresHanoi.cpp"
int main() {
    try{
        JuegoTorresHanoi<int> juego;
        juego.jugar();
    }catch (RuntimeException e){
        cout<<"Error: "<<e.getMessage()<< '\n';
    }
    return 0;
}
