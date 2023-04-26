#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char prime[10][6]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};

int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int *)b;
}

int main()
{
    int T,j;scanf("%d",&T);
    int d[10][26]={0};
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<strlen(prime[i]);j++)
        d[i][prime[i][j]-'A']++;
    }
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        char s[21];scanf("%s",s);
        int c[26]={0};
        for(int i=0;i<strlen(s);i++)
            c[s[i]-65]++;
        int flag=-1,out[7],k=0;
        while(flag==-1)
        {
            flag=0;
            for(int i=0;i<10;i++)
            {
                for(j=0;j<26;j++)
                    if(c[j]<d[i][j])break;
                if(j>=26)
                {
                    flag=-1;
                   for(j=0;j<26;j++)c[j]-=d[i][j];
                   out[k++]=i;
                }
            }

        }
        qsort(out,k,sizeof(out[0]),cmp);
        for(j=0;j<k;j++)printf("%d",out[j]);
        printf("\n");
        t++;
    }
}
