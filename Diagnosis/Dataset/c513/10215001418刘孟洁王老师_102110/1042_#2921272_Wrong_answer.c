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
    int n,i,j,k,y,start,l,m,len,sec;
    char s1[17],s2[17], t[150][17];
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 128; j++)p[j] = -1;
        len = 0;
        scanf("%s",s1);
        m = strlen(s1);
        j = 0;
        while(j < m)
        {
            if(p[s1[j]] == -1)p[s1[j]] = 0,s2[len] = s1[j],len++,j++;
            else j++;
        }
        qsort(s2,len,sizeof(char),cmp1);
        j = 0;
       for(start = 0; start < len; start++)//记录开头的字母；
        {
            for(sec = 1; sec < len-start; sec++)//后面会有几个字母做第二个字母
           {
                    for(l = sec-1; l < len-start-sec+1;l++,j++)//l记录每一个字母开头的字符串最长有多长;
                 {
                        t[j][0] = s2[start];
                        for(k = 1, y = start+sec; k <= l; k++, y++)//x记录从哪个这个字母到最后;
                          t[j][k] = s2[y];
                        t[j][k] = '\0';
                }

           }
        }
        printf("case #%d:\n",i);
        for(k = 0; k<j; k++)printf("%s\n",t[k]);
        for(k = 0; k<j; k++)
            for(l = 0; l<17; l++)t[k][l]='\0';
        for(j = 0; j < len; j++)s2[j] = '\0';
}
    return 0;
}
