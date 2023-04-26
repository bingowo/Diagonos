#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char prime[10][6]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};

int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int *)b;
}

int trans(int out[],int *d[],int c[],int i)
{
    int e[26];
    int flag=-1,j,k=0;
    for(j=0;j<26;j++)e[j]=c[j];
        while(flag==-1)
        {
            flag=0;
            for(int i1=i;i1<10;i1++)
            {
                for(j=0;j<26;j++)
                    if(e[j]<d[i1][j])break;
                if(j>=26)
                {
                    flag=-1;
                   for(j=0;j<26;j++)e[j]-=d[i1][j];
                   out[k++]=i1;
                }
            }
        for(j=0;j<26;j++)if(e[j]>0)k=-1;
        return k;
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
            int out[26],k;
        i=0;
        int trans(int out[],int d[][],int c[],int i);
        k=trans(out[26],d[10][26],c[26],i);
        i++;
        while(k==-1){k=trans(out[26],d[10][26],c[26],i);i++}
        qsort(out,k,sizeof(out[0]),cmp);
        for(j=0;j<k;j++)printf("%d",out[j]);
        printf("\n");
    }
}
