#include <stdio.h>
#include <stdlib.h>
#include<string.h>
double p[27];
int cmp(const void*a,const void*b)
{
    char c = *(char*)a;
    char d = *(char*)b;
    int p1,p2;

    if( c >= 'a' && c <= 'z' ) p1 = c-'a';
    else p1 = c-'A';

    if( d >= 'a' && d <= 'z' ) p2 = d-'a';//直接将字母转化为数字，方便知道字母频率
    else p2 = d-'A';

    if(p[p1] > p[p2])return -1;
    else if(p[p1] < p[p2])return 1;
    else //频率相同时，分字母相同和不同情况讨论（**特别注意，不同字母可能频率相同）
    {
        if(p1==p2)
        {
            if(c<d)return 1;
          else return -1;  
        }
        else
        {
            if(c<d)return -1;
          else return 1; 
        }
    }
}

int main()
{
    int i,j,n;
    char s[101];
    scanf("%d",&n);
    for(j = 0;j < n;j++)
    {
      for(i = 0; i<26; i++)scanf("%lf",&p[i]);
      scanf("%s",s);
      qsort(s,strlen(s),sizeof(s[0]),cmp);
      printf("case #%d:\n",j);
      printf("%s\n",s);
    }
    return 0;
}