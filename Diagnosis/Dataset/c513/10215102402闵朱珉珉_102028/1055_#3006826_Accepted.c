#include <stdio.h>

int main()
{
    char s[1000001];
    scanf("%s",s);
    int len=0,start=0;
    int q[128];
    for (int i=0;i<128;i++) q[i]=-1;
    int t=0;
    for (int i=0;s[i];i++)
    {
        char c=s[i];
        if (q[c]>=t)
        {
            t=q[c]+1;
            q[c]=i;
        }
        else
        {
            q[c]=i;
            if (len<i-t+1)
            {
                start=t;
                len=i-t+1;
            }
        }
    }
    for (int j=start;j<start+len;j++)
        printf("%c",s[j]);

}
