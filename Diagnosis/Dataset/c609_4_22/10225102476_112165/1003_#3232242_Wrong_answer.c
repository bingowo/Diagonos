#include<stdio.h>
#include<math.h>
int main()
{
    int a;
    scanf("%d", &a);
    int i = 0;
    while(i<a){
        int m;
        scanf("%d", &m);
        int n = 0;
        while (m >= pow(2333, n+1))
            n++;
        while (n>=0) {
            int t = m / pow(2333, n);
            printf("%d ", t);
            m = m - t*pow(2333, n);
            n--;
        }
        printf("\n");
        i++;
    }

    return 0;
}