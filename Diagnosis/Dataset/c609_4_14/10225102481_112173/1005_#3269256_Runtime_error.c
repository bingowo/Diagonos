#include<stdio.h>
#include<string.h>

void Ternary(char a[])
{
    int len=strlen(a);
    int num=0;
    int alp[1000];
    alp['0']=0;
    alp['1']=1;
    alp['-']=-1;
    for(int i=0;i<len;i++)
    {
        num*=3;
        num+=alp[a[i]];
    }
    printf("%d\n",num);
}

int main()
{
    int total;
    scanf("%d\n",&total);
    for(int i=0;i<total;i++)
    {
        char a[1000];
        scanf("%s\n",a);
        printf("case # ");
        printf("%d",i);
        printf(':');
        Ternary(a);
    }
}
