#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
char s[36] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int solve1(char *a,int n)
{
    unsigned len = strlen(a);
    int re = 0;
    for(int i = 0;i < len;i++)
    {
        int res;
        char c = a[i];
        c = toupper(c);
        if(c >= 'A')
        {
            res = c-'A'+10;
        }
        else
            res = c-'0';
        int k = len-i-1;
        int res2 = (int)pow(n,k)*res;
        re += res2;
    }
    return re;
}
void solve(int num,int n)
{
    char p[100] = {0};
    int cnt = 0;
    if(num < 0)
    {
        printf("-");
        num = -num;
    }

    while(num)
    {
        p[cnt++] = s[num%n];
        num /= n;
    }
    for(int i = strlen(p)-1;i >= 0;i--)
    {
        printf("%c",p[i]);
    }
    printf("\n");
}

int main()
{
    int a,b;
    char l[1000] = {0};
    scanf("%d %s %d",&a,l,&b);
    solve(solve1(l,a),b);
    return 0;
}