#include <iostream>
#include <string>
using namespace std;

struct Estudiante {
    int id;
    char nombre[30];
    char apellido[30];
    float nota1, nota2, nota3, nota4;
    float promedio;
};

int main() {
    int N;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> N;

    Estudiante* estudiantes = new Estudiante[N];

    // Captura de datos
    for (int i = 0; i < N; i++) {
        cout << "\nEstudiante #" << (i + 1) << ":\n";
        cout << "ID: ";
        cin >> estudiantes[i].id;
        
         cin.ignore();  // ?? LIMPIAR el salto de línea pendiente
        cout << "Nombre: ";
        cin.getline(estudiantes[i].nombre, 30);
        cout << "Apellido: ";
        cin.getline(estudiantes[i].apellido, 30);
        cout << "Nota 1: ";
        cin >> estudiantes[i].nota1;
        cout << "Nota 2: ";
        cin >> estudiantes[i].nota2;
        cout << "Nota 3: ";
        cin >> estudiantes[i].nota3;
        cout << "Nota 4: ";
        cin >> estudiantes[i].nota4;

        // Calcular promedio
        estudiantes[i].promedio = (estudiantes[i].nota1 + estudiantes[i].nota2 +
                                   estudiantes[i].nota3 + estudiantes[i].nota4) / 4.0;
    }

    // Mostrar resultados
    cout << "\n=== RESULTADOS ===\n";
    for (int i = 0; i < N; i++) {
        Estudiante* est = &estudiantes[i];  // puntero al estudiante actual

        cout << "\nEstudiante #" << (i + 1) << "\n";
        cout << "ID: " << est->id << "\n";
        cout << "Nombre completo: " << est->nombre << " " << est->apellido << "\n";
        cout << "Promedio: " << est->promedio << "\n";

        if (est->promedio >= 60) {
            cout << "Estado: APROBADO\n";
        } else {
            cout << "Estado: REPROBADO\n";
        }
    }

    // Liberar memoria
    delete[] estudiantes;

    return 0;
}

