#include <stdio.h>
#include <stdlib.h>
#include<string.h>
double p[27];
int cmp(const void*a,const void*b)
{
    char c = *(char*)a;
    char d = *(char*)b;
    int p1,p2;

    if( c>= 'a' && c <= 'z' ) p1 = c-'a';
    else p1 = c-'A';

    if(d >= 'a' && d <= 'z') p2 = d-'a';
    else p2 = d-'A';

    if(p[p1] > p[p2])return -1;
    else if(p[p1] < p[p2])return 1;
    else if(c > d)return -1;
    else return 1;
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
