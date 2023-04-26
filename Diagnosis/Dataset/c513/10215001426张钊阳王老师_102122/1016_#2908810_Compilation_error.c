
#include <stdio.h>
char ans[25];
int num[25];
 
void Change(int j)
{
    int i;
    for(i = 0;i < j;i++)
    {
        if(num[i] >= 0 && num[i] <= 9)
            ans[i] = num[i] + '0';
        else
            ans[i] = num[i] - 10 + 'A';
    }
}
 
int main()
{
    int n,r;
    scanf("%d%d",&n,&r);
    
    printf("%d=",n);
    int i = 0;
    while(n)
    {
        if(n%r < 0)
        {
            num[i] = n%r - r;
            n = n/r + 1;
        }
        else
        {
            num[i] = n%r;
            n /= r;
        }
        i++;
    }
    Change(i);
        
    for(int j = i-1;j >= 0;--j)
    {
        printf("%c",ans[j]);
    }
    printf("(base%d)",r);
    
	return 0;

————————————————
版权声明：本文为CSDN博主「天笙月」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/m0_61465701/article/details/122893999