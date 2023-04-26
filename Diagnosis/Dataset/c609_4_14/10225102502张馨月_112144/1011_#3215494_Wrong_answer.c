#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[100];
    scanf("%s",&s);
    int k=0;
    int len=strlen(s);
    for(k=0;k<len&&s[k]!='.';k++);
    //k是小数点前的数字总数
    int res=0;
    for(int i=0;i<k;i++)
    {   if(s[i]=='2')
            res=res*3-1;
        else
            res=res*3+s[i]-'0';
    }

    //解决小数点后的
    
    printf("%d",res);
    return 0;
}
