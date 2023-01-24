#include<stdio.h>
#include<stdlib.h>

typedef struct Vector
{
    int *p;
    int tam;
} vector;

//operaciones basica de TDA vector
void crear(vector*, int);
void destruir(vector*);
void cambiar(vector*, int, int);
void obtener(vector*, int);
void mostrar(vector);

int main()
{
    vector vec;
    int pos, dato, opcion = 0;

    do
    {
        printf("\n|-----------------|");
        printf("\n|  *  VECTOR  *   |");
        printf("\n|-----------------|");
        printf("\n| 1. Crear        |");
        printf("\n| 2. Obtener      |");
        printf("\n| 3. Cambiar      |");
        printf("\n| 4. Destruir     |");
        printf("\n| 5. Mostrar      |");
        printf("\n| 6. Salir        |");
        printf("\n|-----------------|");

        printf("\n\nEscoge una opcion:\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            printf("\nIngrese el tamaño deseado para el vector:\n");
            scanf("%d", &pos);
            crear(&vec, pos);
            break;
        case 2:
            printf("\nIngrese la posicion del vector de la cual obtener informacion:\n");
            scanf("%d", &pos);
            //obtener(&vec, pos);
            break;
        case 3:
            printf("\nIngrese el dato que desea ingresar:\n");
            scanf("%d", &dato);
            printf("\nIngrese la posicion del vector la cual desea modificar:\n");
            scanf("%d", &pos);

            cambiar(&vec, dato, pos);
            break;
        case 4:
            printf("\nDestruyendo vector...\n");
            destruir(&vec);
            break;
        case 5:
            printf("\nMostrando vector...\n");
            mostrar(vec);
            break;
        case 6:
            printf("\nSaliendo del programa...\n");
            break;
        default:
            printf("\n\nOpcion no valida.\n");
        }
    }
    while(opcion != 6);


    return 0;
}

void crear(vector* vec, int pos)
{
    vec->tam = pos;
    vec->p = (int*)malloc(sizeof(int) * pos);
    printf("\nVector creado con exito.\n");
}

void destruir(vector* vec)
{
    free(vec);
    printf("\nVector destruido con exito.\n");
}

void cambiar(vector* vec, int dato, int pos)
{
    pos--;
    vec->p+pos = dato;
}

void mostrar(vector vec)
{
    for(int i = 0; i < vec.tam;i++)
        {
            printf("\n%d\n", vec.p[i]);
        }
}
