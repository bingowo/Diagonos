#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T; scanf("%d",&T);
    for (int t=0;t<T;t++)
    {
        char s[101] = {}; scanf("%s",s);
        int colornum[4] = {};
        int c1,c2,c3,c4; 
        for (int i=0;s[i];i++)
        {
            if (s[i]=='!') colornum[i%4]++;
            else if (s[i]=='R') c1 = i;
            else if (s[i]=='B') c2 = i;
            else if (s[i]=='Y') c3 = i;
            else if (s[i]=='G') c4 = i;
        }
        printf("%d %d %d %d\n",colornum[c1%4],colornum[c2%4],colornum[c3%4],colornum[c4%4]);
    }
    system("pause");
    return 0;
}