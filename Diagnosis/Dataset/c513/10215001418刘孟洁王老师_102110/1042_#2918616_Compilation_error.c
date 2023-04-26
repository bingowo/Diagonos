#include<stdio.h>
#include<stdlib.h>

int cmp1(const void*a,const void*b)
{
    char c = *(char*)a;
    char d = *(char*)b;
    if(a < b)return -1;
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
    int n;
    char s[17]; t[150][17];
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s",s);
        m = strlen(s);
        qsort(s,strlen(s),sizeof(char),cmp);
        for(j = 0; j < m*(m+1)/2; j += l)
        {
            for(l = 0/*等于几还需考虑*/; l < m-j; l++)//每一个字母开头有几种串
                for(k = 0; k <= l; k++)//记录从那个这个字母到最后
                t[l][k] = s[k];
        }
        prinf("%case #%d:\n",i);
        
    }
}