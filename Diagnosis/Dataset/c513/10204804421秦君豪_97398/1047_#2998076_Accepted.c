#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

typedef struct
{
    int num;
    char c;
}data;

int solve(char* s, data* ans)
{
    char tmp=' ';
    int cnt=-1;
    for (int i=0;s[i]!='\0';i++)
    {
        char chr = s[i];
        if((chr!=tmp)||(i==0))
        {
            cnt++;
            ans[cnt].c=chr;
            ans[cnt].num++;
            tmp=chr;
        }
        else if(chr==tmp)
        {
            if(ans[cnt].num==255)
            {
                ans[++cnt].c=chr;
                ans[cnt].num++;
            }
            else
            {
                ans[cnt].num++;
            }
        }
    }
    return cnt;
}





int main(void)
{
    int t;char s[501];
    scanf("%d",&t);
    getchar();
    for(int i=0;i<t;i++)
    {
        gets(s);
        data ans[501]={{0}};
        int len=solve (s,ans);
        printf("case #%d:\n",i);
        for (int j=0;j<=len;j++)
        {
            printf("%d%c",ans[j].num,ans[j].c);
        }
        printf("\n");
    }
    return 0;

}
