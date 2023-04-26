#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    char s[101];
    scanf("%s",s);
    int x,y;
    int len= strlen(s);
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int a=0,b=0;
        scanf("%d%d",&x,&y);
        if(a==x&&b==y)
            printf("%s\n","Yes");
        int flag=0;
        while (a!=x||b!=y)
        {
            for(int k=0;k<len;k++)
            {
                flag++;
                if(s[k]=='U')
                {
                    b++;
                }
                if(s[k]=='D')
                {
                    b--;
                }
                if(s[k]=='L')
                {
                    a--;
                }
                if(s[k]=='R')
                {
                    a++;
                }
                if(a==x&&b==y)
                {
                    printf("%s\n","Yes");
                    break;
                }
            }
            if(flag>3000)
            {
                printf("%s\n","No");
                break;
            }
        }
    }
    return 0;
}
