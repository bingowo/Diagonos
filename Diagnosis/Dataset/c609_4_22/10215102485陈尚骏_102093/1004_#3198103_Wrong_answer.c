#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    int A,a[33],b;
    char c[33];
    int i=0;
    scanf("%d",&A);
    scanf("%s",c);
    if(A>10)
    {
    for(;i<strlen(c)-1;i++)
    {
        if(c[i]<='z'&&c[i]>='a')
        {
            a[i]=c[i]-'a'+10;
        }
        else if(c[i]<='Z'&&c[i]>='A')
        {
            a[i]=c[i]-'A'+10;
        }
    }
    }
    else
    {
        for(;i<strlen(c)-1;i++)
        {
            a[i]=c[i]-'0';
        }
    }
    if(c[strlen(c)-1]<='z'&&c[strlen(c)-1]>='a')
    {
        a[strlen(c)-1]=c[strlen(c)-1]-'a'+10;
    }
    else if(c[strlen(c)-1]<='Z'&&c[strlen(c)-1]>='A')
    {
        a[strlen(c)-1]=c[strlen(c)-1]-'A'+10;
    }
    else a[strlen(c)-1]=c[strlen(c)-1]-'0';
    scanf("%d",&b);
    int aten=0;
    for(int j=0;j<strlen(c);j++)
    {
        int x=1;
        for(int k=strlen(c)-1-j;k>0;k--)
        {
            x=x*A;
        }
        aten+=a[j]*x;
    }
    if(b==10)
    {
        printf("%d\n",aten);
        return 0;
    }
    int c1=0,a1[100];
    while(aten)
    {
        a1[c1]=(aten%b);
        c1++;
        aten/=b;
    }
    for(i=c1-1;i>=0;i--)
    {
        if(a1[i]>=10)
        {
            printf("%c",'A'+a1[i]-10);
        }
        else printf("%d",a1[i]);
    }
    printf("\n");
    return 0;
}
