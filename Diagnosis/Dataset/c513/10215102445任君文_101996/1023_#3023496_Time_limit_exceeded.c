#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 100
void swap(int* b, int* a)
{
    int temp=*b;
    *b=*a;
    *a=temp;
}
int main()
{
    int n=1;
    char c;
    int i,L,j,t,a=0,b=0;
    int p[M]={0},num[M]={0},f[M]={0},pn[M]={0},py[M]={0};
    char str[M][31]={0};
    scanf("%s",str[0]);
    while((c=getchar())!='\n')
    {
        scanf("%s",str[n]);
        p[n]=n;
        n++;
    }
    if(n==1)
        printf("%s\n",str[0]);
    else
    {
        for(i=0;i<n;i++)
        {
            L=strlen(str[i]);
            for(j=0;j<L;j++)
            {
                if(('0'<=str[i][j])&&(str[i][j]<='9'))
                {
                    f[i]=1;
                    py[a]=i;
                    a++;
                    t=str[i][j]-'0';
                    num[i]=num[i]*10+t;
                }
            }
            if(f[i]!=1)
            {
                pn[b]=i;
                b++;
            }
        }
        for(i=0;i<b-1;i++)
        {
            for(j=b-1;j>0;j++)
            {
                if(strcmp(str[pn[j]],str[pn[j-1]])<0)
                    swap(&pn[j],&pn[j-1]);
            }
        }
        for(i=0;i<a-1;i++)
        {
            for(j=a-1;j>0;j++)
            {
                if(num[py[j]]<num[py[j-1]])
                    swap(&py[j],&py[j-1]);
                else if(num[py[j]]==num[py[j-1]])
                {
                    if(strcmp(str[py[j]],str[py[j-1]])<0)
                    swap(&py[j],&py[j-1]);
                }
            }
        }
        for(i=0;i<b;i++)
        {
            printf("%s ",str[pn[i]]);
        }
        for(i=0;i<a;i++)
        {
            printf("%s ",str[py[i]]);
        }
        printf("\n");
    }
    return 0;
}