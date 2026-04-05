#include <iostream>
using namespace std;

int main() {
    int edad;
    string nombre;

    cout << "Ingrese su nombre: ";
    cin >> nombre;

    cout << "Ingrese su edad: ";
    cin >> edad;

    if (edad >= 18) {
        cout << "Bienvenido " << nombre << ", eres mayor de edad." << endl;
    } else {
        cout << "Bienvenido " << nombre << ", eres menor de edad." << endl;
    }

    return 0;
}