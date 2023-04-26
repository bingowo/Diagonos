#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char s;
    int i;
}map4;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[101];
        map4 ans[4]={0};
        map4 ret[4]={{'R',0},{'B',0},{'Y',0},{'G',0}};
        scanf("%s",s);
        int len=strlen(s);
        for(int j=0;j<len;j++)
        {

            if(s[j]!='!')
                {
                    ans[j%4].s=s[j];
                    switch(s[j])
                    {
                        case 'R':ret[0].i++;break;
                        case 'B':ret[1].i++;break;
                        case 'Y':ret[2].i++;break;
                        case 'G':ret[3].i++;break;
                    }

                }
            else
            {
                ans[j%4].i++;
                if(ans[j%4].s!='Y'&&ans[j%4].s!='B'&&ans[j%4].s!='G'&&ans[j%4].s!='R')
                    ans[j%4].s='!';
            }

        }
        printf("case #%d:\n",i);
        for(int k=0;k<4;k++)
        {
            if(ret[k].i==0)
            {
                for(int m=0;m<4;m++)
                {
                    if(ans[m].s=='!')
                    {
                        ans[m].s=ret[k].s;
                    }
                }
            }
        }
        for(int k=0;k<4;k++)
        {
            if(ans[k].s=='R')printf("%d",ans[k].i);
        }
        for(int k=0;k<4;k++)
        {
            if(ans[k].s=='B')printf(" %d",ans[k].i);
        }
        for(int k=0;k<4;k++)
        {
            if(ans[k].s=='Y')printf(" %d",ans[k].i);
        }
        for(int k=0;k<4;k++)
        {
            if(ans[k].s=='G')printf(" %d\n",ans[k].i);
        }

    }
    return 0;
}
