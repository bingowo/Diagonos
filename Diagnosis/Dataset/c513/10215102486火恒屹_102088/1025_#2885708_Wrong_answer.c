#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int quesnum;
    scanf("%d",&quesnum);
    for(int i=0;i<quesnum;i++)
    {
        printf("case #%d:\n",i);
        int snum;
        char s[102][22]={'\0'};
        scanf("%d",&snum);
        for(int j=0;j<snum;j++)
            scanf("%s",&s[j]);
        int alphanum[102]={0};
        for(int j=0;j<snum;j++)
        {
            for(int k=0;k<strlen(s[j]);k++)
            {
                int flag=1;
                for(int l=0;l<k;l++)
                {
                    if(s[j][l]==s[j][k])
                        flag=0;
                }
                if(flag==1)
                    alphanum[j]++;
            }
        }
        for(int j=0;j<snum;j++)
        {
            int max=0;
            for (int k=0;k<snum;k++)
            {
                if(max==k)
                {
                    max++;
                    continue;
                }
                if(alphanum[max]<alphanum[k])
                    max=k;
                else if(alphanum[max]==alphanum[k])
                    {int cmp=strcmp(s[max],s[k]);
                     if(cmp>0) max=k;}
            }
            printf("%s\n",s[max]);
            alphanum[max]=0;
        }
    }
    return 0;
}
