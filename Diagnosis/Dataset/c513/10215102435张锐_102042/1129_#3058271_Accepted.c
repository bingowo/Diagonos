#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char s[20000];
    scanf("%s",&s);
    int l=strlen(s);
    int left=0;int right=0;
    for(int i=0;i<l;i++)
    {
        if(isdigit(s[i]))
        {
            int temp=0;right=i;
            while(isdigit(s[i])) temp=temp*10+(s[i++]-'0');
            i--;
            for(int f=0;f<temp;f++)
            {
                for(int j=left;j<right;j++) printf("%c",s[j]);
            }
            left=i+1;
        }
        if(i==l-1)
        {
            right=l;
            for(int j=left;j<right;j++) printf("%c",s[j]);
        }
    }
    return 0;
}
