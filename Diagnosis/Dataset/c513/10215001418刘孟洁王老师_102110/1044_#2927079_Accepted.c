#include<stdio.h>
#include<string.h>


int main()
{
    char s[100001];
    int i,k,num;
    long long int ans[100001];
    scanf("%s",s);
    k = 0;
    for(i = 0; i < strlen(s); i++)
    {
        if(s[i] == '0'&&s[i+1] == 'x')
        {
            for(i += 2,num = 0;(s[i] >= '0'&&s[i] <= '9')||(s[i] >= 'a'&&s[i] <= 'f');i++)
            {
                if(s[i] >= '0'&&s[i] <= '9')num++/*记录是否有有效数据*/,ans[k] = ans[k]*16 + s[i]-'0';
                else if(s[i] >= 'a'&&s[i] <= 'f')num++,ans[k] = ans[k]*16 + s[i]-'a'+10;
            }
            if(num)k++;//如果有有效数据的话，就进行下一轮；
        }
    }
    if(k == 0)printf("-1");
    else {for(i = 0; i < k; i++)printf("%lld ",ans[i]);}
    return 0;
}
