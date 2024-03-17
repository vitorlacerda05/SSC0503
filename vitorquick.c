#include <stdio.h>
#include <stdlib.h>

void ShellSort(int v[], int n, int *var_operator)
{

    int gap = 1;

    while (gap <= n) {
        gap *= 2;
    }

    gap = (gap / 2) - 1;

    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int x = v[i];
            *(var_operator) += 1;
            int j = i - gap;

            while (j >= 0)
            {
                *var_operator += 1;
                if( v[j] <= x )
                {                    
                    break;
                }

                v[j + gap] = v[j];
                *var_operator += 1;
                j -= gap;
            }

            v[j + gap] = x;
            *var_operator += 1;
        }

        gap /= 2;
    }
}

void QuickSort(int v[], int f, int l, int *var_operator) {

    if (f >= l) {
        return;
    }

    int m = (l + f) / 2;
    int pivot = v[m];
    *var_operator += 1;
    
    int i = f;
    int j = l;

    while (1) {
        while (v[i] < pivot) {
            *(var_operator) += 1;
            i++;
        }
        *(var_operator) += 1;


        while (v[j] > pivot) {
            *(var_operator) += 1;
            j--;
        }
        *(var_operator) += 1;

        if (i >= j) {
            break;
        }

        int aux = v[i];        
        v[i] = v[j];
        v[j] = aux;
        *(var_operator) += 3;
        i++;
        j--;
    }

    QuickSort(v, f, j, var_operator);
    QuickSort(v, j + 1, l, var_operator);
}

void PrintArray(int v[], int N) {
    int i = 0;
    printf("[ ");
    for (i = 0; i < N - 1; i++)
    {
        printf("%d, ", v[i]);
    }

    printf("%d ]\n", v[i]);
}

int main() {

    int N;
    scanf("%d", &N);

    int v[N];
    char *response;

    for (int i = 0; i < N; i++) {
        scanf("%d ", &v[i]);
    }

    response = malloc(sizeof(char) * N);

    int num_shell = 0;
    int num_quick = 0;

    for (int j = 0; j < N; j++) {
        num_shell = 0;
        int *var_shell = malloc(sizeof(int) * (j + 1));

        num_quick = 0;
        int *var_quick = malloc(sizeof(int) * (j + 1));

        for (int k = 0; k < j + 1; k++) {
            var_shell[k] = v[k];
            var_quick[k] = v[k];
        }

        ShellSort(var_shell, j + 1, &num_shell);
        QuickSort(var_quick, 0, j, &num_quick);

        if (num_shell < num_quick) {
            response[j] = 'S';
        }
        else if (num_shell > num_quick) {
            response[j] = 'Q';
        }
        else {
            response[j] = '-';
        }

        free(var_shell);
        free(var_quick);
    }

    printf("%s\n", response);

    free(response);
    return 0;
}