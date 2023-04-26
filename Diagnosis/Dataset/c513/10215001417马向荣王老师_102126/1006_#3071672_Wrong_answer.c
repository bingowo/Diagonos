#include<stdio.h>
#include<string.h>
int main(void)
{
    int t=0;
    scanf("%d\n",&t);
    for(int i = 0; i < t; i++)
    {
        char s[100];//存放每个数字
        scanf("%s",s);
        int len=strlen(s);
        int num=0;
        for(int j=len;j>0;j--)
        {
            if(s[j]=='-') s[j]=-1;
            num=num*3+s[j];
        }
        printf("case #%d:\n",i);
        printf("%d\n",num);
    }
    return 0;
}