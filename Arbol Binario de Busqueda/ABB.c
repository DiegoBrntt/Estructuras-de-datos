#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int clave;
    struct Nodo *padre;
    struct Nodo *izquierda;
    struct Nodo *derecha;
} nodo;

void crear(nodo **);
void alta(nodo **, int);
int esta(nodo **, int);
void recorridoPreorden(nodo **);
void recorridoInorden(nodo **);
void recorridoPosorden(nodo **);
int cantidadNodos(nodo **);
int alturaArbol(nodo **);

int main()
{
    nodo arbol;
    int opcion = -1, dato;

    do
    {
        printf("\n-----------------------------");
        printf("\n| ARBOL DE BUSQUEDA BINARIO |");
        printf("\n-----------------------------");
        printf("\n| 1. Crear Arbol Binario    |");
        printf("\n| 2. Alta                   |");
        printf("\n| 3. Buscar                 |");
        printf("\n| 4. Recorrido Preorden     |");
        printf("\n| 5. Recorrido Inorden      |");
        printf("\n| 6. Recorrido Posorden     |");
        printf("\n| 7. Cantidad de nodos      |");
        printf("\n| 8. Altura del arbol       |");
        printf("\n| 0. Salir                  |");
        printf("\n-----------------------------");
        printf("\n\nEscoge una opcion:\n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("\nCreando Arbol de Busqueda Binario... \n");
            crear(&arbol);
            printf("\nArbol de Busqueda Binario creado exitosamente. \n");
            break;
        case 2:
            printf("\nIngrese clave para dar de alta: \n");
            scanf("%d", &dato);
            alta(&arbol, dato);
            break;
        case 3:
            printf("\nIngrese clave a buscar: \n");
            scanf("%d", &dato);
            if (esta(&arbol, dato) == 0)
            {
                printf("\nClave (%d) NO encontrada \n", dato);
            }
            else
            {
                printf("\nClave (%d) encontrada \n", dato);
            }
            break;
        case 4:
            printf("\nRecorriendo arbol preorden: \n");
            recorridoPreorden(&arbol);
            break;
        case 5:
            printf("\nRecorriendo arbol inorden: \n");
            recorridoInorden(&arbol);
            break;
        case 6:
            printf("\nRecorriendo arbol posorden: \n");
            recorridoPosorden(&arbol);
            break;
        case 7:
            printf("\nContando nodos... \n");
            printf("\nNodos: %d \n", cantidadNodos(&arbol));
            break;
        case 8:
            printf("\nMidiendo arbol... \n");
            printf("\nNiveles: %d \n", alturaArbol(&arbol));
            break;
        case 0:
            printf("\nSaliendo del programa... (gracias vuelvas prontos) \n");
            break;
        default:
            printf("\nOpcion no valida. \n");
            break;
        }

    }
    while (opcion != 0);
}

void crear(nodo **arbol)
{
    *arbol = NULL;
}
void alta(nodo **arbol, int dato)
{
    if (*arbol == NULL)
    {
        (*arbol) = (nodo **)malloc(sizeof(nodo));
        (*arbol)->clave = dato;
        (*arbol)->derecha = NULL;
        (*arbol)->izquierda = NULL;
        printf("\nAlta dada correctamente. \n");
    }
    else
    {
        if (dato < (*arbol)->clave)
        {
            alta(&((*arbol)->izquierda), dato);
        }
        else if (dato > (*arbol)->clave)
        {
            alta(&((*arbol)->derecha), dato);
        }
        else
        {
            printf("\nEsta clave ya existe. \n");
        }
    }
}
int esta(nodo **arbol, int dato)
{
    if (*arbol == NULL)
    {
        return 0;
    }
    else
    {
        if (dato == (*arbol)->clave)
        {
            return 1;
        }
        else
        {
            if (dato < (*arbol)->clave)
            {
                return esta(&((*arbol)->izquierda), dato);
            }
            else
            {
                return esta(&((*arbol)->derecha), dato);
            }
        }
    }
}
void recorridoPreorden(nodo **arbol)
{
    if(*arbol != NULL)
    {
        printf("\n%d ", (*arbol)->clave);
        recorridoPreorden(&((*arbol)->izquierda));
        recorridoPreorden(&((*arbol)->derecha));
    }
}
void recorridoInorden(nodo **arbol)
{
    if(*arbol != NULL)
    {
        recorridoInorden(&((*arbol)->izquierda));
        printf("\n%d ", (*arbol)->clave);
        recorridoInorden(&((*arbol)->derecha));
    }
}
void recorridoPosorden(nodo **arbol)
{
    if(*arbol != NULL)
    {
        recorridoPosorden(&((*arbol)->izquierda));
        recorridoPosorden(&((*arbol)->derecha));
        printf("\n%d ", (*arbol)->clave);
    }
}
int cantidadNodos(nodo **arbol)
{
    if(*arbol == NULL)
    {
        return 0;
    }
    int contador = 0;

    int cont_izq = cantidadNodos(&((*arbol)->izquierda));
    int cont_der = cantidadNodos(&((*arbol)->derecha));

    contador = cont_izq + cont_der +1;

    return contador;
}
int alturaArbol(nodo **arbol)
{
    if(*arbol == NULL)
    {
        return 0;
    }
    int contador = 0;

    int cont_izq = alturaArbol(&((*arbol)->izquierda));
    int cont_der = alturaArbol(&((*arbol)->derecha));

    contador = cont_izq > cont_der ? cont_izq + 1 : cont_der + 1;

    return contador;
}
