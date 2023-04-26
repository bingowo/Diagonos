#include <stdio.h>
#include <string.h>

int op(int x)
{
    int n = 0; 
    while (x > 0){
        if (x % 2 == 1) n ++;
        x /= 2;
    }
    return n;
}

int main()
{
    int n, count, sum, length;
    scanf("%d", &n);
    char c;
    c = getchar();
    for (int t; t < n; t ++){
        count = 0;
        length = 0;
        while ((c = getchar()) != '\n'){
            count += op((int)c);
            length ++;
        }
        if (count == 0){
            printf("0\n");
        }
        else{
            int a = length * 8, b = count, c;
            while (a % b != 0){
                c = a % b;
                printf("%d %d %d", a, b, c);
                a = b; 
                b = c;
            }
            count /= b;
            sum = length * 8 / b;
            printf("%d/%d\n", count, sum);
        }
    }
    return 0;
}