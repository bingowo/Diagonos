#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*void read(char s[],long long a,long long b)
{
long long sign1 = 1,sign2 = 1;
    int i,k = 0;
    int len = strlen(s);
    if(s[0] == '-')sign1 = -1,k = 1;
    for(i = k,a = 0; i < len && isdigit(s[i]);i++)a = a*10 + s[i]-'0';
    a *= sign1;
    if(s[i] == 'i'&& a)b = a,a = 0;
    else if(s[i] == 'i' && a == 0)b = 1*sign1,a = 0;
    else if(s[i] == '+')sign2 = 1;
    else if(s[i] == '-')sign2 = -1;
    if(s[i+1] == 'i')b = 1;
    else
      {
        for(i += 1; i < len; i++)b = b*10 + s[i]-'0';
      }
    if(!a)b *= sign2;
    printf("%lld %lld\n",a,b);
}*/

int main()
{
    char s[1007];
    long long a = 0,b = 0,qr,qi,ans[1007];
    long long sign1 = 1,sign2 = 1;
    int i,j,k = 0;
    scanf("%s",s);
    memset(ans,0,sizeof(ans));
    int len = strlen(s);
    if(s[0] == '-')sign1 = -1,k = 1;
    for(i = k,a = 0; i < len && isdigit(s[i]);i++)a = a*10 + s[i]-'0';
    a *= sign1;
    if(s[i] == 'i'&& a)b = a,a = 0;
    else if(s[i] == 'i' && a == 0)b = 1*sign1,a = 0;
    else if(s[i] == '+')sign2 = 1;
    else if(s[i] == '-')sign2 = -1;
    if(s[i+1] == 'i')b = 1;
    else
      {
        for(i += 1; i < len && isdigit(s[i]); i++)b = b*10 + s[i]-'0';
      }
    if(a != 0)b *= sign2;
    //read(s,a,b);
    if(abs(a%2) == abs(b%2))ans[0] = 0;
    else if(abs(a%2) != abs(b%2))ans[0] = 1;
    qr = (ans[0]+b-a)/2;qi = (ans[0]-a-b)/2;i = 1;
    while(qi||qr)
    {
        if(abs(qr%2) == abs(qi%2))ans[i] = 0;
        else if(abs(qr%2) != abs(qi%2))ans[i] = 1;
        a = qr;b = qi;
        qr = (ans[i]+b-a)/2;qi = (ans[i]-b-a)/2;
        i++;
    }
    for(j = i-1; j >= 0; j--)printf("%lld",ans[j]);
    return 0;
}
