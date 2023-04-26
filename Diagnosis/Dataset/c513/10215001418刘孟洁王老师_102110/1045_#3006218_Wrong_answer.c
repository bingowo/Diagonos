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
int len[100007],num[107][100007];
char s[100007][107],ss[100007][107];
int main()
{
    int i,j,k,h,cas,flag = 0,ans,ans1,ans2,midle;
    scanf("%d",&cas);
    for(i = 0; i < cas; i++)
    {
        //memset(p,-1,sizeof(p));
        scanf("%s",s[i]);
        memset(ss[i],0,sizeof(ss[i]));
        len[i] = strlen(s[i]);
        ss[i][0] = s[i][0];
        for(j = 0,k = 0; j < len[i]; j++)
        {
            if(i != 0 && ss[i][k] != ss[0][k])
               {
                  printf("-1\n");
                  flag = 1;
                  break;
               }
            if(s[i][j] != ss[i][k])
             {
               k++;
               ss[i][k] = s[i][j];
            }
        }
        k++;ss[i][k] = '\0';
    }
    for(h = 0; h < k; h++)memset(num[h],0,sizeof(num[h]));
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
