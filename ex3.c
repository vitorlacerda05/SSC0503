#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int * array, int N, int *swapCounter, int *comparisonCounter)
{
    for(int i = 1; i < N; i++)
    {
        int key = array[i];
        int j = i - 1;
        
        while(j >= 0)
        {
            (*comparisonCounter) += 1;
            if(array[j] > key)
            {
                array[j + 1] = array[j];
                j -= 1;
                (*swapCounter) += 1;
            }
            else
            {
                break;
            }
        }
        array[j + 1] = key;
        (*swapCounter) += 2;
    }
}


void Merge(int arr[], int left, int mid, int right, int* swapCounter, int* comparisonCounter)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftSubArray[n1], rightSubArray[n2];

    for (i = 0; i < n1; i++)
        leftSubArray[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightSubArray[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        (*comparisonCounter) += 1;
        if (leftSubArray[i] <= rightSubArray[j]) {
            arr[k] = leftSubArray[i];
            i += 1;
        } else {
            arr[k] = rightSubArray[j];
            j += 1;
        }

        (*swapCounter) += 2;
        k += 1;
    }

    while (i < n1) {
        arr[k] = leftSubArray[i];
        (*swapCounter) += 2;
        i += 1;
        k += 1;
    }

    while (j < n2) {
        arr[k] = rightSubArray[j];
        (*swapCounter) += 2;
        j += 1;
        k += 1;
    }
}


void MergeSort(int *array, int low, int high, int *swapCounter, int *comparisonCounter)
{
    if (low < high) {
        int mid = low + (high - low) / 2;

        MergeSort(array, low, mid, swapCounter, comparisonCounter);
        MergeSort(array, mid + 1, high, swapCounter, comparisonCounter);

        Merge(array, low, mid, high, swapCounter, comparisonCounter);
    }
}


int main()
{   
    int Q; // Número de vetores;
    scanf("%d", &Q);

    int *vetores[Q]; // Vetor de vetores;
    int N[Q]; // swapCounteramanho dos vetores;

    for(int i = 0; i < Q; i++)
    {
        scanf("%d ", &N[i]);
    }

    for(int j = 0; j < Q; j++)
    {
        vetores[j] = (int *)malloc(N[j] * sizeof(int)); // Aloca o vetor i na memória de acordo com o tamanho N lido        

        for(int k = 0; k < N[j]; k++)
        {
            scanf("%d", &vetores[j][k]);
        }

        int swapCounter = 0;
        int comparisonCounter = 0;
        InsertionSort(vetores[j], N[j], &swapCounter, &comparisonCounter);

        printf("I %d %d %d\n", N[j], swapCounter, comparisonCounter);

        swapCounter = 0;
        comparisonCounter = 0;
        MergeSort(vetores[j], 0, N[j] -1, &swapCounter, &comparisonCounter);

        printf("M %d %d %d\n", N[j], swapCounter, comparisonCounter);
    }


    // No final do programa é necessário liberar a memória alocada para cada um dos Q vetores
    for(int i = 0; i < Q; i++)
    {
        free(vetores[i]);
    }

    return 0;
}
