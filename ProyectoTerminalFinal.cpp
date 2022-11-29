#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

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