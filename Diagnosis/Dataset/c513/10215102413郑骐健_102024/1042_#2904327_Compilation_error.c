#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 256

int cmp(int *p,int n)
{
    for(int i=0;i<N-n;i++)
    {
        if(p[i]>0)return i;
        else return -1;
    }
}
int main()
{
    int s[N];
    memset(s,0,256);
    int n;
    scanf("%d",&n);
    for(int i =0;i<n;i++)
    {
    int n =0;
    char c;
    while((c = getchar())!='\n')
        {
            if(s[c]==0)n++;
            s[c]++;
        }
    for(int i=0;i<n;i++)
        
    }
    
    return 0;
}
