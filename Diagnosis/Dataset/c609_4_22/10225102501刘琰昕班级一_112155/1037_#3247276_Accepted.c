#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *s; int start=0,maxlen=0;
    s=(char *)malloc(1000001*sizeof(char));
    scanf("%s",s);
    //48-57数字，65-90大写字母，97-122小写字母
    int alpha[123];//是否出现过与上一次出现的位置
    for(int i=0;i<123;i++)alpha[i]=-1;
    int t=0;
    for(int i=0;s[i];i++)
    {
        char c=s[i];
        if(alpha[c]>=t)
            {t=alpha[c]+1;alpha[c]=i;}
        else
        {
            alpha[c]=i;
            if(maxlen<i-t+1)
                {start=t;maxlen=i-t+1;}
        }
    }
    for(int i=start;i<start+maxlen;i++)
        putchar(s[i]);
    return 0;
}
