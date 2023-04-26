#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    if(num==1) sum=1;
    if(num==2) sum=4;
    if(num==3) sum=12;
    else 
    {
        for(int i=0;i<num-3;i++)
        {
            sum=sum*3;
        }
        sum=sum*10;
    }
    printf("%d\n",sum);
    return 0;
}
