#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[51];memset(s,0,51*sizeof(char));
    scanf("%s",s);
    int i = 0,j = 0,len = 1,res = 1;
    while(s[j+1]!=0)
    {
        if(s[j]==s[j+1]){i = j+1;j++;}
        else
        {
            j++;
            len = j-i+1;
            if(len>res){res = len;}
        }
    }
    printf("%d",res);
    return 0;
}
