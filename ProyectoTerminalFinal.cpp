#include <iostream>
//#include <stdlib.h>     // 
#include <cstring>      // permitira la conversion de cadenas en c de forma nativa
#include <sys/wait.h>   //nos va a permitir usar la  funcion wait

using namespace std;
/*
    El interprete recibira un comando por linea y lo enviara a un hilo en segundo plano
    Los hilos principales recibiran comandos de interfaz de ayuda al usuario
    Recibira comandos basicos para manejar procesos o recibir comandos del Sistema operativo
*/

int main(int argc, char **argv){
    // Parse command line arguments: 
    char *oper = new char();
    cout << "[ Shell BIENVENIDO ]\n" << endl;
    cout << "\t Consultar Ayuda -- help for more information\n\n";
    while (!(strcmp(oper, "SALIR") == 0 || strcmp(oper, "EXIT") == 0))
    {
        cout << "Shell@$ ";
        cin >> oper;
        if (strcmp(oper, "TERMINAL") == 0)
        {
            cout << oper << endl;
        }
        else
        {
            if (!(strcmp(oper, "SALIR") == 0 || strcmp(oper, "EXIT") == 0))
            {
                cout << oper << ": Orden no encontrada\n" << endl;
            }
            /* no hacer nada */
        }
        
    }
    delete oper;
    return 0;
}