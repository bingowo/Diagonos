#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000

void solveInt(int n)
{
    int num = sizeof(n);
    char *p = (char*)&n;
    while(num--) {printf("%02x ",*p++);}
    printf("\n");
}

void solveDouble(double n)
{
    int num = sizeof(n);
    char *p = (char*)&n;
    while(num--) {printf("%02x ",*p++);}
    printf("\n");
}

int main()
{
    char a[N]; //double类型需要64位存储，8个字节

    while(scanf("%s",a)!=EOF)
    {
        int flag = 1;

        if(strchr(a,'.')==0) flag = 0;

        if(flag == 1) solveDouble(atof(a));
        else solveInt(atoi(a));
    }
    return 0;
}
