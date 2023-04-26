#include<stdio.h>
#include<string.h>
void binary(char *s,int len,int n)//500-111110100-9
{
    int i=0;
    for(i=n-1;i>=0;i--)
    {
        s[i]=len%2;
        len/=2;
    }
    s[n]='\0';
}
int main(void)
{
    char arr[500];//input
    int num[10];//二进制
    scanf("%s",arr);
    int len=strlen(arr);
    printf("0001");
    binary(num,len,10);
    printf("%s",num);
    int i,j,t=0;
    for(i=0;i<len/3;i++)//分份
    {
        for(j=i*3;j<i*3+2;j++)//转成数字
        {
            t=t*10+arr[j];
        }
        binary(num,t,10);
        printf("%s",num);
        t=0;
    }
    if(len%3)
    {
        for(j=i*3;j<=len-1;j++)
        {
            t=t*10+arr[j];
        }
        int nums[(len%3)*3+3];
        binary(nums,t,(len%3)*3+1);
        printf("%s",nums);
    }
    return 0;
}