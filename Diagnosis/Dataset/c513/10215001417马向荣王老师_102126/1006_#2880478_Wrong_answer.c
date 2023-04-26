#include<stdio.h>
#include<math.h>
#include<string.h>
int main(void)
{
    int n=0;
    scanf("%d\n",&n);
    int arr[20]={0};
    arr['0']=0;
    arr['1']=1;
    arr['-']=-1;
    for(int i = 0; i < n; i++)
    {
        printf("case #%d:\n",i);
        char s[100];//存放每个数字
        scanf("%s",s);
        int len=strlen(s);
        int num = 0;
        for(int j=0;j<len;j++)
        {
            num=num*3+arr[s[j]];
        }
        printf("%d\n",num);
    }
    return 0;
}