#include <iostream>
using namespace std;

int main() {
    double num1, num2;

    cout << "Escribe el primer numero: ";
    cin >> num1;

    cout << "Escribe el segundo numero: ";
    cin >> num2;

    cout << "La suma es: " << num1 + num2 << endl;
    cout << "La resta es: " << num1 - num2 << endl;
    cout << "La multiplicacion es: " << num1 * num2 << endl;

    if (num2 != 0) {
        cout << "La division es: " << num1 / num2 << endl;
    } else {
        cout << "No se puede dividir entre cero." << endl;
    }

    return 0;
}