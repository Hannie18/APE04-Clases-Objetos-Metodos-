import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Estudiante> listaEstudiantes = new ArrayList<>();
        String opcion;

        do {
            System.out.println("\n=== SISTEMA BASICO DE CONTROL DE ESTUDIANTES ===");
            String cedula;
            while (true) {
                System.out.print("Ingrese la Cedula (10 digitos): ");
                cedula = sc.nextLine();
                if (cedula.length() == 10) break;
                System.out.println("X Error: La cedula debe tener 10 digitos.");
            }

            System.out.print("Ingrese su Nombre: ");
            String nombre = sc.nextLine();
            System.out.print("Ingrese su Apellido: ");
            String apellido = sc.nextLine();
            System.out.print("Ingrese Nota 1: ");
            double n1 = Double.parseDouble(sc.nextLine());
            System.out.print("Ingrese Nota 2: ");
            double n2 = Double.parseDouble(sc.nextLine());
            System.out.print("Ingrese Nota 3: ");
            double n3 = Double.parseDouble(sc.nextLine());

            listaEstudiantes.add(new Estudiante(cedula, nombre, apellido, n1, n2, n3));
            System.out.println("Estudiante registrado correctamente.");

            System.out.print("\nDesea registrar otro estudiante? (S/N): ");
            opcion = sc.nextLine().toUpperCase();
        } while (opcion.equals("S"));

        // Reportes
        System.out.println("\n--- LISTA TOTAL ---");
        for (Estudiante e : listaEstudiantes) e.mostrarInformacion();

        System.out.println("\n--- APROBADOS ---");
        boolean hayAprobados = false;
        for (Estudiante e : listaEstudiantes) {
            if (e.getEstado().equals("Aprobado")) {
                e.mostrarInformacion();
                hayAprobados = true;
            }
        }
        if (!hayAprobados) System.out.println("No hay aprobados.");

        System.out.println("\n--- REPROBADOS ---");
        boolean hayReprobados = false;
        for (Estudiante e : listaEstudiantes) {
            if (e.getEstado().equals("Reprobado")) {
                e.mostrarInformacion();
                hayReprobados = true;
            }
        }
        if (!hayReprobados) System.out.println("No hay reprobados.");
        
        sc.close();
    }
}