#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int cmp(const void*a,const void*b)
{
    char* pa=(char*)a,*pa0=pa,*pb=(char*)b,*pb0=pb;
    while(!isdigit(*pa)&&*pa)pa++;
    while(!isdigit(*pb)&&*pb)pb++;
    if(*pa==0&&*pb==0)return strcmp(pa0,pb0);
    if(*pa==0||*pb==0)if(*pa==0)return -1;else return 1;
    int x=atoi(pa)-atoi(pb);
    if(x)return x;
    else return strcmp(pa0,pb0);
}

int main()
{
   int n=0,i;
   char s[100][1000];
   while(scanf("%s",s[n++])>=1);
   n--;
   qsort(s,n,sizeof(s[0]),cmp);
   for(i=0;i<n;i++)printf("%s ",s[i]);
}
