#include <stdio.h>
#include <string.h>
#include <math.h>
typedef long long int ll;

int main()
{
    int i,t=0,T;
    scanf("%d\n",&T);
    while(t++<T)
    {
        char s[15];
        memset(s,0,sizeof(int));
        scanf("%s",s);
        s[strlen(s)+1]='\0';
        ll sum=0;
        for(i=strlen(s)-1;i>=0;i--)
        {
            if(s[i]=='1')
            {
                sum+=pow(3,strlen(s)-i-1);
            }
            if(s[i]=='-')
            {
                sum-=pow(3,strlen(s)-i-1);
            }
        }
        printf("case #%d:\n%lld\n",t-1,sum);
    }
}
