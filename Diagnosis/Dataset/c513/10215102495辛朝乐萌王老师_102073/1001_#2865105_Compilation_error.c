#include <stdio.h>
#include <stdlib.h>
int hex(int num,int p)
{
    int a[110];
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
    return 0；
}

int main()
{
    int n,num,p;
    scanf("%d",&n);
    int a[110],r = 0,y;
    do{
            (scanf("%d %d",&num,&p));
       }
    while(y = getchar() != EOF);
    for(int j = 0;j<n;j++){
        printf("%d\n",hex(num,p));
    }

    return 0;
}
