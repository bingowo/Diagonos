#include<stdio.h>
#include<string.h>

int max(int a,int b)
{
    if(a>b)
        return a;
    else 
        return b;
}

int main()
{
    char s[55];
    scanf("%s",s);
    
    int cnt[55];
    cnt[0] = 1;
    int maxn = 1;
    for(int i=1;i < strlen(s);i++)
    {
        if(s[i] != s[i-1]) //和前面的不相等
        {
            cnt[i] = cnt[i-1] + 1;
            maxn = max(cnt[i],maxn);  //max函数
        }
        else
            cnt[i] = 1;
    }
    printf("%d",maxn);
    return 0;
}