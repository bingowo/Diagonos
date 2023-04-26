#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long  len,line,k,h;
long long  sum[3007][3007];
long long sn[10007];

void turn_chuan(long long j)
{

    if(j < 10)sn[0] = j;
    else
    {
        for(k = 0; j; k++)
        {
            sn[k] = j%10;
            j /= 10;
        }
    }
}

void multiply_line(long long s[])
{
    for(line = 0; line < k; line++)
        for(h = 0; h < len; h++)sum[line][h+line] = s[h]*sn[line];
    for(line = 0; line < k; line++)
        for(h = 0; h < len; h++)
        {
          if(h == len-1&&sum[line][h+line] >= 10)
            {
                sum[line][h+line+1] += (sum[line][h+line]/10);
                sum[line][h+line] %= 10;
                len++;
            }
          else if(sum[line][h+line] >= 10)
            {
                sum[line][h+line+1] += (sum[line][h+line]/10);
                sum[line][h+line] %= 10;
            }
        }
    len++;
}

void get_val(long long s[])
{
     for(h = 0,s[h] = 0; h < len; h++)
        for(line = 0; line < k; line++)s[h] += sum[line][h];
     for(h = 0; h < len; h++)
    {
        if(h == len-1&&s[h] >= 10)
        {
            s[h+1] += (s[h]/10);
            s[h] %= 10;
            len++;
        }
        else if(s[h] >= 10)
        {
            s[h+1] += (s[h]/10);
            s[h] %= 10;
        }
    }
}


int main()
{
    int cas,i;
    long long n,num,j;
    long long s[10007];
    scanf("%d",&cas);
    for(i = 0; i < cas; i++)
    {
        memset(s,0,sizeof(s));
        memset(sn,0,sizeof(sn));
        memset(sum,0,sizeof(sum));
        scanf("%lld",&n);
        if(n <= 4){num = 0;printf("case #%d:\n",i);printf("%lld\n",num);continue;}
        else
        {
            s[0] = 4;
            s[1] = 2;
            len = 2;
            k = 1;
            for(j = 5; j <= n; j++)
            {
               turn_chuan(j);
               multiply_line(s);
               get_val(s);
            }
            for(num = 0; s[num] == 0; num++);
            }
            printf("case #%d:\n",i);
            printf("%lld\n",num);
            //for(j = len-1; j >= 0; j--)printf("%lld",s[j]);
            //printf("\n");
        }
        return 0;
    }
