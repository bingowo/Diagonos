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
        printf("case #%d:\n",i);
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
                    for(k=v,g=0;k<=j;k++,g++)
                    {
                        b[t][g]=a[k];
                    }
                    d[t]=k-v-1;
                    v=j+1;
                    t=t+1;
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
        qsort(b,t,sizeof(b[0]),cmp);
        for(w=0;w<strlen(b[0]);w++)
           printf("%c",b[0][w]);
        for(h=1;h<t;h++)
        {
            y=0;
            for(u=h-1;u>=0;u--)
            {
                if(strcmp(b[h],b[u])!=0) y++;
            }
            if(y==h)
            {
                for(w=0;w<strlen(b[h]);w++)
                     printf("%c",b[h][w]);
                printf(" ");
            }
        }
       printf("\n");

    }


}
