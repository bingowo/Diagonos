#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 102
int main()
{
    char s[N][21]={0};
    int i,j,T,n,temp;
    int alp[26]={0};
    int diff_num[N]={0};
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%s",s[j]);
            printf("%s",s[j]);
        }
        printf("\n");
        
    }
}