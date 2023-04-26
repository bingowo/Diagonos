#include <stdio.h>
#include <string.h>

int main()
{
    int T; scanf("%d",&T);
    for (int t=0;t<T;t++)
    {
        char s[101] = {}; scanf("%s",s);
        int colornum[4] = {};
        int c1=0,c2=0,c3=0,c4=0;
        if (strlen(s)==4)
        {
            colornum[0] = 1,colornum[2] = 1,colornum[1] = 1,colornum[3] = 1;
            for (int i=0;i<strlen(s);i++)
            {
                if (s[i]=='R') colornum[0]--;
                else if (s[i]=='B') colornum[1]--;
                else if (s[i]=='Y') colornum[2]--;
                else if (s[i]=='G') colornum[3]--; 
            }
            printf("case #%d:\n%d %d %d %d\n",t,colornum[0],colornum[1],colornum[2],colornum[3]);
        }
        else for (int i=0;s[i];i++)
        {
            if (s[i]=='!') colornum[i%4]++;
            else if (s[i]=='R') c1 = i%4;
            else if (s[i]=='B') c2 = i%4;
            else if (s[i]=='Y') c3 = i%4;
            else if (s[i]=='G') c4 = i%4;
            printf("case #%d:\n%d %d %d %d\n",t,colornum[c1%4],colornum[c2%4],colornum[c3%4],colornum[c4%4]);
        }
    }
    return 0;
}