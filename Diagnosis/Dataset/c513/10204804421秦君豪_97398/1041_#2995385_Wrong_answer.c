#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

#define maxn 51


int main(void)
{
    char s[51];
    int flag=0,temp=0;
    int len=0,ans=0;
    scanf("%s",s);
    for (int i=0;i<strlen(s);i++)
    {
        if(s[i]=='|')
        {
            flag=1;
        }
        else if (s[i]=='-')
        {
            flag =-1;
        }
        if (flag==temp)
        {
            if(len>ans) 
                ans=len;
            else {
                len=1;
            }
        }
        else
        {
            len++;
        }


        temp=flag;
    }
    if(ans==0) ans=len;
    printf("%d",ans);
    return 0;

}
