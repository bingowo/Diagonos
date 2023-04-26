#include<stdio.h>
#include<math.h>
#include<string.h>
int main(void)
{
    int n=0;
    scanf("%d\n",&n);
    for(int i = 0; i < n; i++)
    {
        printf("case #%d:\n",i);
        char s[100];//存放每个数字
        scanf("%s",s);
        s['0']=0;
        s['1']=1;
        s['-']=-1;
        int len=strlen(s);
        int num = 0;
        for(int j=0;j<len;j++)
        {
            num=num*3+s[j];
        }
        printf("%d\n",num);
    }
    return 0;
}