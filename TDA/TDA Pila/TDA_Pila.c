#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Nodo
{
    int dat;
    struct Nodo * sig;
} nodo;

typedef struct Pila
{
    nodo *pri;
    int tope;
} pila;

void crear(pila*);
void destruir(pila*);
void apilar(pila*, int);
void desapilar(pila*);
void recorrer(pila*);
int tope(pila);
int vacia(pila);

int main()
{
    pila pil;
    int opcion = 0, dato;


    do
    {
        printf("\n|-------------------------------------|");
        printf("\n|             *  PILA  *              |");
        printf("\n|------------------|------------------|");
        printf("\n| 1. Crear Pila    | 5. Tope          |");
        printf("\n| 2. Apilar        | 6. Vacia         |");
        printf("\n| 3. Desapilar     | 7. Destruir      |");
        printf("\n| 4. Recorrer      | 8. Salir         |");
        printf("\n|------------------|------------------|");

        printf("\n\nEscoge una opcion:\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            printf("\n\nCreando Pila...\n");
            crear(&pil);
            break;
        case 2:
            printf("\n\nIngrese un valor para apilar, o -1 para finalizar:\n");
            scanf("%d", &dato);

            while(dato != -1)
            {
                apilar(&pil, dato);

                printf("\n\nIngrese un valor para apilar, o -1 para finalizar:\n");
                scanf("%d", &dato);
            }
            break;
        case 3:
            desapilar(&pil);
            break;
        case 4:
            recorrer(&pil);
            break;
        case 5:
            printf("\nBuscando tope de Pila...\n");
            if(tope(pil) != -1)
                printf("\nTope: %d\n", tope(pil));
            else
                printf("\nPila vacia.\n");
            break;
        case 6:
            printf("\nVerificando si la Pila se encuentra vacia...\n");
            if(vacia(pil) == 0)
                printf("\nPila vacia.\n");
            else
                printf("\nLa Pila contiene elementos.\n");
            break;
        case 7:
            printf("\n\nDestruyendo Pila...\n");
            destruir(&pil);
            break;
        case 8:
            printf("\n\nSaliendo del programa...\n");
            break;
        default:
            printf("\n\nOpcion no valida.\n");

        }
    }
    while(opcion != 8);

    return 0;
}


void crear(pila *pil)
{
    pil->pri = NULL;
    pil->tope = -1;
    printf("\nPila creada exitosamente.\n");
}
void destruir(pila* pil)
{
    nodo* actual = pil->pri;

    if(pil->pri != NULL)
    {
        while(pil->pri != NULL)
        {
            actual = pil->pri;
            pil->pri = pil->pri->sig;
            pil->tope = -1;
            free(actual);
        }
        printf("\n\n¡ENHORABUENA! Pila Destruida.\n");
    }
    else
    {
        printf("\nPila inexistente.\n");
    }
}
void apilar(pila *pil, int dato)
{
    nodo *nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dat = dato;
    nuevo->sig = pil->pri;
    pil->pri = nuevo;
    pil->tope = dato;
    printf("\nDato apilado correctamente.\n");
}
void desapilar(pila* pil)
{
    nodo* actual = pil->pri;
    nodo* anterior = (nodo*)malloc(sizeof(nodo));
    anterior = NULL;

    if(pil->pri != NULL)
    {
        pil->pri = pil->pri->sig;
        if(pil->pri == NULL)
            pil->tope = -1;
        else
            pil->tope = pil->pri->dat;

        anterior = actual;
        actual = actual->sig;

        free(anterior);

        printf("\nSe ha desapilado correctamente.\n");

    }
    else
    {
        printf("\nPila inexistente.\n");
    }
}
void recorrer(pila* pil)
{
    nodo* actual = pil->pri;

    if(pil->pri != NULL)
    {
        while(actual != NULL)
        {
            printf("\n%d\n", actual->dat);
            actual = actual->sig;
        }
    }
    else
    {
        printf("\nEsta pila se encuentra vacia.\n");
    }
}
int tope(pila pil)
{
    if(pil.tope != -1)
        return pil.tope;
    else
        return -1;
}
int vacia(pila pil)
{
    if(pil.pri != NULL)
        return 1;
    else
        return 0;
}
