#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Readnumber(char x[],int y[])
{
    int index = 25,n=1;
    for(int i=strlen(x)-1; i>=0; i--)
    {
        if(x[i]>='0' && x[i]<='9')
        {
            y[index] += (x[i]-'0')*n;
            n*=10;
        }
        else
        {
            index--;
            n=1;
        }
    }
}
void ADD(int a[],int b[],int c[])
{
    int prime[25]= {97,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
    int x=0;
    for(int i = 25; i>=1; i--)
    {
        c[i]=(a[i]+b[i]+x)%prime[i-1];
        x = (a[i]+b[i]+x)/prime[i-1];
    }
    c[0] = x;
}
int main()
{
    int prime[25]= {97,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
    char s[100];
    scanf("%s",s);
    int t[26] = {0},index = 25,n = 1;;
    for(int i = strlen(s)-1; i >= 0; i--)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            t[index] += (s[i]-'0')*n;
            n *= 10;
        }
        else
        {
            index--;
            n = 1;
        }
    }
    long long ans = 0;
    for(int i = index;i <= 25;i++){
        ans = ans * prime[i - 1] +t[i];
    }
    printf("%lld",ans);
    return 0;

}
