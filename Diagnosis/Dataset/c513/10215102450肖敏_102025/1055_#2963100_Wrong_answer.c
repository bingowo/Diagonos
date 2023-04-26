#include <stdio.h>

int main() {
    char s[1000001];
    scanf("%s",s);
    int b=0;
    int len =0;
    int i,m[128];
    for(i=0;i<128;i++)
        m[i]=-1;
    int t=0;
    char c;
    for(i=0;s[i];i++)
    {
        c=s[i];
        if(m[c] >= t)
        {
            t= m[c]+1;
            m[c]=i;
        } else{
            m[c]=i;
            if(len < i-t+1)
            {
                b=1;
                len=i+1-t;
            }
        }
    }
    for(int j=0;j<len;j++)
    {
        printf("%c",s[j]);
    }
    printf("\n");
    return 0;
}
