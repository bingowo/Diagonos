#include<stdio.h>
#include<string.h>

int main()
{
    int t;
    scanf("%d\n",&t);

    for (int i=0;i<t;++i)
    {
        char s[101];
        scanf("%s",s);

        int tot[4]={0};
        int cnt[4]={0};
        int pos[4]={-1,-1,-1,-1};
        int len=strlen(s);

        for (int j=0;j<len;++j)
        {
            tot[j%4]++;

            switch (s[j])
            {
                case 'R':
                pos[0]=j%4;
                cnt[j%4]++;
                break;

                case 'B':
                pos[1]=j%4;
                cnt[j%4]++;
                break;

                case 'Y':
                pos[2]=j%4;
                cnt[j%4]++;
                break;

                case 'G':
                pos[3]=j%4;
                cnt[j%4]++;
                break;
            }
        }
        int flag[4]={0};
        int t;
        for (int j=0;j<4;j++)
        {
            if (pos[j]>=0)
            {
                flag[pos[j]]=1;
            }
        }
        for (int j=0;j<4;j++)
        {
            if (!flag[j])
            {
                t=j;break;
            }
        }
        for (int j=0;j<4;j++)
        {
            if (pos[j]<0)
            {
                pos[j]=t;break;
            }
        }

        printf("case #%d:\n",i);
        for (int j=0;j<4;++j)
        {
            printf("%d",tot[pos[j]]-cnt[pos[j]]);putchar(' ');
        }
        putchar('\n');

    }
    return 0;
}