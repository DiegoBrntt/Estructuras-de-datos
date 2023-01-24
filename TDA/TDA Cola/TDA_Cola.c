#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Nodo
{
    int dat;
    struct Nodo * sig;
} nodo;

typedef struct Cola
{
    nodo *pri, *ult;
    int frente;
    int fondo;
} cola;

void crear(cola*);
void destruir(cola*);
void acolar(cola*, int);
void desacolar(cola*);
void recorrer(cola*);
int frente(cola);
int vacia(cola);

int main()
{
    cola col;
    int opcion = 0, dato;

    do
    {
        printf("\n|-------------------------------------|");
        printf("\n|             *  COLA  *              |");
        printf("\n|------------------|------------------|");
        printf("\n| 1. Crear Cola    | 5. Recorrer      |");
        printf("\n| 2. Acolar        | 6. Frente        |");
        printf("\n| 3. Desacolar     | 7. Vacia         |");
        printf("\n| 4. Destruir      | 8. Salir         |");
        printf("\n|------------------|------------------|");

        printf("\n\nEscoge una opcion:\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            crear(&col);
            break;
        case 2:
            printf("\n\nIngrese un valor para acolar, o -1 para finalizar:\n");
            scanf("%d", &dato);

            while(dato != -1)
            {
                acolar(&col, dato);

                printf("\n\nIngrese un valor para acolar, o -1 para finalizar:\n");
                scanf("%d", &dato);
            }
            break;
        case 3:
            desacolar(&col);
            break;
        case 4:
            destruir(&col);
            break;
        case 5:
            printf("\n\nRecorremos la lista:\n");
            recorrer(&col);
            break;
        case 6:
            printf("\nBuscando frente de Cola...\n");
            if(frente(col) != -1)
                printf("\nFrentee: %d\n", frente(col));
            else
                printf("\nCola vacia.\n");
            break;
        case 7:
            printf("\nVerificando si la Cola esta vacia...\n");
            if(vacia(col) == 0)
                printf("\nCola vacia.\n");
            else
                printf("\nLa Cola contiene elementos.\n");
            break;
        case 8:
            printf("\nSaliendo del programa...\n");
            break;
        default:
            printf("\n\nOpcion no valida.\n");

        }
    }
    while(opcion != 8);

    return 0;
}


void crear(cola *col)
{
    col->pri = NULL;
    col->ult = NULL;
    col->frente = -1;
    col->fondo = -1;
    printf("\nCola creada exitosamente.\n");
}
void destruir(cola *col)
{
    nodo* actual = col->pri;

    if(col->pri != NULL)
    {
        while(col->pri != col->ult->sig)
        {
            actual = col->pri;
            col->pri = col->pri->sig;
            free(actual);
        }
        col->frente = -1;
        actual = col->ult;
        free(actual);


        printf("\n\n�ENHORABUENA! Cola Destruida.\n");
    }
    else
    {
        printf("\nCola inexistente.\n");
    }
}
void acolar(cola *col, int dato)
{
    nodo* nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->dat = dato;

    if(col->pri == NULL)
    {
        col->frente = dato;
        col->fondo = dato;
        col->pri = nuevo;
        col->pri->sig = NULL;
        col->ult = nuevo;
    }
    else
    {
        col->ult->sig = nuevo;
        nuevo->sig = NULL;
        col->ult = nuevo;
        col->fondo = dato;
    }

    printf("\nDato acolado correctamente\n");
}

void recorrer(cola* col)
{
    nodo* actual = col->pri;

    if(col->pri != NULL)
    {
        while(actual != NULL)
        {
            printf("\n%d\n", actual->dat);
            actual = actual->sig;
        }
    }
    else
    {
        printf("\nEsta lista se encuentra vacia.\n");
    }
}


int frente(cola col)
{
    if(col.frente == -1)
        return -1;
    else
        return col.frente;
}

int vacia(cola col)
{
    if(col.pri == NULL)
        return 0;
    else
        return -1;
}

void desacolar(cola* col)
{
    nodo* actual = col->pri;
    nodo* anterior = (nodo*)malloc(sizeof(nodo));
    anterior = NULL;

    if(col->pri != NULL)
    {
            col->pri = col->pri->sig;
            if(col->pri == NULL)
                col->frente = -1;
                col->fondo = -1;
            else
                col->frente = col->pri->dat;


            anterior = actual;
            actual = actual->sig;

            free(anterior);

    }
    else
    {
        printf("\n La cola no existe\n\n");
    }
}

