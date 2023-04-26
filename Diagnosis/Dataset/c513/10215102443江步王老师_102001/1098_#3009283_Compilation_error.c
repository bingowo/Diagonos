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
        int pos[4];
        int len=strlen(s);

        for (int j;j<len;++j)
        {
            tot[j%4]++;

            switch (s[i])
            {
                case 'R':
                pos[0]=i%4;
                cnt[i%4]++;
                break;

                case 'B':
                pos[1]=i%4;
                cnt[i%4]++;
                break;

                case 'G':
                pos[2]=i%4;
                cnt[i%4]++;
                break;

                case 'Y':
                pos[3]=i%4;
                cnt[i%4]++;
                break;
            }
        }
        printf("case #%d:\n",i);
        for (int j=0;j<4;++j)
        {
            printf("%d",tot[pos[j]]-cnt[pos[j]]);putchar(' ')
        }
        putchar('\n');

    }
    return 0;
}