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
    char arr[500];
    int num[10];
    scanf("%s",arr);
    int len=strlen(arr);
    printf("0001");
    binary(num,len,10)；
    printf("%s",num);
    for(int i=0;i<len/3;i++)
    {
        
    }
    return 0;
}