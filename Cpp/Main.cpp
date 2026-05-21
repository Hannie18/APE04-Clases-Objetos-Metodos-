#include <iostream>
#include <string>
#include <vector>  // Nos sirve para poder usar arreglos dinamicos
#include <iomanip>

using namespace std;

class Estudiante {
private:
// Declaramos las variables en private para que el usuaro no lo pueda modificar
    string cedula;
    string nombre;
    string apellido;
    double nota1;
    double nota2;
    double nota3;
    double promedio;
    string estado;

public:
    Estudiante(string _cedula, string _nombre, string _apellido, double _nota1, double _nota2, double _nota3) {
        cedula = _cedula;
        nombre = _nombre;
        apellido = _apellido;
        nota1 = _nota1;
        nota2 = _nota2;
        nota3 = _nota3;
        calcularPromedio();
        determinarEstado();
    }

    void calcularPromedio() {
        promedio = (nota1 + nota2 + nota3) / 3.0;
    }

    void determinarEstado() {
        if (promedio >= 7.0) {
            estado = "Aprobado";
        } else {
            estado = "Reprobado";
        }
    }

    void mostrarInformacion() {
        cout << fixed << setprecision(1);
        cout << "Cedula: " << cedula << " | "
             << left << setw(20) << (nombre + " " + apellido)
             << " | Notas: [" << nota1 << ", " << nota2 << ", " << nota3 << "] | "
             << fixed << setprecision(2) << "Promedio: " << promedio << " | "
             << "Estado: " << estado << endl;
    }

    // Getter para filtrar el estado en los reportes
    string getEstado() { return estado; }
};

int main() {
    // Vector dinamico para almacenar los objetos Estudiante
    vector<Estudiante> listaEstudiantes;
    char opcion;

    do {
        string cedula, nombre, apellido;
        double n1, n2, n3;

        cout << "\n=== SISTEMA BASICO DE CONTROL DE ESTUDIANTES Y CALIFICACIONES ===" << endl;

        while (true) {
            cout << "Ingrese la Cedula (10 digitos): ";
            cin >> cedula;
            if (cedula.length() == 10) break;
            cout << "X Error: La cedula debe tener exactamente 10 digitos." << endl;
        }

        cin.ignore();
        cout << "Ingrese su Nombre: ";
        getline(cin, nombre);
        cout << "Ingrese su Apellido: ";
        getline(cin, apellido);

        cout << "Ingrese Nota 1: ";
        cin >> n1;
        cout << "Ingrese Nota 2: ";
        cin >> n2;
        cout << "Ingrese Nota 3: ";
        cin >> n3;

        // Esta parte servira para crear el objeto y meterlo al vector dinamico
        Estudiante nuevoEstudiante(cedula, nombre, apellido, n1, n2, n3);
        listaEstudiantes.push_back(nuevoEstudiante);
        cout << " El estudiante fue registrado CORRECTAMENTE :) ." << endl;

        cout << "\nDesea registrar otro estudiante? (S/N): ";
        cin >> opcion;
        opcion = toupper(opcion);

    } while (opcion == 'S');

    // ================= REPORTES FINALES =================
    cout << "\n==============================================================================================================" << endl;
    cout << "                                             REGISTRO TOTAL                                                     " << endl;
    cout << "==============================================================================================================" << endl;

    // 1. Lista Total
    cout << "\n--------------------------------- LISTA TOTAL DE ESTUDIANTES REGISTRADOS --------------------------------------" << endl;
    for (size_t i = 0; i < listaEstudiantes.size(); i++) {
        listaEstudiantes[i].mostrarInformacion();
    }

    // 2. Lista de Aprobados
    cout << "\n---------------------------------------- ESTUDIANTES APROBADOS ------------------------------------------------" << endl;
    bool hayAprobados = false;
    for (size_t i = 0; i < listaEstudiantes.size(); i++) {
        if (listaEstudiantes[i].getEstado() == "Aprobado") {
            listaEstudiantes[i].mostrarInformacion();
            hayAprobados = true;
        }
    }
    if (!hayAprobados) cout << "No hay estudiantes aprobados." << endl;

    // 3. Lista de Reprobados
    cout << "\n-------------------------------------------- ESTUDIANTES REPROBADOS --------------------------------------------" << endl;
    bool hayReprobados = false;
    for (size_t i = 0; i < listaEstudiantes.size(); i++) {
        if (listaEstudiantes[i].getEstado() == "Reprobado") {
            listaEstudiantes[i].mostrarInformacion();
            hayReprobados = true;
        }
    }
    if (!hayReprobados) cout << "No hay estudiantes reprobados." << endl;

    cout << "\n================================================================================================================" << endl;
    return 0;
}
