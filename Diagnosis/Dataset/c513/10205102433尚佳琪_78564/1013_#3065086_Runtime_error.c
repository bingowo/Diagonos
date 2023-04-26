#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int gcd(int a,int b)
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
    int i=0,num=0,sum=0;
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
    if(len2==0)
        printf("%d",sum);
    else
    {
        int fm=pow(3,len2),num2=0,sum2=0;
        for(int j=len-1;j>i;j--)
        {
            if (s[j] == '2')
                num2 = -1;
            else
                num2 = s[j] - '0' ;
            sum2 = sum2 * 3 + num2;
        }
        //printf("%d",sum2);
        int tmp=gcd(abs(sum2),fm);
        if(sum>0&&sum2>0)
            printf("%d %d %d",sum,sum2/tmp,fm/tmp);
        else if(sum==0&&sum2>0)
           printf("%d %d",sum2/tmp,fm/tmp);
        else if(sum==0&&sum2<0)
           printf("%d %d",sum2/tmp,fm/tmp);
        else if(sum<0&&sum2<0)
            printf("%d %d %d",sum,-sum2/tmp,fm/tmp);
        else if(sum>0&&sum2<0)
            printf("%d %d %d",sum-1,fm/tmp+sum2/tmp,fm/tmp);
        else if(sum<0&&sum2>0)
            printf("%d %d %d",sum+1,fm/tmp-sum2/tmp,fm/tmp);
    }
    //printf("Hello world!\n");
    return 0;
}
