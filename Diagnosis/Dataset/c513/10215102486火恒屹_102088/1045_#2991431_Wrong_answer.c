#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 1001
char order[101]={'\0'};
int num[N][101]={0};
int cmp(const void *a,const void *b)
{
    int x=*(int*)a;
    int y=*(int*)b;
    return x>y? 1:-1;
}
void define_order(char s[])
{
    int i=1;
    order[0]=s[0];
    int j=1;
    while(j<strlen(s))
    {
        while(s[j]==s[j-1])
            j++;
        order[i]=s[j];
        i++;
        j++;
    }
}

void count(char s[],int i)
{
    int j=1;
    num[i][0]=1;
    int k=0;
    while(j<strlen(s))
    {
        if(s[j]==s[j-1]) num[i][k]++;
        else{k++;num[i][k]++;}
        j++;
    }
}

int cmp_order(char s[])
{
    if(s[0]!=order[0]) return 0;
    else
    {
        int i=1;
        int j=1;
        while(j<strlen(s))
        {
            while(s[j]==s[j-1]) j++;
            if(j==strlen(s)) return 1;
            if(s[j]!=order[i]) return 0;
            j++;
            i++;
        }
        return 1;
    }
}

int main()
{
    int n;
    long long res=0;
    scanf("%d",&n);
    char s[101]={'\0'};
    scanf("%s",&s);
    define_order(s);
    count(s,0);
    for(int i=1;i<n;i++)
    {
        scanf("%s",&s);
        if(cmp_order(s)==0) res=-1;
        else count(s,i);
    }
    if(res==-1) {printf("-1");return 0;}
    for(int i=0;i<strlen(order);i++)
    {
        int kazu[N]={0};
        for(int j=0;j<n;j++)
            kazu[j]=num[j][i];
        qsort(kazu,n,sizeof(int),cmp);
        int median;
        if(n%2!=0) median=kazu[(n-1)/2];
        else median=(kazu[n/2]+kazu[n/2-1])/2;
        for(int j=0;j<n;j++)
            res+=abs(kazu[j]-median);
    }
    printf("%lld",res);
    return 0;
}
