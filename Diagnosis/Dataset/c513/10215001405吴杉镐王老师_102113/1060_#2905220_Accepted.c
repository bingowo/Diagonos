#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[101];
    int cnt=0;
    int max=0;
    gets(s);
    int l=strlen(s);
    for(int i=0;i<l;i++)
    {
        if(isdigit(s[i]) && s[i]!='0')
        {
            while(isdigit(s[i]))
            {
                cnt++;
                i++;
            }
            if(cnt>max)
            {
                max=cnt;
            }
            cnt=0;
        }
    }
    printf("%d",max);
}
