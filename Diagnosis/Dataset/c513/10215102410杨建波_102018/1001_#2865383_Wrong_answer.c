#include<stdio.h>
int main()
{
    int T,N,R;
    int rem,i = 0,m,t;
    scanf("%d",&T);
    for(int n = 0;n<T;n++)
    {
        scanf("%d %d",&N,&R);
        char c[100];
        rem = R;
    while(rem >= R){
    rem = N % R; 
    if(rem >= 10)
    {
        t = rem -10 ;
        c[i] = 'A'+t;
    }
    else
    {
        c[i] = '0'+rem;
    }
    N = N / R;
    i++;
    }
    i--;
    for(i;i >= 0;i--)
    {
       printf("%c",c[i]); 
    }
    }
}