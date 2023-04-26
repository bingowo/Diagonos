#include <stdio.h>
#include <stdlib.h>

char transform(x)
{
    if(x<10)
    {
        return x+'0';
    }
    if(x>=10)
    {
        return x-10+'A';
    }
}
int main()
{
    int T,N,R;
    char r[32];
    int i=0;
    scanf("%d",&T);
    while(T>0)
    {
        T--;
        scanf("%d %d",&N,&R);
        if(N<0)
        {
            N=-N;
            printf("-");
        }
        do{
            r[i]=transform(N%R);
            N=N/R;
            i++;
        }while(N>0);
        i=0;
        printf("%s\n",r);
    }
    return 0;
}
