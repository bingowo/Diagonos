#include <stdio.h>
#include <string.h>
int main()
{
    char s[101];
    scanf("%s",s);
    int res = 0,i,n = 0;
    for(i = 0;i<strlen(s);i++)
    {
        if(isdigit(s[i]))
        {
            if(s[i]=='0')
            {
                int j = i;
                while(s[j]=='0') j--;
                if(isdigit(s[j])) n++;
            }
            else n++;
        }
        else if(isdigit(s[i-1])) n = 1;res = res>n?res:n;
    }
    printf("%d",res);
    return 0;

}
