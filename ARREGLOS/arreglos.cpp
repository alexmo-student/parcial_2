#include <iostream>
using namespace std;

int main() {
    int N;

    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> N;

    // Declaración de arreglos
    int id[N];
    string nombres[N];
    string apellidos[N];
    float nota1[N], nota2[N], nota3[N], nota4[N], promedio[N];

    // Entrada de datos
    for (int i = 0; i < N; i++) {
        cout << "\nEstudiante #" << (i + 1) << ":\n";
        cout << "ID: ";
        cin >> id[i];
        cout << "Nombre: ";
        cin >> nombres[i];
        cout << "Apellido: ";
        cin >> apellidos[i];
        cout << "Nota 1: ";
        cin >> nota1[i];
        cout << "Nota 2: ";
        cin >> nota2[i];
        cout << "Nota 3: ";
        cin >> nota3[i];
        cout << "Nota 4: ";
        cin >> nota4[i];

        // Calcular promedio
        promedio[i] = (nota1[i] + nota2[i] + nota3[i] + nota4[i]) / 4.0;
    }

    // Mostrar resultados
    cout << "\n=== RESULTADOS ===\n";
    for (int i = 0; i < N; i++) {
        cout << "\nEstudiante #" << (i + 1) << "\n";
        cout << "ID: " << id[i] << "\n";
        cout << "Nombre completo: " << nombres[i] << " " << apellidos[i] << "\n";
        cout << "Promedio: " << promedio[i] << "\n";

        if (promedio[i] >= 60) {
            cout << "Estado: APROBADO\n";
        } else {
            cout << "Estado: REPROBADO\n";
        }
    }

    return 0;
}

