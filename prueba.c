
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <nombre_del_archivo>\n", argv[0]);
        return 1;
    }

    FILE *archivo = fopen(argv[1], "r");
    
    if (archivo == NULL) {
        printf("Error al abrir el archivo %s.\n", argv[1]);
        return 1;
    }
    
    FILE *nuevoArchivo = fopen("nuevoArchivo.txt", "w");
    
    if (nuevoArchivo == NULL) {
        printf("Error al crear el nuevo archivo.\n");
        fclose(archivo);
        return 1;
    }
    
    int elemento1, elemento2;
    char linea[100];
    
    printf("Ingrese el presupuesto: ");
    int presupuesto;
    scanf("%d", &presupuesto);
    
    while (fgets(linea, sizeof(linea), archivo)) {
        sscanf(linea, "%d %d", &elemento1, &elemento2);
        
        if (elemento1 > elemento2 && elemento2 <= presupuesto) {
            // Solo escribe las líneas donde el primer elemento es mayor que el segundo y el costo es menor o igual al presupuesto ingresado
            fputs(linea, nuevoArchivo);
        }
    }
    
    fclose(archivo);
    fclose(nuevoArchivo);
    
    // Reemplaza el archivo original con el nuevo archivo
    remove(argv[1]);
    rename("nuevoArchivo.txt", argv[1]);
    
    return 0;
}




/*
461 637
1026 710
755 181
962 533
641 61
706 294*/
