#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Estudiante {
    int id;
    char nombre[30];
    char apellido[30];
    float nota1, nota2, nota3, nota4;
    float promedio;
    char resultado[10];
};

// es para calcular promedio y estado
void calcularPromedio(Estudiante &est) {
    est.promedio = (est.nota1 + est.nota2 + est.nota3 + est.nota4) / 4.0;
    if (est.promedio >= 60)
        strcpy(est.resultado, "APROBADO");
    else
        strcpy(est.resultado, "REPROBADO");
}

// para agregar un nuveo estudiante 
void crearEstudiante() {
    ofstream archivo("notas.dat", ios::binary | ios::app);
    Estudiante est;

    cout << "ID: "; cin >> est.id;
    cin.ignore();
    cout << "Nombre: ";cin.getline(est.nombre, 30);
    cout << "Apellido: "; cin.getline(est.apellido, 30);
    cout << "Nota 1: "; cin >> est.nota1;
    cout << "Nota 2: "; cin >> est.nota2;
    cout << "Nota 3: "; cin >> est.nota3;
    cout << "Nota 4: "; cin >> est.nota4;

    calcularPromedio(est);
    archivo.write(reinterpret_cast<char*>(&est), sizeof(Estudiante));
    archivo.close();
    cout << "\n? Estudiante agregado con Exito.\n";
}

// Mostrar todos los estudiantes agregados 
void mostrarEstudiantes() {
    ifstream archivo("notas.dat", ios::binary);
    Estudiante est;
    int i = 0;

    cout << "=== LISTA DE ESTUDIANTES ===\n";

    while (archivo.read(reinterpret_cast<char*>(&est), sizeof(Estudiante))) {
        cout << "\nEstudiante #" << ++i << endl;
        cout << "ID: " << est.id << "\nNombre: " << est.nombre << "\nApellido: " << est.apellido;
        cout << "\nNotas: " << est.nota1 << ", " << est.nota2 << ", " << est.nota3 << ", " << est.nota4;
        cout << "\nPromedio: " << est.promedio << "\nResultado: " << est.resultado << endl;
    }

    if (i == 0) {
        cout << "\n?? No hay estudiantes registrados.\n";
    }

    archivo.close();
}

// Actualizar datos del estudiante  por ID
void actualizarEstudiante() {
    fstream archivo("notas.dat", ios::binary | ios::in | ios::out);
    Estudiante est;
    int idBuscar;
    bool encontrado = false;

    cout << "Ingrese el ID del estudiante a actualizar: ";
    cin >> idBuscar;

    while (archivo.read(reinterpret_cast<char*>(&est), sizeof(Estudiante))) {
        if (est.id == idBuscar) {
        	cin.ignore(); // Limpia el buffer de entrada
            cout << "\n--- Ingrese nuevos datos ---\n";
            cout << "Nombre: ";cin.getline(est.nombre, 30);
            cout << "Apellido: "; cin.getline(est.apellido, 30);
            cout << "Nota 1: "; cin >> est.nota1;
            cout << "Nota 2: "; cin >> est.nota2;
            cout << "Nota 3: "; cin >> est.nota3;
            cout << "Nota 4: "; cin >> est.nota4;

            calcularPromedio(est);
            int pos = -1 * static_cast<int>(sizeof(Estudiante));
            archivo.seekp(pos, ios::cur);
            archivo.write(reinterpret_cast<char*>(&est), sizeof(Estudiante));
            cout << "\n? Estudiante actualizado con Exito.\n";
            encontrado = true;
            break;
        }
    }

    if (!encontrado) cout << "\n?? Estudiante no encontrado.\n";
    archivo.close();
}

// Eliminar los datos completos del  por ID
void eliminarEstudiante() {
    ifstream archivo("notas.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);
    Estudiante est;
    int idEliminar;
    bool eliminado = false;

    cout << "Ingrese el ID del estudiante a eliminar: ";
    cin >> idEliminar;

    while (archivo.read(reinterpret_cast<char*>(&est), sizeof(Estudiante))) {
        if (est.id != idEliminar) {
            temp.write(reinterpret_cast<char*>(&est), sizeof(Estudiante));
        } else {
            eliminado = true;
        }
    }

    archivo.close();
    temp.close();

    remove("notas.dat");
    rename("temp.dat", "notas.dat");

    if (eliminado)
        cout << "\n? Estudiante eliminado con Exito.\n";
    else
        cout << "\n?? Estudiante no encontrado.\n";
}

// Menú principal con limpieza de pantalla
int main() {
    int opcion;

    do {
        system("cls");  // Limpiar pantalla de opciones
        cout << "===== MENU DE OPCIONES =====\n";
        cout << "1. Agregar estudiante\n";
        cout << "2. Mostrar estudiantes\n";
        cout << "3. Actualizar estudiante\n";
        cout << "4. Eliminar estudiante\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        system("cls");  // Limpiar pantalla antes de ejecutar opción

        switch (opcion) {
            case 1: crearEstudiante(); break;
            case 2: mostrarEstudiantes(); break;
            case 3: actualizarEstudiante(); break;
            case 4: eliminarEstudiante(); break;
            case 5: cout << "\n?? Saliendo del programa.\n"; break;
            default: cout << "\n? Opcion no valida.\n";
        }

        if (opcion != 5) {
            cout << "\nPresione ENTER para continuar.";
            cin.ignore();
            cin.get();
        }

    } while (opcion != 5);

    return 0;
}

