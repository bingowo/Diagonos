#include <stdio.h>
#include <string.h>
int main()
{
    int orin,res;//orin为原始进制，res为改后进制
    char a[11111];//存贮原始数字
    scanf("%d",&orin);
    scanf("%s",a);
    scanf("%d",res);
    
    //原始转换为十进制
    int x = 0;//十进制数
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] < 10)//如果是0到9
        {
            x = x + orin * a[i];
        }
        else //如果是十及以上
        {
            x = x + orin * (tolower(a[i]) - 'a' + 10);
        }
    }
    
    //十进制转换为res进制数
    int ans[1111];//储存答案数组
    int i;
    for (i = 0; x > 0; i++, x /= res)
    {
        int n = x % res;
        if (n < 10)//如果该数在0到9
        {
            ans[i] = n;
        }
        else //需要字母表示
        {
           ans[i] = n - 10 + 'A'; 
        }
    }
    
    for (int j = 0; j < i; j++)
    {
        printf("%c",ans[j]);
    }
    return 0;
}