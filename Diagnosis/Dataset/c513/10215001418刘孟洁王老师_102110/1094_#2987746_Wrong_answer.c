#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{char s[127],num,sign;}distance;

int cmp(const void*a,const void*b)
{
    distance c = *(distance*)a;
    distance d = *(distance*)b;
    if(c.sign == -1)
    {
        if(d.sign == 1)return 1;
        else if(c.num < d.num)return -1;
        else if(c.num > d.num)return 1;
        else if(strcmp(c.s,d.s) < 0)return -1;
        else return 1;
    }
    else if(c.sign == 1)
    {
        if(d.sign == -1)return -1;
        else if(c.num < d.num)return 1;
        else if(c.num > d.num)return -1;
        else if(strcmp(c.s,d.s) < 0)return 1;
        else return -1;
    }
}

void reverse1(char *s)
{
    int i,n = strlen(s);
    for(i = 0; i <= (n-1)/2; i++)
    {
        char d = s[i];
        s[i] = s[n-1-i];
        s[n-1-i] = d;
    }
    s[n] = '\0';
    //printf("%s\n",s);
}

void reverse2(int *s,int n)
{
    int i,d;
    for(i = 0; i <= (n-1)/2; i++)
    {
        d = s[i];
        s[i] = s[n-1-i];
        s[n-1-i] = d;
    }
}

int main()
{
    distance p[127];
    int cas,i,j,k,m,tmp,len,ans[127];
    char t[127];
    scanf("%d",&cas);
    for(i = 0; i < cas; i++)
    {
        scanf("%s",t);
        len = strlen(t);
        for(j = 0; j < len; j++)p[i].s[j] = '0';
        if(t[0] == '-')p[i].sign = -1,j = 1;
        else p[i].sign = 1, j = 0;
        for(k = 0; j < strlen(t); k++,j++)p[i].s[k] = t[j];
        p[i].num = j;
        p[i].s[k] = '\0';
    }
    qsort(p,cas,sizeof(p[0]),cmp);
    reverse1(p[0].s);reverse1(p[cas-1].s);
    if(p[0].sign == 1 && p[cas-1].sign == 1)
    {
        m = 0;
        len = p[0].num;
        for(i = p[cas-1].num; i < len; i++)p[cas-1].s[i] = '0';
        p[0].s[i] = '\0';p[cas-1].s[i] = '\0';
        for(i = 0; i < len; i++)
        {
            tmp = (p[0].s[i]-'0') - (p[cas-1].s[i]-'0') - m;
            //printf("%d %d\n",p[0].s[i]-'0',p[cas-1].s[i]-'0');
            ans[i] = tmp < 0?tmp+10:tmp;
            m = tmp < 0? 1:0;
        }
    }
    else if(p[0].sign == 1 && p[cas-1].sign == -1)
    {
        m = 0;
        len = p[0].num > p[cas-1].num?p[0].num : p[cas-1].num;
        for(i = p[0].num; i < len; i++)p[0].s[i] = '0';
        for(i = p[cas-1].num; i < len; i++)p[cas-1].s[i] = '0';
        p[0].s[i] = '\0';p[cas-1].s[i] = '\0';
        for(i = 0; i < len; i++)
        {
            tmp = (p[0].s[i]-'0') + (p[cas-1].s[i]-'0') + m;
            ans[i] = tmp%10;
            m = tmp/10;
        }
        while(m)
        {
            ans[len++] = m%10;
        }
    }
    else if(p[0].sign == -1 && p[cas-1].sign == -1)
    {
        m = 0;
        len = p[0].num > p[cas-1].num?p[0].num : p[cas-1].num;
        for(i = p[0].num; i < len; i++)p[0].s[i] = '0';
        for(i = p[cas-1].num; i < len; i++)p[cas-1].s[i] = '0';
        p[0].s[i] = '\0';p[cas-1].s[i] = '\0';
        for(i = 0; i < len; i++)
        {
            tmp = (p[cas-1].s[i]-'0') - (p[0].s[i]-'0') - m;
            ans[i] = tmp < 0?tmp+10:tmp;
            m = tmp < 0? 1:0;
        }
    }
    for(i = 0; ans[i] == 0 && i < len; i++);
    //if(i == len)printf("0\n");
    for( ; i < len; i++)printf("%d",ans[i]);
    return 0;
}

