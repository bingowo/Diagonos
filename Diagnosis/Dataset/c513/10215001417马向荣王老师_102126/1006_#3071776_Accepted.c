#include<stdio.h>
#include<string.h>
int main(void)
{
    int t=0;
    scanf("%d\n",&t);
    for(int i = 0; i < t; i++)
    {
        char s[1000];
        scanf("%s",s);
        int j=0,num=0;
        for(j=0;j<strlen(s);j++)
        {
            num*=3;
            if(s[j]=='-') num-=1;
            if(s[j]=='1') num+=1;
        }
        printf("case #%d:\n",i);
        printf("%d\n",num);
    }
    return 0;
}