#include<stdio.h>
int main()
{
    char s[1000001];
    gets(s);
    int maxlen=0;
    int start=0;
    int alpha[128];
    for(int i=0;i<128;i++) alpha[i]=-1;
    int t=0;
    for(int i=0;s[i];i++)
    {
        char c=s[i];
        if(alpha[c]>=t)
        {
            t=alpha[c]+1;
            alpha[c]=i;
        }
        else
        {
            alpha[c]=i;
            if(maxlen<i-t+1)
            {
                start=t;
                maxlen=i-t+1;
            }
        }
    }
    for(int i=start;i<start+maxlen;i++) printf("%c",s[i]);
}