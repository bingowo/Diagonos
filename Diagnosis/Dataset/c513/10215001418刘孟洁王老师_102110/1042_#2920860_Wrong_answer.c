#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int p[128];

int cmp1(const void*a,const void*b)
{
    char c = *(char*)a;
    char d = *(char*)b;
    if(c < d)return -1;
    else return 1;
}

int cmp2(const void*a,const void*b)
{
    char *s1 = *(char**)a;
    char *s2 = *(char**)b;
    if(strcmp(s1,s2)<0)return -1;
    else return 1;
}


int main()
{
    int n,i,j,k,y,x,l,m,g;
    char s1[17],s2[17], t[150][17];
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 128; j++)p[j] = -1;
        g = 0;
        scanf("%s",s1);
        m = strlen(s1);
        j = 0;
        while(j < m)
        {
            if(p[s1[j]] == -1)p[s1[j]] = 0,s2[g] = s1[j],g++,j++;
            else j++;
        }
        qsort(s2,g,sizeof(char),cmp1);
        j = 0;
       for(x = 0; x < g; x++)
        {
            for(l = 0; l < g-x; l++,j++)//l记录每一个字母开头有几种串;
            {
                for(k = 0, y = x; k <= l; k++, y++)//x记录从哪个这个字母到最后;
                  t[j][k] = s2[y];
                t[j][k] = '\0';
            }
        }
        printf("case #%d:\n",i);
        for(j = 0; j<g*(g+1)/2; j++)printf("%s\n",t[j]);
        for(j = 0; j<g*(g+1)/2; j++)
            for(k = 0; k<17; k++)t[j][k]='\0';
        for(j = 0; j < g; j++)s2[j] = '\0';
}
    return 0;
}
