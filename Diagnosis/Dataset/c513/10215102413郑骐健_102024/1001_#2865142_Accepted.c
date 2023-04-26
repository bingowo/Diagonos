#include <stdio.h>

char s[36];
char D[32];
int point = 0;
void push(char a)
{
    D[point ++] = a;
}
void clean()
{
    while(!(point < 0 ))
    {
        printf("%c",D[--point]);
    }
    printf("\n");
}
int main()
{
    int i;
    for( i =0;i<10;i++)
    {
        s[i] = '0'+i;
    }
    for (i = 10;i<36;i++)
    {
        s[i] = 'A'+i-10;
    }
    int num;
    scanf("%d",&num);
    for(int j =0;j<num;j++)
    {
        long long int N;int R;
        scanf("%lld%d",&N,&R);
        if(N<0)
        {
            printf("-");
            N*=-1;
        }
    while(N>0)
    {
        push(s[N%R]);
        N = N/R;
    }
    clean();
    }
    return 0;

}
