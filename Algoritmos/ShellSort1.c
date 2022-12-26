#include <stdio.h>
#include <stdlib.h>

void shellSort(int[], int);
void printArray(int [], int );

// En el main se imprime el menú y se manda a llamar la función de shell sort dependiendo de que tipo de caso el usuario quiera simular.
int main()
{
    int mejor[] = {2, 3, 5, 6, 11, 14, 17, 18, 19};
    int normal[] = {19, 18, 3, 17, 5, 6, 14, 11, 2};
    int peor[] = {19, 2, 18, 3, 17, 5, 14, 6, 11};
    int size = sizeof(normal) / sizeof(normal[0]), cho= 0;

    do
    {
        printf("\n\t\tBIENVENIDOS A LA SIMULACION");
        printf("\n\tElija la simulaci%cn deseada: ",162);
        printf("\n\n\t[1] Mejor de los casos.");
        printf("\n\t[2] Peor de los casos.");
        printf("\n\t[3] Caso normal.");
        printf("\n\t[4] Salir.\n");
        scanf("%d", &cho);
        fflush(stdin);
        switch(cho)
        {
            case 1:
                shellSort(mejor, size);
                break;
            case 2:
                shellSort(peor, size);
                break;
            case 3:
                shellSort(normal, size);
                break;
            case 4:
                printf("\nBUEN DIA\n");
                break;
        }
    }while(cho!=4);
}

// Aplica el método de ordenamiento Shell sort.
void shellSort(int array[], int n) {
  // Reordena  el arreglo usando los brincos necesarios (n/2, n/4, n/8, ... 1).
    int i, j, m, aux;
    system("cls");
    printf("Array a ordenar:\n");
    printArray(array, n);
    getchar();
    for (m = n / 2; m > 0; m /= 2)
    {
        printf("\n\tSalto = %d\n",m);
        for (j = m; j < n; j++)
        {
            for (i = j-m; i>=0; i-=m)
            {
                printf("\nPosici%cn de i: %d.\n",162, i+1);
                if(array[i+m]>=array[i])
                    break;
                else
                {
                    printf("\nCambia posici%cn %d con %d.\n\n",162, i+1, i+m);
                    aux = array[i];
                    array[i] = array[i+m];
                    array[i+m]=aux;
                }
            }
            printArray(array, n);
            getchar();
        }
    }
}

// Imprime el array.
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}
