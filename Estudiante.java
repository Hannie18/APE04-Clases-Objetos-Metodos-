public class Estudiante {
    private String cedula;
    private String nombre;
    private String apellido;
    private double nota1, nota2, nota3;
    private double promedio;
    private String estado;

    public Estudiante(String cedula, String nombre, String apellido, double nota1, double nota2, double nota3) {
        this.cedula = cedula;
        this.nombre = nombre;
        this.apellido = apellido;
        this.nota1 = nota1;
        this.nota2 = nota2;
        this.nota3 = nota3;
        calcularPromedio();
        determinarEstado();
    }

    private void calcularPromedio() {
        this.promedio = (nota1 + nota2 + nota3) / 3.0;
    }

    private void determinarEstado() {
        this.estado = (promedio >= 7.0) ? "Aprobado" : "Reprobado";
    }

    public void mostrarInformacion() {
        System.out.printf("Cedula: %s | %-20s | Notas: [%.1f, %.1f, %.1f] | Promedio: %.2f | Estado: %s%n",
                cedula, (nombre + " " + apellido), nota1, nota2, nota3, promedio, estado);
    }

    public String getEstado() {
        return estado;
    }
}
