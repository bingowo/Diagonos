#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char a[4000][15];
int n;
int function(char*b)
{
    int k,j,i;
    k=strlen(b);
    for(i=0;i<k-1;i++)
    {
        for(j=0;j<n;j++)
        {
            if(!strcmp(a[j],b)) {printf("%s ",b);return i;}
        }
        b[k-1-i]=0;
    }
    printf("%s ",b);
    return i;
}
void move(char*a,int b)
{
    int i=strlen(a),j;
    for(j=b;j<i;j++)
    {
        a[j-b]=a[j];
    }
}
int main()
{
    int i,k,j,l=0,max=0,o,h;
    char b[5001],c[15]={0};

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",a[i]);
        j=strlen(a[i]);
        if(j>max) max=j;
    }
    scanf("%s",b);
    for(k=0;k<=strlen(b);k++)
    {
        strncpy(c,b,max);
        h=function(c);
        k+=max-h;
        move(b,max-h);

    }
    printf("\n");
}
