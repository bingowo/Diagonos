#include <stdio.h>
#define N 40 
int prime[]=
{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int p[25][N]={0};
int d[N]={0};
int input(int (*p)[N])
{
    int i = 0,n;
    char c;
    do
    scanf("%d%c",&p[i++][N-1],&c);
    while(c==',');
    return i;
}
void mult_n(int a[],int n)
{
    int i;
    for(i=N-1;i>0;i--) a[i]*=n;
    for(i=N-1;i>0;i--)
    {
        a[i-1] += a[i]/10;
        a[i]%=10;
    }
}
void add(int a[],int b[]) //a+=b
{
    int i;
    for(i=N-1;i>0;i--)
    {
        a[i] += b[i];
        a[i-1] += a[i]/10;
        a[i] %= 10;
    }
}
void output(int a[])
{
    int i;
    while(i<N && a[i]==0) i++;
    if(i>=N)
    { printf("0\n"); return;}
    while(i<N)
    printf("%d",a[i++]);
    printf("\n");
}

int main()
{
    int p[25][N]={0};
    int d[N]={0};
    int num = input(p);
    int i,j;
    for(i=0;i<num;i++)
    {
        for(j=0;j<num-i-1;j++) mult_n(p[i],prime[j]);
        add(d,p[i]);
    }
    output(d);
    return 0;
}