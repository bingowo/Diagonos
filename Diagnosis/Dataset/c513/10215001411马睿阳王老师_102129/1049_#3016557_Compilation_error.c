#include<stdio.h>
#include<string.h>

int cmp(const void*a,const void*b)
{
    char*c=*(char**)a;
    char*d=*(char**)b;
    if(strcmp(c,d)<0) return-1;
    else return 1;
}
int main()
{
    int T,i=0,j=0,k=0,t=0;
    char a[505];
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        char b[500][50]={0},c[500][50]={0};
        int d[500]={0},e[500]={0};
        int l=0;
        int h=0,n=0,m=0,q=0,w=0;
        while(scanf("%s",a)!=EOF)
        {
            int d=0,t=0;
            l=strlen(a);
            for(j=0;j<l;j++)
            {

                if(a[j]==','||a[j]=='.'||a[j]=="!"||a[j]=='?')
                {
                    for(k=d;k<j;k++)
                    {
                        b[t][k]=b[k];
                    }
                    d[t]=k;
                    d=j;
                    t++;
                }
            }
        }
        m=0;
        for(n=0;n<d[0];n++)
            c[0][n]=b[0][n];
        for(h=1;h<t;h++)
        {

            if(b[h]!=b[h-1])
            {
                for(n=0;n<d[t];n++)
                {
                   c[m][n]=b[t][n];
                   e[m]=n;
                   m++;
                   t++;

                }
            }
            c[m][n]='\0';////////////???
        }
        qsort(c,m-1,sizeof(c[0]),cmp);
        printf("case #%d:\n",i);
        for(q=0;q<m;q++)
        {
            for(w=0;w<e[q];w++)
            {
                printf("%c ",c[q][w]);
            }
        }
        printf("\n");

    }
}
