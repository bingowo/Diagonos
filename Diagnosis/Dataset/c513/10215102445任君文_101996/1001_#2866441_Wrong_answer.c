#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char trans(int N,int R)
{
    int s,k=1;
    char res;
    char S[]="-0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if(N<0)
        {
            k=-1;
            N=-N;
        }
    while(N>0)
        {
            s=N%R;
            N=N/R;
            res=S[s+1]+res;
        }
        if(k==-1)
            res=S[0]+res;
    return res;
}
int main()
{
    int a,i,n[100],r[100];
    char res;
    scanf("%d",&a);
    for(i=0;i<a;i++)
        {
            scanf("%d %d",&n[i],&r[i]);
        }
    for(i=0;i<a;i++)
        {

            res=trans(n[i],r[i]);
            printf("%d\n",res);
        }

    return 0;
}