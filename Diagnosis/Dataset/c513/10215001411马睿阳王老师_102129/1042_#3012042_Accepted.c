#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int p[128];

int cmp1(const void*a,const void*b)
{
    char c = *(char*)a;
    char d = *(char*)b;
    if(c<d)return -1;
    else return 1;
}

int cmp2(const void*a,const void*b)
{
    char *c = *(char**)a;
    char *d = *(char**)b;
    if(strcmp(c,d)<0)return -1;
    else return 1;
}



int main()
{
    int n,i,j,k,l,m,len;
    char s1[17],s2[17],**t;
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
        t = (char**)malloc(pow(2,len)*sizeof(char*));

        for(j = 0; j < (1<<len); j++)
            t[j] = (char*)malloc(17*sizeof(char));
        for(j = 1; j < (1<<len); j++)//枚举到全1即可；
        {
           for(k = 0,l = 0; l < len; l++)
           {
               if((j>>l)&1)//j的二进制是1的地方储存字母，0的地方不储存；
               {
                   t[j-1][k] = s2[l];
                   k++;
               }
               t[j-1][k] = '\0';
           }
        }
        //用二进制枚举并记录字符排列的情况；
        qsort(t,j-1,sizeof(t[0]),cmp2);//将所有字符串按字典顺序排序
        printf("case #%d:\n",i);
        for(k = 0; k<j-1; k++)printf("%s\n",t[k]);
        for(j = 0; j < len; j++)s2[j] = '\0';
}
    return 0;
}