#include <stdio.h>
#include <string.h>
#define R 2333

void change(char s[],int num[])//将字符数组转化为整形数组
{
    num[0] = strlen(s);//首位存储字符串长度
    for(int i = 1; i <= strlen(s); i++)
    {
        if(s[i-1] >= '0' && s[i-1] <= '9')
        {
            num[i] = s[i-1] - '0';
        }
    }
}
void solve(int num[],int ans[],int end[])//再理解
{
    memset(end,0,sizeof(end));//该初始化不可少
    while(num[0] >= 1)
    {
        int y = 0;
        int i = 1;
        ans[0] = num[0];
        while(i <= num[0])
        {
            y = y * 10 + num[i];
            ans[i++] = y / R;
            y %= R;
        }
        end[++end[0]] = y;//存储结果
        i = 1;
        while((i<=ans[0]) && (ans[i]==0))
            i++;
        memset(num,0,sizeof(num));
        for(int j = i;j <= ans[0];j++)
            num[++num[0]] = ans[j];
        memset(ans,0,sizeof(ans));
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    char s[1000];
    int num[1000]={0};
    int ans[1000]={0},end[1000]={0};
    for(int z = 0; z < t; z++)
    {
        scanf("%s",s);
        change(s,num);
        solve(num,ans,end);
        for(int i = end[0];i >= 1;i--)
        {
            printf("%d ",end[i]);
        }
        printf("\n");
    }
    return 0;
}
