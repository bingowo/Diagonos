#include<stdio.h>
void binary(int, int);

int main()
{
    int N, R;
    while(scanf("%d %d", &N, &R)!=EOF)
    {
        if(N==0)
            printf("%d",0);
        else if(N<0)
        {
            printf("-");
            N=-N;
        }
        binary(N, R);
        printf("\n");
    }
    return 0;
}

void binary(int n, int r)
{
    int m;
    if(n==0)
        return;
    else
    {
        binary(n/r, r);
        m=n%r;
        if(m<10)
            printf("%d", m);
        else
            printf("%c", 'A'+m-10);
    }
}

