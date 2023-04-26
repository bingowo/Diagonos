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
        int c1=0,c2=0,c3=0,c4=0; 
        for (int i=0;s[i];i++)
        {
            if (s[i]=='!') colornum[i%4]++;
            else if (s[i]=='R') c1 = i%4;
            else if (s[i]=='B') c2 = i%4;
            else if (s[i]=='Y') c3 = i%4;
            else if (s[i]=='G') c4 = i%4;
        }
        /*if (c1==0) c1 = 6-c2-c3-c4;
        if (c2==0) c2 = 6-c1-c3-c4;
        if (c3==0) c3 = 6-c1-c2-c4;
        if (c4==0) c4 = 6-c1-c2-c3; */
        printf("case #%d:\n%d %d %d %d\n",t,colornum[c1%4],colornum[c2%4],colornum[c3%4],colornum[c4%4]);
    }
    return 0;
}