#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    int T;
    scanf("%d",&T);
    char s[2001][35];int m;
    char x[2001];
    for(int cas=0;cas<T;cas++)
    {
        scanf("%d",&m);
        getchar();
        gets(x);
        int i=0,k=0;
        for(i=0;k<strlen(x);i++)
        {
            for(int j=0;;j++)
            {
                if(x[k]!=' ' && x[k]!='\0')
                {
                    s[i][j]=x[k];
                    k++;
                }
                else
                {
                    k++;
                    if(j==0)
                    {
                        i--;
                    }
                    else s[i][j]='\0';
                    break;
                }
            }
        }
        printf("case #%d:\n",cas);
        int cnt=0;int num=0;
        for(int j=0;j<i;j++)
        {
            cnt+=strlen(s[j]);
            if(cnt<m)
            {
                num++;cnt++;
            }
            else
            {
                if(cnt>m)
                {
                    cnt--;
                    cnt-=strlen(s[j]);
                    num--;
                    j--;
                }
                cnt=m-(cnt-num);//空格个数
                for(int k=j-num;k<j;k++)
                {
                    printf("%s",s[k]);
                    for(int l=0;l<cnt/num;l++)
                    {
                        printf(" ");
                    }
                    cnt=cnt-cnt/num;
                    num--;
                }
                printf("%s\n",s[j]);
                cnt=0;num=0;
            }
        }
        if(cnt!=0)
        {
            cnt--;
            num--;
            for(int k=i-1-num;k<i-1;k++)
            {
                printf("%s ",s[k]);
            }
            printf("%s\n",s[i-1]);
        }
    }
    return 0;
}


