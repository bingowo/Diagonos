#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void solve(int a,int b)
{
    if(a<b)
    {
        if(a<10)
            printf("%d",a);
        else
            printf("%c",'A'-10+a);
        return;
    }
    solve(a/b,b);
    int tmp=a%b;
    if(tmp<10)
            printf("%d",tmp);
    else
            printf("%c",'A'-10+tmp);
    return;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T)
    {
        T--;
        int N,R;
        scanf("%d %d",&N,&R);
        if(N<0)
        {
            printf("-");
            N=-N;
        }
        solve(N,R);
        printf("\n");
    }
    return 0;
}
