#include <stdio.h>
#include <stdlib.h>

void ShellSort(int v[], int n, int *Op)
{

    int gap = 1;

    while (gap <= n)
    {
        gap *= 2;
    }

    gap = (gap / 2) - 1;

    while (gap > 0)
    {
        for (int i = gap; i < n; i++)
        {
            int x = v[i];
            *(Op) += 1;
            int j = i - gap;

            while (j >= 0)
            {
                *Op += 1;
                if( v[j] <= x )
                {                    
                    break;
                }

                v[j + gap] = v[j];
                *Op += 1;
                j -= gap;
            }

            v[j + gap] = x;
            *Op += 1;
        }

        gap /= 2;
    }
}

void QuickSort(int v[], int f, int l, int *Op)
{

    if (f >= l)
    {
        return;
    }

    int m = (l + f) / 2;
    int pivot = v[m];
    *Op += 1;
    
    int i = f;
    int j = l;

    while (1)
    {
        while (v[i] < pivot)
        {
            *(Op) += 1;
            i++;
        }
        *(Op) += 1;


        while (v[j] > pivot)
        {
            *(Op) += 1;
            j--;
        }
        *(Op) += 1;

        if (i >= j)
        {
            break;
        }

        int aux = v[i];        
        v[i] = v[j];
        v[j] = aux;
        *(Op) += 3;
        i++;
        j--;
    }

    QuickSort(v, f, j, Op);
    QuickSort(v, j + 1, l, Op);
}

void PrintArray(int v[], int N)
{
    int i = 0;
    printf("[ ");
    for (i = 0; i < N - 1; i++)
    {
        printf("%d, ", v[i]);
    }

    printf("%d ]\n", v[i]);
}

int main()
{
    // Número de elementos no vetor
    int N;
    scanf("%d", &N);

    int v[N];
    char *response;

    for (int i = 0; i < N; i++)
    {
        scanf("%d ", &v[i]);
    }

    response = malloc(sizeof(char) * N);

    int numeroDeOperacoesShell = 0;
    int numeroDeOperacoesQuick = 0;

    for (int j = 0; j < N; j++)
    {
        numeroDeOperacoesShell = 0;
        numeroDeOperacoesQuick = 0;

        int *vShell = malloc(sizeof(int) * (j + 1));
        int *vQuick = malloc(sizeof(int) * (j + 1));

        for (int k = 0; k < j + 1; k++)
        {
            vShell[k] = v[k];
            vQuick[k] = v[k];
        }

        // PrintArray(vShell, j + 1);
        // PrintArray(vQuick, j + 1);

        ShellSort(vShell, j + 1, &numeroDeOperacoesShell);
        QuickSort(vQuick, 0, j, &numeroDeOperacoesQuick);

        // printf("Shell: %d\n", numeroDeOperacoesShell);
        // printf("Quick: %d\n", numeroDeOperacoesQuick);

        // PrintArray(vShell, j + 1);
        // PrintArray(vQuick, j + 1);

        if (numeroDeOperacoesShell < numeroDeOperacoesQuick)
        {
            response[j] = 'S';
        }
        else if (numeroDeOperacoesShell > numeroDeOperacoesQuick)
        {
            response[j] = 'Q';
        }
        else
        {
            response[j] = '-';
        }

        free(vShell);
        free(vQuick);
    }

    printf("%s\n", response);

    free(response);
    return 0;
}