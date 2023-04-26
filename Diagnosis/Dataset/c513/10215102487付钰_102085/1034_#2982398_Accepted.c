#include <stdio.h>
#include <stdlib.h>
#include <string.h>
float time[26];
char str[151];
int i;

int cmp(const void *pt1,const void *pt2)
{
 char * p1=(char *)pt1;
 char * p2=(char *)pt2;
 
 if(*p1==*p2+32) return -1;
 if(*p1==*p2-32) return 1;
 
 int t1= *p1<=90 ? *p1-'A':*p1-'a'; 
 int t2= *p2<=90 ? *p2-'A':*p2-'a'; 
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