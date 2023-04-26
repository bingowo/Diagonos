#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a,const void*b)
{
    int c = *(int*)a;
    int d = *(int*)b;
    if(c < d)return -1;
    else return 1;
}

int main()
{
    int i,j,k,h,cas,flag = 0,ans,ans1,ans2,midle;
    int len[1007],num[107][17],p[128];
    char s[107][17],ss[57][17];
    scanf("%d",&cas);
    for(i = 0; i < cas; i++)
    {
        memset(p,-1,sizeof(p));
        scanf("%s",s[i]);
        len[i] = strlen(s[i]);
        for(j = 0,k = 0; j < len[i]; j++)
        {
            if(p[s[i][j]] == -1)
            {
               p[s[i][j]] = 0;
               ss[i][k] = s[i][j];
               if(i != 0 && ss[i][k] != ss[0][k])
               {
                  printf("-1\n");
                  flag = 1;
                  break;
               }
               else k++;
            }
        }
        ss[i][k] = '\0';
    }
    for(i = 0; !flag&&i < cas; i++)
    {
        for(j = 0,h = 0; j < len[i]; j++)
            {
                if(s[i][j] == ss[0][h])num[h][i]++;
                else
                {
                    h++;
                    num[h][i]++;
                }
            }
    }
    if(cas%2 == 1 && !flag)
    {
        for(h = 0,ans = 0; h < k; h++)
        {
            qsort(num[h],cas,sizeof(int),cmp);
            for(i = 0; i < cas; i++)ans += abs(num[h][i] - num[h][(cas-1)/2]);
         }
    }
    else if(cas%2 == 0 && !flag)
    {
        for(h = 0,ans = 0; h < k; h++)
        {
            qsort(num[h],cas,sizeof(int),cmp);
            midle = num[h][cas/2] + num[h][(cas-1)/2];
            if(midle%2 == 0)
            {
                midle /= 2;
                for(i = 0; i < cas; i++)ans += num[h][i] - midle;
            }
            else
            {
                for(i = 0,ans1 = 0; i < cas; i++)ans1 += abs(num[h][i] - num[h][cas/2]);
                for(i = 0,ans2 = 0; i < cas; i++)ans2 += abs(num[h][i] - num[h][(cas-1)/2]);
                ans = ans1<ans2?ans1+ans:ans2+ans;
            }
       }
    }
    if(!flag)printf("%d\n",ans);
    return 0;
}
