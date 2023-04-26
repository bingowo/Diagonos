#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main()
{
    char s[110];memset(s,0,110*sizeof(char));

    scanf("%s",s);
    int len = strlen(s);
    //char num[50][110];memset(num,0,50*110*sizeof(char));
    int cnt = 0;
    long long now = 0,max = 0;
    char t[110];memset(t,0,110*sizeof(char));
    for(int i = 0;i<len;i++)
    {
        if(isdigit(s[i])){t[cnt] = s[i];cnt++;}
        else
        {
            //printf("%s\n",t);
            sscanf(t,"%lld",&now);
            if(now>max){max = now;}
            //printf("t = %s, now = %d\n",t,now);
            memset(t,0,110*sizeof(char));
            cnt = 0;
        }
    }
    sscanf(t,"%lld",&now);
    if(now>max){max = now;}
    //printf("now = %d\n",now);
    printf("%lld\n",max);
    //for(int i = 0;i<len;i++)
    //{
    //    if(isdigit(s[i]))
    //}

    //char *s1 = "00123";
    //int n1 = 0;
    //sscanf(s1,"%d",&n1);
    //printf("%d\n",n1);
    return 0;
}
