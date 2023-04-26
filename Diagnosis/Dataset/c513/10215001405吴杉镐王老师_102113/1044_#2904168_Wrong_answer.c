#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
    char s[100001]={'\0'};
    scanf("%s",s);
    int sum=0;
    int flag=0;
    int len=strlen(s);
    if(len<3)
    {
        printf("-1");
        return 0;
    }
    for(int i=2;i<len;i++)
    {
        if(s[i-2]=='0' && s[i-1]=='x')
        {
            flag=1;
            sum=0;
            for(;s[i]>='0' && s[i]<='9' || s[i]>='a' && s[i]<='f';i++)
            {
                if(s[i]>='0' && s[i]<='9')
                {
                    sum=sum*16+s[i]-'0';
                }
                else
                {
                    sum=sum*16+s[i]-'a'+10;
                }
            }
            if(sum)
                printf("%d ",sum);
        }
    }
    if(flag==0)
        printf("-1");
	return 0;
}
