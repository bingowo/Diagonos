#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T = 0;
    int reslist[10];
    char s[100];
    memset(s,0,100);

    scanf("%d",&T);

    for(int i = 0;i<T;i++)
    {
        scanf("%s",s);

        int res = 0,j = 0;

        while(s[j] != 0)
        {
            if(s[j] == '1'){res = 3*res + 1;}
            else if(s[j] == '0'){res = 3*res;}
            else if(s[j] == '-'){res = 3*res - 1;}
            j++;
        }

        reslist[i] = res;
    }

    for(int i = 0;i<T;i++)
    {
        printf("%d\n",reslist[i]);
    }

    return 0;
}
