#include <stdio.h>
#include <stdlib.h>
void hex(int num,int p)
{
    int a[100];
    int i = 0;
    do{
        a[++i] = num%p;
        num = num/p;
    }while(num != 0);
    for(;i>0;i--)
    {
        if(a[i]<10){
            printf("%d",a[i]);
        }
        else{
            a[i] = a[i] % 10 + 'A';
            printf("%c",a[i]);
        }
    }
}

int main()
{
    int n,num,p;
    scanf("%d",&n);
    int a[100],r = 0,y;
    while(scanf("%d %d",&num,&p) != EOF);
    hex(num, p);
    printf("\n");
    return 0;
}
