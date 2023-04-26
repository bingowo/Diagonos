#include<stdio.h>
int main()
{
    int a = 0;
    scanf("%d", &a);
    int i = 0;
    int b = 0;
    while (i < a) {
        scanf("%d", &b);
        int t = 333333;
        while (t>=2333) {
            t = b / 2333;
            b = b % 2333;
            printf("%d ",t);
        }
        printf("%d", b);
        printf("\n");
        i++;
    }
    
    return 0;
}