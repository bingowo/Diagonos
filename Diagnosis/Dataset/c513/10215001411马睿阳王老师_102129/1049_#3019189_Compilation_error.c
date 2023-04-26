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
    int T,i=0,j=0,k=0,g=0;
    char a[505];
    scanf("%d",&T);
    getchar();
    for(i=0;i<T;i++)
    {
        char b[500][50]={0},**c;
        int d[500]={0},e[500]={0};
        int l=0;
        int h=0,n=0,m=0,q=0,w=0,t=0;
        gets(a);
        int v=0;
        l=strlen(a);
        for(j=0;j<l;j++)
        {


                if(a[j]==','||a[j]=='.'||a[j]=='!'||a[j]=='?'||isspace(a[j]))
                {
                    for(k=v,g=0;k<=j;k++,g++)
                    {
                        b[t][g]=a[k];
                    }
                    d[t]=k;
                    v=j+1;
                    t=t+1;
                }
                 else if(j==l-1&&((a[l-1]>='a'&&a[l-1]<='z')||(a[l-1]>='A'&&a[l-1]<='Z')))
                {
                    for(k=v,g=0;k<=j;k++,g++)
                    {
                        b[t][g]=a[k];
                    }
                    d[t]=k;
                    v=j+1;
                    t=t+1;
                }
        }

        m=0;
        c=(char**)malloc(500*sizeof(char*));
        for(n=0;n<50;n++)
            c[n]=(char*)malloc(50*sizeof(char));
        for(n=0;n<d[0];n++)
            c[0][n]=b[0][n];
        for(h=1;h<t;h++)
        {

            if(strcmp(b[h],b[h-1])!=0)
            {
                for(n=0;n<d[h];n++)
                {
                   c[m][n]=b[h][n];
                   e[m]=n;
                }
                m++;
            }
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
    int T,i=0,j=0,k=0,g=0;
    char a[505];
    scanf("%d",&T);
    getchar();
    for(i=0;i<T;i++)
    {
        char b[500][50]={0},**c;
        int d[500]={0},e[500]={0};
        int l=0;
        int h=0,n=0,m=0,q=0,w=0,t=0;
        gets(a);
        int v=0;
        l=strlen(a);
        for(j=0;j<l;j++)
        {


                if(a[j]==','||a[j]=='.'||a[j]=='!'||a[j]=='?'||isspace(a[j]))
                {
                    for(k=v,g=0;k<=j;k++,g++)
                    {
                        b[t][g]=a[k];
                    }
                    d[t]=k;
                    v=j+1;
                    t=t+1;
                }
                 else if(j==l-1&&((a[l-1]>='a'&&a[l-1]<='z')||(a[l-1]>='A'&&a[l-1]<='Z')))
                {
                    for(k=v,g=0;k<=j;k++,g++)
                    {
                        b[t][g]=a[k];
                    }
                    d[t]=k;
                    v=j+1;
                    t=t+1;
                }
        }

        m=0;
        c=(char**)malloc(500*sizeof(char*));
        for(n=0;n<50;n++)
            c[n]=(char*)malloc(50*sizeof(char));
        for(n=0;n<d[0];n++)
            c[0][n]=b[0][n];
        for(h=1;h<t;h++)
        {

            if(strcmp(b[h],b[h-1])!=0)
            {
                for(n=0;n<d[h];n++)
                {
                   c[m][n]=b[h][n];
                   e[m]=n;
                }
                m++;
            }
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

    }


}

3
ask not what your country can do for you,ask what you can do for your country.
no enthusiasm forever,no unexpected happening of surprising and pleasing so,only silently ask myself in mind next happiness,when will come?
let us go! let us go!a things.
