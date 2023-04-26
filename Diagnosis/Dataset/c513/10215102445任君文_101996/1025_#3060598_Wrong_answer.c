#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 102
void swap(int*a ,int*b)
{
    int temp =*a;
    *a=*b;
    *b=temp;
}
int main()
{
    char s[N][25]={0};
    int i,j,k;
    int T,n,temp;
    int L=0;
    int diff_num[N]={0};
    int alp[28]={0};
    int p[N]={0};
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%s",s[j]);
            L=strlen(s[j]);
            p[j]=j;
            for(k=0;k<L;k++)
            {
                temp=s[j][k]-'A';
                alp[temp]=1;
            }
            for(k=0;k<28;k++)
            {
                diff_num[j]=diff_num[j]+alp[k];
                alp[k]=0;
            }
        }
        for(j=0;j<n-1;j++)
        {
            for(k=0;k<n-1-j;k++)
            {
                if(diff_num[p[k]]<diff_num[p[k+1]])
                {
                    swap(&p[k],&p[k+1]);
                }
                else if(diff_num[p[k]] == diff_num[p[k+1]])
                {
                    if(strcmp(s[p[k]],s[p[k+1]])>0)
                    {
                        swap(&p[k],&p[k+1]);
                    }
                }
            }
        }
        printf("case #%d:\n",i);
        for(j=0;j<n;j++)
        {
            printf("%s\n",s[p[j]]);
        }
    }
    return 0;
}