#include <iostream>
#include <string>
using namespace std;

int main() {
    int edad;
    string nombre;

    // Solicitar nombre
    cout << "Ingrese su nombre: ";
    cin >> nombre;

    // Solicitar edad
    cout << "Ingrese su edad: ";
    cin >> edad;

    // Condición para determinar si es mayor o menor de edad
    if (edad >= 18) {
        cout << "Bienvenido " << nombre << ", eres mayor de edad." << endl;
    } else {
        cout << "Bienvenido " << nombre << ", eres menor de edad." << endl;
    }

    return 0;
}