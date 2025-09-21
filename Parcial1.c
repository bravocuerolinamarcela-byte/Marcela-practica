#include <stdio.h>

typedef struct {
    int codigo;
    float nota;
} Estudiante;

Estudiante estudiantes[] = {
    {2024101, 4.5},
    {2024102, 3.2},
    {2024103, 2.9},
    {2024104, 5.0},
    {2024105, 3.8}
};

int cantidad = 5;

float notaMaxima(Estudiante lista[], int n) {
    if (n == 1) {
        return lista[0].nota;
    }
    float mayor = notaMaxima(lista, n - 1);
    if (lista[n - 1].nota > mayor) {
        return lista[n - 1].nota;
    }
    return mayor;
}

float sumaNotas(Estudiante lista[], int n) {
    if (n == 1) {
        return lista[0].nota;
    }
    return lista[n - 1].nota + sumaNotas(lista, n - 1);
}

void ordenarPorCodigo(Estudiante lista[], int inicio, int n) {
    if (inicio >= n - 1) return;
    int lugarMenor = inicio;
    for (int i = inicio + 1; i < n; i++) {
        if (lista[i].codigo < lista[lugarMenor].codigo) {
            lugarMenor = i;
        }
    }
    if (lugarMenor != inicio) {
        Estudiante temp = lista[inicio];
        lista[inicio] = lista[lugarMenor];
        lista[lugarMenor] = temp;
    }
    ordenarPorCodigo(lista, inicio + 1, n);
}

void mostrar(Estudiante lista[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Codigo: %d  Nota: %.2f\n", lista[i].codigo, lista[i].nota);
    }
}

int main() {
    int opcion = 0;
    do {
        printf("\n=== MENU ===\n");
        printf("1. Ver nota maxima\n");
        printf("2. Ver promedio\n");
        printf("3. Ordenar por codigo\n");
        printf("4. Mostrar lista\n");
        printf("5. Salir\n");
        printf("Escoja una opcion: ");
        if (scanf("%d", &opcion) != 1) {
            printf("Entrada invalida.\n");
            return 1; 
        }

        if (opcion == 1) {
            float max = notaMaxima(estudiantes, cantidad);
            printf("La nota maxima es: %.2f\n", max);
        }
        else if (opcion == 2) {
            float suma = sumaNotas(estudiantes, cantidad);
            float promedio = suma / cantidad;
            printf("El promedio es: %.2f\n", promedio);
        }
        else if (opcion == 3) {
            ordenarPorCodigo(estudiantes, 0, cantidad);
            printf("Lista ordenada.\n");
        }
        else if (opcion == 4) {
            mostrar(estudiantes, cantidad);
        }
        else if (opcion == 5) {
            printf("Saliendo...\n");
        }
        else {
            printf("Opcion no valida.\n");
        }

    } while (opcion != 5);

    return 0;
}