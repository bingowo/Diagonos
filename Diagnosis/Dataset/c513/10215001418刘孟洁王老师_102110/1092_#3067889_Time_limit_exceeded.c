#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,k,len1,tmp,m;
    char s[1007];
    int num[1007];
    scanf("%s",s);
    int len = strlen(s);
    memset(num,0,sizeof(num));
    len1 = 1;num[0] = 1;
    if(len == 1)printf("1");
    else
    {
        for(i = 0; i < len; i++)
      {
        if((i == 0 && s[i] != s[i+1])||(i == len-1 && s[i] != s[i-1]))
        {
            m = 0;
           for(k = 0; k < len1; k++)
            {
                tmp = num[k]*2 + m;
                num[k] = tmp%10;
                m = tmp/10;
            }
            while(m)
            {
                num[len1++] = m%10;
                
            }
        }
        else if(s[i] != s[i-1]&&s[i] != s[i+1]&&s[i-1] != s[i+1])
        {
            m = 0;
            for(k = 0; k < len1; k++)
            {
                tmp = num[k]*3 + m;
                num[k] = tmp%10;
                m = tmp/10;
            }
            while(m)
            {
                num[len1++] = m%10;
                m /= 10;
            }
        }
        else if((s[i] != s[i-1]&&s[i] == s[i+1])||(s[i] != s[i+1]&&s[i] == s[i-1])||(s[i] != s[i-1]&&s[i] != s[i+1]&&s[i-1] == s[i+1]))
        {
            if(i == 0 || i == len-1)continue;
            else
            {
                m = 0;
                for(k = 0; k < len1; k++)
                {
                    tmp = num[k]*2 + m;
                    num[k] = tmp%10;
                    m = tmp/10;
                }
                while(m)
                {
                    num[len1++] = m%10;
                   m /= 10;
                }
            }
        }
    }
    for(i = len1-1; i>= 0; i--)printf("%d",num[i]);
    }
    return 0;
}