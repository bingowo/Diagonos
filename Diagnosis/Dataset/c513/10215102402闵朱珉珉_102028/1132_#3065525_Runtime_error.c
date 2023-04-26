#include <stdio.h>
#include <string.h>
char q[40]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void change(int n,int r,char *answer)
{
    char ans[15]={0};
    int i=0,j=0,t=0,tt=0;
    do
    {
        ans[i++]=q[n%r];
        n=n/r;
    }while (n);
    for (int i=0;i<strlen(ans);i++)
    {
        if (ans[i]<='9'&&ans[i]>='0')
            t+=ans[i]-'0';
        else
            t+=ans[i]-'A';
    }
    do
    {
        answer[j++]=q[t%r];
        t=t/r;
    }while (t);
}
int main()
{
    int T;
    scanf("%d",&T);
    for (int cas=0;cas<T;cas++)
    {
        printf("case #%d:\n",cas);
        int n,r;
        scanf("%d %d",&n,&r);
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
