#include <stdio.h>
#include <string.h>
void trans(int a,int *b,int n)
{
    int i;
    for(i = 7;i>=0;i--)
    {
        b[n+i] = a%2;
        a /= 2;
    }

}
int main()
{
    int T,i,j;
    scanf("%d",&T);
    char b[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    for(i = 0;i<T;i++)
    {
        char s[101],ans[100];
        scanf("%s",s);
        int a[800]={0},n,m = 0,k,p = 0;
        for(j = 0;j<strlen(s);j++)
        {
            n = (int)s[j];
            trans(n,a,8*j);
        }
        if(strlen(s)*8%6!=0) m = 6-(strlen(s)*8%6);
        for(j = 0;j<(strlen(s)*8+m)/6;j++)
        {
            int res = 0;
            for(k = 0;k<6;k++)
                res = res*2 + a[j*6+k];
            ans[p++] = b[res];
        }
        while(p%4!=0)
        {
            ans[p++] = '=';
        }
        ans[p] = '\0';
        printf("case #%d:\n%s\n",i,ans);
    }
    return 0;
}
