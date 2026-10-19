#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int not_execute() {
        printf("Esta funcion no se ejecuta\n");
        exit(3);
}

int main(int count, char *argument[]){
        char buffer[100];

        if (count  < 2 ){
                printf("Se debe ingresar texto como entrada.  \n");
                exit(1);

        }

        strcpy(buffer, argument[1]);
        printf("[DEBUG] buffer = %p\n", buffer);
        printf("Yo soy main() y no ejecuto ninguna otra funcion\n");

        return 0;
}
