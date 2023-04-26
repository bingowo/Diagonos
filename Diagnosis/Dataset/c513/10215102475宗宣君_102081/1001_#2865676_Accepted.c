#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int T,i,j,N[100],R[100],a[32],b,c;
    scanf("%d",&T);
    char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(i = 0;i<T;i++)
        scanf("%d%d",&N[i],&R[i]);
    for(j = 0;j<T;j++)
    {   b = 0;
    if(N[j]<0) printf("-");
        do
        {
            a[b] = abs(N[j])%R[j];N[j]= abs(N[j])/R[j];
            b++;
        }while(N[j]!=0);

        for(c = b-1;c>=0;c--)
        printf("%c",table[a[c]]);
        printf("\n");
    }
    return 0;
}
