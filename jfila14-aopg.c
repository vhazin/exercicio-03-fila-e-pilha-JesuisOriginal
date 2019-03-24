#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int *list, n, m, aux;
    scanf("%u", &n);
    if (n < 1 || n > 50000) {
        exit(-1);
    }
    list = (int*)malloc(n * sizeof(int));
    for (unsigned int i = 0; i < n; i++) {
        scanf("%u", &list[i]);
        if (list[i] < 1 || list[i] > 100000) {
            list[i] = 0;
        }
    }

    scanf("%u", &m);
    if (m < 1 || m >= n) {
        exit(-1);
    }
    
    for (unsigned int i = 0; i < m; i++) {
        scanf("%u", &aux);
        for(unsigned int j = 0; j < n; j++)
        {
            if (list[j] == aux) {
                list[j] = 0;
                break;
            }
        }
    }

    for (unsigned int i = 0; i < n; i++) {
        if (list[i])
            printf("%u ", list[i]);
    }
}