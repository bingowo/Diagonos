#include <stdio.h>
#include <string.h>
int main()
{
    char s[20];
    int len;
    double n;
    while(scanf("%s",s)!=EOF)
    {
        n=0;
        len=strlen(s);
        int i;
        for(i=len-1;s[i]!='.';i--)
        {
            n/=double(8.0);
            n+=double(s[i]-'0');
        }
        n/=double(8.0);
        printf("%s",s);
        printf(" [8] = %.45g [10]\n",n);
    }
    return 0;
}
