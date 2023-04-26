#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//16 17
int cmp1(const *a,const *b);
int cmp2(const *a,const *b);
int cmp3(const *a,const *b);


int main()
{
    int n,i;
    scanf("%d",&n);
    char field[n][100];
    for(i=0;i<n;i++)
    {
        gets(field[i]);
    }
    char lis[100];
    gets(lis);
    if(strcmp(lis,"LIST /NAME")==0)
    {
        qsort(field,n,sizeof(field[0]),cmp1);
    }
    else if(strcmp(lis,"LIST /SIZE")==0)
    {
        qsort(field,n,sizeof(field[0]),cmp2);
    }
    else if(strcmp(lis,"LIST /TIME")==0)
    {
        qsort(field,n,sizeof(field[0]),cmp3);
    }
    for(i=0;i<n;i++)
    {
        int len=strlen(field[i]);
        int j=0;
        for(j=0;j<len;j++)
        {
            printf("%c",field[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int cmp1(const *a,const *b)
{
    int i;
    char x[1000],y[1000];
    for(i=34;i<strlen(a);i++)
    {
        x[i-34]=a[i];
    }
    for(i=34;i<strlen(b);i++)
    {
        y[i-34]=b[i];
    }
    return strcmp(x,y);
}
int cmp2(const *a,const *b)
{
    int i,j;
    char x[1000],y[1000];
    for(i=16;i<34;i++)
    {
        j=0;
        if(isspace(a[i])==0)
        {
            x[j]=a[i];
            j++;
        }
    }
    for(i=16;i<34;i++)
    {
        j=0;
        if(isspace(b[i])==0)
        {
            y[j]=b[i];
            j++;
        }
    }
    if(strcmp(x,y)!=0)
        return strcmp(x,y);
    else
        return cmp1(a,b);
}
int cmp3(const *a,const *b)
{
    int i;
    char x[1000],y[1000];
    for(i=0;i<16;i++)
    {
        x[i]=a[i];
    }
    for(i=0;i<16;i++)
    {
        y[i]=b[i];
    }
    if(strcmp(x,y)!=0)
        return strcmp(x,y);
    else
        return cmp1(a,b);
}
