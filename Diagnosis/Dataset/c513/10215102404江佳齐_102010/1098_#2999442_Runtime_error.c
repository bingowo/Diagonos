#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int m=0;m<t;m++)
    {
        char s[110];
        scanf("%s",s);
        int i,len=strlen(s);
        int turn[4]={0},cnt[4]={0},ans[4];
        for(i=0;i<len;i++)
        {
            turn[i%4]++;
            switch(s[i])
            {
                case 'R': cnt[0]++;ans[0]=i%4;break;
                case 'B': cnt[1]++;ans[1]=i%4;break;
                case 'Y': cnt[2]++;ans[2]=i%4;break;
                case 'G': cnt[3]++;ans[3]=i%4;break;
            }
        }
        printf("case #%d:\n%d %d %d %d\n",m,turn[ans[0]]-cnt[0],turn[ans[1]]-cnt[1],turn[ans[2]]-cnt[2],turn[ans[3]]-cnt[3]);
    }
    return 0;
}
