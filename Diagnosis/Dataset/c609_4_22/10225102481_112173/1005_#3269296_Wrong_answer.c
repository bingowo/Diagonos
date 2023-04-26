#include<stdio.h>
#include<string.h>

void Ternary(char a[])
{
    int len=strlen(a);
    int num=0;
    for(int i=0;i<len;i++)
    {
       num*=3;
       if(a[i]=='-')num+=-1;
       else num+=a[i]-'0';
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
        printf(":");
        Ternary(a);
    }
}
