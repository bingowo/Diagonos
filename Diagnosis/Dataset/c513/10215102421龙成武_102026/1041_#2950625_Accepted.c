#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int temp,maxlen,i,j;
    char s[51];
    scanf("%s",s);
    temp=maxlen=1;
    for(i=0;i<strlen(s);i++)
    {
        temp=1;
        for(j=i;j<strlen(s)-1;j++)
        {
            if(s[j]!=s[j+1])
            {
                temp++;
            }
            else if(s[j]==s[j+1])
            {
                temp=1;
            }
            maxlen=maxlen<temp? temp:maxlen;        
            //如果把这句放到else里面，就有可能没法赋值了
            //所以不得已，只能牺牲一点性能
        }
    }
    printf("%d",maxlen);
    return 0;
}

