#include <stdio.h>
#include <stdlib.h>
#define num 1000000007


int main()
{
    long long res = 1;
    char s[2000];
    scanf("%s",s);
    int len =strlen(s);
    if(len==1)printf("1");
    else
    {
        for(int i=0;i<len;i++)
        {
            long long int mid = 1;
            if(i==0)
            {
                if(s[i]!=s[i+1])mid++;
            }
            else if(i==len-1)
            {
                if(s[i]!=s[i-1])mid++;
            }
            else
            {
                if(s[i]!=s[i-1])mid++;
                if(s[i]!=s[i+1])mid++;
                if(s[i-1]==s[i+1]&&mid==3)mid-=1;
            }
            res*=mid;
            res%=num;
        }
        printf("%lld",res);
    }
    return 0;
}
