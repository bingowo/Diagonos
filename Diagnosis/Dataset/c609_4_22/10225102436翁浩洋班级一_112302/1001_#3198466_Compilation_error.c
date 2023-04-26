#include <stdio.h>
int main()
{
    unsigned int T;
    int N,R,a,b;
    char m[33]={};
    char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%d",&T);
    for (int i=0;i<T;i++)
        {
            scanf("%d%d",&N,&R);
            do
            {
            a=N/R;
            b=N%R;
            strcat(m,table[b]);
            N=a;
            }while(N);
        }
    for(int k=sizeof(m);k>=0;k--)
        {
        printf("%c",m[k]);
        }
    return 0;