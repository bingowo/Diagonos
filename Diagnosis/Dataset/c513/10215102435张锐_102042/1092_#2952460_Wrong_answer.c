#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int f(int i,int num,int len)
{
    if((i==1||i==num)&&len==0) return 0;
    if(i!=1&&i!=num&&len==0) return 3;
    len--;
    if(i==1&&len!=0) return f(i,num,len)+f(i+1,num,len);
    if(i!=1&&i!=num) return f(i-1,num,len)+f(i,num,len)+f(i+1,num,len);
    if(i==num) return f(i-1,num,len)+f(i,num,len);
}
int main()
{
    char s[1000];
    scanf("%s",s);
    int len=strlen(s);int num=1;
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(j==i-1&&s[j]!=s[i]) num++;
        }
    }
    int sum=1;
    for(int i=1;i<num&&i<3;i++)
    {
        sum+=f(i,num,len-1);
    }
    printf("%d\n",sum);
    return 0;
}
