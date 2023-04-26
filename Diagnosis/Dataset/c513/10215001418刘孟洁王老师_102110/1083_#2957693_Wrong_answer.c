#include<stdio.h>
#include<stdlib.h>


int main()
{
    int cas,n,i,j,k,h,line,num,len,g;
    int s[10007] = {0},sn[10007] = {0},sum[107][107] = {0};
    scanf("%d",&cas);
    for(i = 0; i < cas; i++)
    {
        scanf("%d",&n);
        if(n <= 4){num = 0;printf("case #%d:\n",i);printf("%d\n",num);continue;}
        else
        {
            s[0] = 4;
            s[1] = 2;
            len = 2;
            k = 1;
            for(j = 5; j <= n; j++)
            {
                if(j < 10)sn[0] = j;
                else
                {
                    g = j;
                    for(k = 0; g; k++)
                    {
                        sn[k] = g%10;
                        g /= 10;
                    }
                }
                    for(line = 0; line < k; line++)
                        for(h = 0; h < len; h++)sum[line][h+line] = s[h]*sn[line];
                    for(line = 0; line < k; line++)
                       for(h = 0; h < len; h++)
                      {
                        if(h == len-1&&sum[line][h+line] > 10)
                        {
                            sum[line][h+line+1] += (sum[line][h+line]/10);
                            sum[line][h+line] %= 10;
                            len++;
                        }
                        else if(sum[line][h+line] > 10)
                            {
                             sum[line][h+line+1] += (sum[line][h+line]/10);
                             sum[line][h+line] %= 10;
                            }
                      }
                    for(h = 0;h < len; h++)s[h] = 0;
                    for(h = 0; h < len; h++)
                        for(line = 0; line < k; line++)s[h] += sum[line][h];
                    for(h = 0; h < len; h++)
                    {
                        if(h == len-1&&s[h] > 10)
                        {
                            s[h+1] += (s[h]/10);
                            s[h] %= 10;
                            len++;
                        }
                        else if(s[h] > 10)
                        {
                            s[h+1] += (s[h]/10);
                            s[h] %= 10;
                        }
                    }
                    for(line = 0; line < k; line++)
                        for(h = 0; h < len; h++)sum[line][h] = 0;
                    for(h = 0; h < len; h++)sn[h] = 0;
                }
            for(j = 0; s[j] != 0; j++);
                    num = j-1;
            }
            printf("case #%d:\n",i);
            printf("%d\n",num);
        }
        return 0;
    }