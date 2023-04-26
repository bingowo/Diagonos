#include <stdio.h>

char lmax[10][31];
int i;

void d2b(int n,int i)
{
    int j= 0;
    if(n/2) d2b(n/2,i);
    lmax[i][j++]= n%2;
}

int count(char lmax[i][31])
{
    int countor= 0;
    for(int j= 0; lmax[i][j]; j++)
        if(lmax[i][j] != lmax[i][j+1]) countor+=1;
    return countor;
}

int main()
{
    int T, n[10];
    scanf("%d",&T);
    for(i= 0; i<T; i++)
    {
        scanf("%d",&n[i]);
    }
    n[i]= 0;
    for(i=0; n[i]; i++)
    {
       d2b(n[i],i);
       printf("case #%d:\n%d\n",i,count(lmax[i]));
    }
    return 0;

}
