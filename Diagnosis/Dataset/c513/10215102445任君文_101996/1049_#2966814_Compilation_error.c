#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define M 500
int main()
{
    int T;
    int f=0;
    int n,l;
    int L[M]={0};
    int i,j,k,temp;
    char s[M][50]={0};
    char c;
    char t;
    scanf("%d",&T);
    c=getchar();
    for(i=0;i<T;i++)
    {
        n=0;
        l=0;
        f=0;
        for(j=0;j<M;j++)
        {
            L[j]=0;
        }
        while((c=gethcar())!='\n')
        {
            if((c=='.')||(c==',')||(c=='!')||(c=='?')||(c==' '))
            {
                L[n]=l;
                n++;
                l=0;
            }
            else
            {
                s[n][l]=c-'a'+1;
                l++;
            }
        }
        f=0;
        for(j=0;j<n;j++)
        {
            for(k=0;k<L[n];k++)
            {
                ;
            }
        }
        
    }
    return 0;
}