#include <iostream>
#include <stdlib.h>
#include <ctring.h>

using namespace std;

int main(int argc, char **argv){
    // Parse command line arguments: 
    char *oper = new char();
    cout << "[ Shell BIENVENIDO ]\n" << endl;
    cout << "\t Consultar Ayuda -- help for more information\n\n";
    while (oper != "SALIR" || oper != "EXIT")
    {
        cout << "Shell@$ ";
        cin >> oper;
        if (strcmp(oper, "TERMINAL"))
        {
            cout << oper << endl;
        }
        else {
            cout << oper << ": Orden no encontrada\n" << endl;
        }
        
    }
}