#include<stdio.h>
char s[36]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
void tranf(int n,int r)
{
    if(n>=r)
    tranf(n/r,r);
    printf("%c",s[n%r]);

}
int main()
{
    int n,r,T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        while(~scanf("%d %d",&n,&r))
    {
        if(n<0)
        {
            printf("-");
            n=-n;
        }
        tranf(n,r);
        printf("\n");

    }
    }
    return 0;
}