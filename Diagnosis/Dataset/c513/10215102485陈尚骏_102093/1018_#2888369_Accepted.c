#include <stdio.h>
#include <stdlib.h>
#define N 40

int p[25][N]={0};
int d[N]={0};

int primein(int(*p)[N])
{
    int i=0;
    char c;
    do{
        scanf("%d%c",&p[i++][N-1],&c);
    }while(c==',');
    return i;
}

void mult_P(int s[],int n)
{
    int i;
    for(i=N-1;i>0;i--)
            s[i]=s[i]*n;
    for(i=N-1;i>0;i--)
    {
        s[i-1]=s[i-1]+s[i]/10;
        s[i]=s[i]%10;
    }
}

void add_P(int s[],int t[])
{
    int i;
    for(i=N-1;i>0;i--)
    {
        s[i]=s[i]+t[i];
        s[i-1]=s[i-1]+s[i]/10;
        s[i]=s[i]%10;
    }
}

void outputd(int s[])
{
    int i=0;
    while(i<N&&s[i]==0) i++;
    if(i>=N){
        printf("0\n");
        return;
    }
    while(i<N)
        printf("%d",s[i++]);
    printf("\n");
}

int main()
{
    int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int num=primein(p);
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num-i-1;j++)
        {
            mult_P(p[i],prime[j]);
        }
        add_P(d,p[i]);
    }
    outputd(d);
    return 0;
}
