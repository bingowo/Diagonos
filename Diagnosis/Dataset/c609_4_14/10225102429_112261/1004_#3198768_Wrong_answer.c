#include <stdio.h>
#include <ctype.h>
#include <string.h>
int in(int In,char s[])
{
    char *sp = s;
    int sum = 0,pow = 1,len = strlen(s);
    for(int i = len-1; i>-1; i--)
    {
        if(isdigit(s[i])) sum+=pow*(s[i]-'0');
        if('a'<=s[i]&&s[i]<='z') sum+=pow*(s[i] - 'a'+10);
        if('A'<=s[i]&&s[i]<='Z') sum+=pow*(s[i]-'A'+10);
        pow*=In;
    }
    return sum;
}
void out(int n, int R, int *p)
{
    int i = 0;
    while(n)
    {
        p[i]=n%R;
        n/=R;
        i++;
    }
}
int main()
{
    int a[20],*p = a;
    for(int i = 0; i<20; i++) a[i] = -1;
    int In,Out; char s[20] = {0};
    scanf("%d%s%d",&In,s,&Out);
    int val = in(In, s);
    printf("%d\n",val);
    out(val,  Out, p);
    for(int i = 19; i>-1; i--)
    {
        if(a[i]==-1) continue;
        if(a[i]>9) printf("%c",'A'+a[i]-10);
        else printf("%d",a[i]);
    }
    return 0;
}