#include "stdlib.h"
#include "iostream"
#include "time.h"
using namespace std;

int main(){

    int Secret;
    
    //Inicializando un termino random
    srand (time(NULL));
    Secret = rand() % 100 + 1;

    int x, intentos = 1;

    cout << "\nJuega a adivinar un numero entre 1 y 100\nTendras 5 intentos para adivinar\nPresiona 0 para salir\n\n";
    cout << "Digita un numero entre 1 y 100: ";
      
    do{

        cin >> x;
        //Para el caso especifico que ingrese 0 se muestra el mensaje y sale del while y el programa
        if (x == 0){
            cout << "\nGracias por tu tiempo!" << endl;
        }else{
            //Si el usuario adivina se muestra el mensaje y sale del while y del programa
            if(x == Secret){
                cout << "\nGanaste!!! Tu numero de intentos fue: " << intentos << endl;
            }else{
                cout << "\nEl numero ingresado es incorrecto\n";

                //Esta condicion aplica cuando sea mayor o menor al numero pero no en el ultimo intento
                if (Secret > x && intentos != 5){
                    cout << "El numero es mayor al ingresado\n";
                    cout << "\nIngresa otro numero: ";

                }else{
                    if (Secret < x && intentos != 5){
                    cout << "El numero es menor al ingresado\n";
                    cout << "\nIngresa otro numero: ";
                    }               
                }
            }
        } 
        intentos++;

    }while(x != Secret && intentos <= 5 && x != 0);

    //En el caso de que el usuario agote sus opciones se muestra este mensaje
    //Tambien pudimos colocar intentos = 6 como condicion
    if (x != Secret && x != 0){
        cout << "\nYa no tienes mas intentos. Mejor suerte a la proxima!\n";
    }

    return 0;
}
