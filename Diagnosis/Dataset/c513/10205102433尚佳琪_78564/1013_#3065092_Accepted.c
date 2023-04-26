#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
long long gcd(long long a,long long b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}
int main()
{
    char s[50];
    scanf("%s",s);
    int len=strlen(s);
    long long i=0,num=0,sum=0;
    for(i=0;i<len;i++)
    {
        if(s[i]=='.')break;
        if (s[i] == '2')
			num = -1;
		else
			num = s[i] - '0' ;
        sum = sum * 3 + num;
    }
    int len2=0;
    len2=len-i-1;
    if(len2==-1)
        printf("%lld",sum);
    else
    {
        long long fm=pow(3,len2),num2=0,sum2=0;
        for(int j=i+1;j<len;j++)
        {
            if (s[j] == '2')
                num2 = -1;
            else
                num2 = s[j] - '0' ;
            sum2 = sum2 * 3 + num2;
        }
        //printf("%d",sum2);
        long long tmp=gcd(abs(sum2),fm);
       // printf("%lld\n\n",sum2);
        if(sum>0&&sum2>0)
            printf("%lld %lld %lld",sum,sum2/tmp,fm/tmp);
        else if(sum==0&&sum2>0)
           printf("%lld %lld",sum2/tmp,fm/tmp);
        else if(sum==0&&sum2<0)
           printf("%lld %lld",sum2/tmp,fm/tmp);
        else if(sum<0&&sum2<0)
            printf("%lld %lld %lld",sum,-sum2/tmp,fm/tmp);
        else if(sum>0&&sum2<0)
            printf("%lld %lld %lld",sum-1,fm/tmp+sum2/tmp,fm/tmp);
        else if(sum<0&&sum2>0)
            printf("%lld %lld %lld",sum+1,fm/tmp-sum2/tmp,fm/tmp);
    }
    //printf("Hello world!\n");
    return 0;
}
