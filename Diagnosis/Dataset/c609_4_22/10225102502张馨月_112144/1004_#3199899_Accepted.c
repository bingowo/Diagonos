#include<stdio.h>
#include<string.h>
void reverse(char s[])
{
    int i,j,t;
    for ( i = 0,j=strlen(s)-1; i <j; i++,j--)
    {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}

int main()
{
    int a,b;
    char n[32];
    scanf("%d%s%d",&a,&n,&b);
    int d=0;//d为十进制数
    int j=strlen(n)-1;
    int i;
    for(i=0;i<=j;i++)
    {
        if(n[i]<='9'&&n[i]>='0')
        {
            d=d*a+n[i]-'0';
        }
        else if(n[i]<='f'&&n[i]>='a')
        {
            d=d*a+10+n[i]-'a';
        }
        else if(n[i]<='F'&&n[i]>='A')
        {
            d=d*a+10+n[i]-'A';
        }
    }


    char r[32];
    int k=0;
    char table[]={"0123456789ABCDEF"};
    do
    {
        r[k]=table[d%b];
        d=d/b;
        k++;
    }while(d>0);
    r[k]='\0';

    reverse(r);

    printf("%s",r);
    return 0;
}
