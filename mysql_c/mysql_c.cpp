// mysql_c.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "estudiante.h"
using namespace std;

int main() {

    string codigo, nombres, apellidos, direccion, fecha_nacimiento;
    int telefono;
    cout << "ingrese codigo : ";
    getline(cin, codigo);
    cout << "ingrese nombres:";
    getline(cin, nombres);
    cout << "ingrese apellidos:";
    getline(cin, apellidos);
    cout << "ingrese direccion:";
    getline(cin, direccion);
    cout << "ingrese telefono:";
    cin >> telefono;
    cin.ignore();
    cout << "ingrese fecha_nacimiento:";
    cin >> fecha_nacimiento;


    estudiante c = estudiante (nombres,apellidos,direccion,telefono,fecha_nacimiento,codigo);
    c.crear();
    c.leer();
    c.actualizar();
    c.borrar();

    system("pause");
    return 0;
}


