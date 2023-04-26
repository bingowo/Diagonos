#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int rtoi(char s)
{
    int ans=0;
    switch(s)
    {
    case 'I':
    ans = 1 ; break;
    case 'V':
    ans = 5 ; break;
    case 'X':
    ans = 10 ; break;
    case 'L':
    ans = 50 ; break;
    case 'C':
    ans = 100 ; break;
    case 'D':
    ans = 500 ; break;
    case 'M':
    ans = 1000 ; break;
    case '(':
    ans = -1 ; break;
    case ')':
    ans = 0 ; break;
    }
    return ans;
}

int main()
{
    char s[50];
    scanf("%s",s);
    int len = strlen(s) , i = 0 , flag = 0;
    long long sum = 0;
    int count=0,p=0;
    for(; i < len ; i++)
    {
        p=0;
        while(rtoi(s[i]) == -1)
        {
            i++;
            flag++;
            count++;
            p++;
        }
        while(rtoi(s[i])!= 0)
        {
            if(rtoi(s[i + 1]) == -1)
                {sum -= rtoi(s[i]);break;}
                if(p!=0)
                {
                    int j=i;
                    long long sum1=0;
                    while(rtoi(s[j])!=0)
                {
                    if(rtoi(s[j]) >= rtoi(s[j + 1]))
                    sum1 += rtoi(s[j]);
                    else
                    sum1 -= rtoi(s[j]);
                    j++;
                }
                sum1*=pow(1000,flag);
                sum+=sum1;i=j;break;
                }
                if(count==0)
                {
                    while(rtoi(s[i]) != 0)
                    {
                        if(rtoi(s[i]) >= rtoi(s[i + 1]))
                        sum += rtoi(s[i]);
                        else
                        sum -= rtoi(s[i]);
                        i++;
                    }
                }
           }
     flag = 0;
    }
printf("%lld",sum);
return 0;
}
