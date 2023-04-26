#include <stdio.h>
#include <stdlib.h>
char c[10000];

void zhuanhuan(int a,int b)
{
    int m,n;
    char s;
    int i;
    if(a<0)
    {
        c[0]='-';
        a=-a;
            if(b<=10)
    {
        for(i=1;a>0;a=a/b,i++)
        {
            c[i]=48+a%b;
        }
        c[i]='\0';
        }
    else
        {
            for(i=1;a>0;i++)
            {
                if(a%b<10)
                {
                    c[i]=48+a%b;
                    a=a/b;
                }
                else
                {
                    c[i]=55+a%b;
                    a=a/b;
                }
            }
            c[i]='\0';
        }
        for(m=1,n=strlen(c)-1;m<n;m++,n--)
    {
        s=c[m];
        c[m]=c[n];
        c[n]=s;
    }
    }
    else
    {
    if(b<=10)
    {
        for(i=0;a>0;a=a/b,i++)
        {
            c[i]=48+a%b;
        }
        c[i]='\0';
        }
    else
        {
            for(i=0;a>0;i++)
            {
                if(a%b<10)
                {
                    c[i]=48+a%b;
                    a=a/b;
                }
                else
                {
                    c[i]=55+a%b;
                    a=a/b;
                }
            }
            c[i]='\0';
        }
        for(m=0,n=strlen(c)-1;m<n;m++,n--)
    {
        s=c[m];
        c[m]=c[n];
        c[n]=s;
    }
    }
}

int main()
{
    int T,i,j,k,l;
    scanf("%d",&T);
    int a[T][2];
    for(i=0;i<T;i++)
    {
        for(j=0;j<2;j++)
            scanf("%d",&a[i][j]);
    }
    for(k=0;k<T;k++)
        {
            zhuanhuan(a[k][0],a[k][1]);
            for(l=0;c[l];l++)
                printf("%c",c[l]);
            printf("\n");
        }
}
