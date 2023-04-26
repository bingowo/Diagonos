#include <stdio.h>

void find(int *N)
{
    int A[101] = {0}, i = 0, a = 2;
    while(i < 25){
        if (A[a] == 0){
            N[i++] = a;
            for (int b = 1;a*b < 100;b++) A[a*b] = 1;
        }
        a += 1;
    }
}

int main()
{
    int P[25][50], I[25], N[25], i = 0;find(N);
    do{
        scanf("%d", &I[i++]);
    }while (getchar() != '\n');
    
}