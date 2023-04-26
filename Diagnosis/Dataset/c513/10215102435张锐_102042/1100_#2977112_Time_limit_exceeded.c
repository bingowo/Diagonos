#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[200];
    scanf("%s",s);
    int len=strlen(s);
    long long int n;
    scanf("%lld",&n);
    for(long long int i=0;i<n;i++)
    {
        long long int a,b;
        scanf("%lld%lld",&a,&b);
        long long int pa=0,pb=0;
        long long int num=0;
        for(int f=0;f<len;f++)
        {
            if(pa==a&&pb==b) {printf("Yes\n");break;}
            if(s[f]=='U') pb++;
            if(s[f]=='D') pb--;
            if(s[f]=='L') pa--;
            if(s[f]=='R') pa++;
            if(pa==a&&pb==b) {printf("Yes\n");break;}
            if(f==len-1) {f=-1;num++;}
            if(num==99) {printf("No\n");break;}
        }
    }
    return 0;
}
