#include <stdio.h>
#include <string.h>
int main()
{
    char s[51];
    scanf("%s",s);
    int n=strlen(s),start=0,temp=1,len=1;
    while(start<n)
    {
        switch(s[start])
        {
            case '|':
            {
                if (start==0) start+=1;
                else if (s[start-1]=='|')
                {
                    if (len>=temp) temp=len;
                    len=1;
                    start+=1;
                }
                else
                {
                    len+=1;
                    start+=1;
                }
                break;
            }
            case '-':
            {
                if (start==0) start+=1;
                else if (s[start-1]=='-')
                {
                    if (len>=temp) temp=len;
                    len=1;
                    start+=1;
                }
                else
                {
                    len+=1;
                    start+=1;
                }
                break;
            }
        }
    }
    if (len>=temp) temp=len;
    printf("%d",temp);
    return 0;
}
