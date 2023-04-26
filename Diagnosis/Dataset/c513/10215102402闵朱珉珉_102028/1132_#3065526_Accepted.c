#include <stdio.h>
#include <string.h>
char q[40]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void change(long long n,long long r,char *answer)
{
    char ans[15]={0};
    int i=0,j=0;
    long long t=0,tt=0;
    do
    {
        t+=n%r;
        n=n/r;
    }while (n);
    do
    {
        tt=t%r;
        t=t/r;
        answer[j++]=q[tt];
    }while (t);
}
int main()
{
    int T;
    scanf("%d",&T);
    for (int cas=0;cas<T;cas++)
    {
        printf("case #%d:\n",cas);
        long long n,r;
        scanf("%lld %lld",&n,&r);
        char answer[100]={0};
        change(n,r,answer);
        for (int i=strlen(answer)-1;i>=0;i--)
        {
            printf("%c",answer[i]);
        }
        printf("\n");

    }
    return 0;
}
