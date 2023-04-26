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
        int d[500]={0};
        int l=0,u=0;
        int h=0,n=0,m=0,q=0,w=0,t=0,y=0;
        gets(a);
        int v=0;
        l=strlen(a);
        for(j=0;j<l;j++)
        {
         
                 if(a[j]==','||a[j]=='.'||a[j]=='!'||a[j]=='?'||isspace(a[j]))
                {
                    if((a[j+1]>='a'&&a[j+1]<='z')||(a[j+1]>='A'&&a[j+1]<='Z'))
                    {
                         for(k=v,g=0;k<j;k++,g++)
                        {
                           b[t][g]=a[k];
                        }
                        d[t]=k-v;
                        v=j+1;
                        t=t+1;
                    }
                    else if(isspace(a[j+1]))
                    {
                        for(k=v,g=0;k<j;k++,g++)
                        {
                           b[t][g]=a[k];
                        }
                        d[t]=k-v;
                        v=j+2;
                        t=t+1;
                    }
                }
                 else if(j==l-1&&((a[l-1]>='a'&&a[l-1]<='z')||(a[l-1]>='A'&&a[l-1]<='Z')))
                {
                    for(k=v,g=0;k<=j;k++,g++)
                    {
                        b[t][g]=a[k];
                    }
                    d[t]=k-v;
                    v=j+1;
                    t=t+1;
                }
        }

        m=0;
        c=(char**)malloc(500*sizeof(char*));
        for(n=0;n<100;n++)
            c[n]=(char*)malloc(50*sizeof(char));
        for(n=0;n<d[0];n++)
            {
                c[0][n]=b[0][n];

            }
        m=1;
        for(h=1;h<t;h++)
        {
            y=0;
            for(u=h-1;u>=0;u--)
            {
                if(strcmp(b[h],b[u])!=0) y++;
            }
            if(y==h)
            {
                for(n=0;n<d[h];n++)
                {
                   c[m][n]=b[h][n];

                }
                m++;
            }
        }
        qsort(c,m,sizeof(c[0]),cmp);
        printf("case #%d:\n",i);
        for(q=0;q<m-1;q++)
        {
            for(w=0;w<strlen(c[q]);w++)
            {
                printf("%c",c[q][w]);

            }
            printf(" ");
        }
        for(w=0;w<strlen(c[m-1]);w++)
           printf("%c",c[m-1][w]);
        printf("\n");

    }


}