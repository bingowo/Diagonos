#include <stdio.h>
#include <stdlib.h>

void zhengshu()
{

}

void fudianshu()
{

}

int main()
{
    char s[1000];
    while (scanf("%s",s)!=EOF)
    {
        int i;
        for(i=0;s[i];i++)
        {
            if(s[i]=='.')
                fudianshu(atof(s));
        }
        zhengshu(atoi(s));
        return 0;
    }
}
