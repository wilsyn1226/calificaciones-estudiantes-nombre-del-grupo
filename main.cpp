#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <windows.h>

using namespace std;

const double NOTA_APROBACION = 70.0;

void llenarDatos(vector<string>& nombres, vector<double>& notas, int cantidad) {
    cout << "\n=== REGISTRO DE ESTUDIANTES Y CALIFICACIONES ===\n";

    cin.ignore(1000, '\n');

    for (int i = 0; i < cantidad; i++) {
        cout << "\nEstudiante #" << (i + 1) << endl;
        cout << "Nombre: ";
        getline(cin, nombres[i]);

        do {
            cout << "Calificacion (0 - 100): ";
            cin >> notas[i];

            if (cin.fail() || notas[i] < 0 || notas[i] > 100) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Error: La calificacion debe estar en el rango de 0 a 100. Intente de nuevo.\n";
            }
            else {
                cin.ignore(1000, '\n');
                break;
            }
        } while (true);
    }
}

void mostrarDatos(const vector<string>& nombres, const vector<double>& notas, int cantidad) {
    cout << "\n=========================================\n";
    cout << "        LISTADO DE CALIFICACIONES        \n";
    cout << "=========================================\n";
    cout << left << setw(5) << "ID" << setw(25) << "Nombre" << setw(10) << "Nota" << endl;
    cout << "-----------------------------------------\n";

    for (int i = 0; i < cantidad; i++) {
        cout << left << setw(5) << (i + 1)
            << setw(25) << nombres[i]
            << fixed << setprecision(2) << setw(10) << notas[i] << endl;
    }
    cout << "-----------------------------------------\n";
}

double calcularPromedio(const vector<double>& notas, int cantidad) {
    double suma = 0.0;
    for (int i = 0; i < cantidad; i++) {
        suma += notas[i];
    }
    return (cantidad > 0) ? (suma / cantidad) : 0.0;
}

void buscarMaximo(const vector<string>& nombres, const vector<double>& notas, int cantidad) {
    if (cantidad == 0) return;

    int indiceMax = 0;
    for (int i = 1; i < cantidad; i++) {
        if (notas[i] > notas[indiceMax]) {
            indiceMax = i;
        }
    }

    cout << "Nota mas alta: " << nombres[indiceMax]
        << " (" << fixed << setprecision(2) << notas[indiceMax] << " pts)\n";
}

void buscarMinimo(const vector<string>& nombres, const vector<double>& notas, int cantidad) {
    if (cantidad == 0) return;

    int indiceMin = 0;
    for (int i = 1; i < cantidad; i++) {
        if (notas[i] < notas[indiceMin]) {
            indiceMin = i;
        }
    }

    cout << "Nota mas baja: " << nombres[indiceMin]
        << " (" << fixed << setprecision(2) << notas[indiceMin] << " pts)\n";
}

void mostrarAprobacion(const vector<double>& notas, int cantidad) {
    int aprobados = 0;
    int reprobados = 0;

    for (int i = 0; i < cantidad; i++) {
        if (notas[i] >= NOTA_APROBACION) {
            aprobados++;
        }
        else {
            reprobados++;
        }
    }

    cout << "Estudiantes aprobados (>= " << NOTA_APROBACION << " pts): " << aprobados << endl;
    cout << "Estudiantes reprobados (< " << NOTA_APROBACION << " pts): " << reprobados << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int cantidadEstudiantes;

    cout << "===============================================\n";
    cout << "  SISTEMA DE CALIFICACIONES - CALCULO DIFERENCIAL\n";
    cout << "===============================================\n";

    do {
        cout << "¿Cuantos estudiantes desea registrar?: ";
        cin >> cantidadEstudiantes;

        if (cin.fail() || cantidadEstudiantes <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Ingrese un numero entero mayor a 0.\n";
        }
        else {
            break;
        }
    } while (true);

    vector<string> nombres(cantidadEstudiantes);
    vector<double> notas(cantidadEstudiantes);

    llenarDatos(nombres, notas, cantidadEstudiantes);
    mostrarDatos(nombres, notas, cantidadEstudiantes);

    cout << "\n=== ESTADISTICAS DEL GRUPO ===\n";
    double promedio = calcularPromedio(notas, cantidadEstudiantes);
    cout << "Promedio general del grupo: " << fixed << setprecision(2) << promedio << " pts\n";

    buscarMaximo(nombres, notas, cantidadEstudiantes);
    buscarMinimo(nombres, notas, cantidadEstudiantes);
    mostrarAprobacion(notas, cantidadEstudiantes);

    return 0;
}
