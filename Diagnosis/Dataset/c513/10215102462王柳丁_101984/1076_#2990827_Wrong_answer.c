#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        char a[101];
        scanf("%s",a);
        int sign=1,j;
        for(j=0;j<strlen(a)-1;j++)
        {
            if(a[j]=='{'){if(a[j+1]!='['){sign=0;break;}}
            if(a[j]=='['){if(a[j+1]!='('){sign=0;break;}}
            if(a[j]=='('){if(a[j+1]!=')'&&a[j+1]!='{'){sign=0;break;}}
            if(a[j]==']'){if(a[j+1]!='['&&a[j+1]!='}'){sign=0;break;}}
            if(a[j]==')'){if(a[j+1]!='('&&a[j+1]!=']'){sign=0;break;}}
            if(a[j]=='}'){if(a[j+1]!='{'&&a[j+1]!=')'){sign=0;break;}}
        }
        if(sign==1)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
