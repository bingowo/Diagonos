#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char s[51];
    int count=0;
    //scanf("%c",&s[0]);
    scanf("%s",&s);
    int i;
    int res=0;
    int j=strlen(s);
    for(i=0;i<j-1;i++)
    {
        if(s[i]!=s[i+1])
            count++;
        else count=0;
        if(count>res)
            res=count;

    }
    res++;

    //最后一个和它后面一个一样，但也要算进来，比如1-1-11有5个
    //要输出最大的count

    printf("%d",res);
    return 0;
}
