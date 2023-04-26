#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
double p[27];
char str[101];
float time[26];
int i;
int cmp(const void *a,const void *b)
{
    char *p1=(char *)a;
    char *p2=(char *)b;

    if(*p1==*p2+32) return -1;
    if(*p1==*p2-32) return 1;

    int t1= *p1<=96 ? *p1-'A':*p1-'a';
    int t2= *p2<=96 ? *p2-'A':*p2-'a';

    if(time[t1]>time[t2]) return -1;
    else return 1;
}

int main()
{
 int T=0;
 scanf("%d",&T);
 for(i=1;i<=T;i++)
 {
  int j;
  for(j=0;j<26;j++) scanf("%f",time+j); //输入频率
  scanf("%s",str);
  qsort(str,strlen(str),sizeof(char),cmp); 
  printf("case #%d:\n%s\n",i-1,str);
 }
 return 0;
}