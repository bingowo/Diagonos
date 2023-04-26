#include <stdio.h>
#include <string.h>

int Bigmul(int a[],int n,int index)
{
    for (int i=0;i<index;i++) a[i] *= n;
    for (int i=0;i<index;i++)
    {
        a[i+1] += a[i]/10;
        a[i] %= 10;
    }
    if (a[index]) return 1;
    else return 0;
}

int main()
{
    char s[1001] = {}; gets(s);
    int ans[501] = {1}; int index = 1;
    if (s[0]!=s[1]&&s[1]) ans[0] *= 2;
    if (s[strlen(s)-1]!=s[strlen(s)-2]&&s[1]) ans[0] *= 2;
    for (int i=1;s[i+1];i++)
    {
        if (s[i]!=s[i-1]&&s[i]!=s[i-1]&&s[i-1]==s[i+1])
        {
            if (Bigmul(ans,2,index)) index++;
        }
        else if (s[i]!=s[i-1]&&s[i]!=s[i+1])
        {
            if (Bigmul(ans,3,index)) index++;
        }
        else if (!(s[i]==s[i-1]&&s[i]==s[i+1]))
        {
            if (Bigmul(ans,2,index)) index++;
        }
    }
    for (int i=index-1;i>=0;i--) printf("%d",ans[i]);
    printf("\n");
    return 0;
}