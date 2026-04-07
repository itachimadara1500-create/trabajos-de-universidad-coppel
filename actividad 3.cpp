#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Empleado {
private:
    string nombre, apellidoP, apellidoM;
    int dia, mes, anio;

public:
    void capturarDatos() {
        cout << "Introduce tu nombre: ";
        cin >> nombre;
        cout << "Introduce tu apellido paterno: ";
        cin >> apellidoP;
        cout << "Introduce tu apellido materno (X si no tienes): ";
        cin >> apellidoM;
        cout << "Fecha de nacimiento (solo numeros)\nDia: ";
        cin >> dia;
        cout << "Mes: ";
        cin >> mes;
        cout << "Año: ";
        cin >> anio;
    }

    string calcularRFC() {
        string rfc = "";

        // Primera letra del apellido paterno
        rfc += toupper(apellidoP[0]);

        // Primera vocal interna del apellido paterno
        string vocales = "AEIOUaeiou";
        for (size_t i = 1; i < apellidoP.size(); i++) {
            if (vocales.find(apellidoP[i]) != string::npos) {
                rfc += toupper(apellidoP[i]);
                break;
            }
        }

        // Inicial del apellido materno o X
        if (apellidoM != "X" && !apellidoM.empty())
            rfc += toupper(apellidoM[0]);
        else
            rfc += 'X';

        // Inicial del nombre
        rfc += toupper(nombre[0]);

        // Año (últimos dos dígitos)
        rfc += to_string(anio).substr(2,2);

        // Mes (dos dígitos)
        if (mes < 10) rfc += "0";
        rfc += to_string(mes);

        // Día (dos dígitos)
        if (dia < 10) rfc += "0";
        rfc += to_string(dia);

        // Validación de palabras prohibidas
        vector<string> prohibidas = {
            "BUEI","BUEY","CACA","CACO","CAGA","CAGO","CAKA","CAKO",
            "COGE","COGI","COJA","COJE","COJI","COJO","CULO","FETO",
            "GUEY","JOTO","KACA","KACO","KAGA","KAGO","KOGE","KOGI",
            "KOJA","KOJE","KOJI","KOJO","KULO","MAME","MAMO","MEAR",
            "MEAS","MEON","MION","MOCO","MULA","PEDA","PEDO","PENE",
            "PUTA","PUTO","QULO","RATA","RUIN","PITO","VACA","VAGO"
        };

        string primeras4 = rfc.substr(0,4);
        for (string p : prohibidas) {
            if (primeras4 == p) {
                rfc[3] = 'X'; // sustituir cuarta letra por X
                break;
            }
        }

        return rfc;
    }
};

int main() {
    Empleado e;
    e.capturarDatos();
    cout << "Tu RFC sin homoclave es: " << e.calcularRFC() << endl;
    return 0;
}