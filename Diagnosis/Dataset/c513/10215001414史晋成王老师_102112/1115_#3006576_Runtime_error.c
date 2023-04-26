#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int cmp(const void*a,const void*b)
{
    return *(char*)a-*(char*)b;
}
int main()
{int T,i,j,n,m,y,x,k,xi;
long long int N;
char s[100];
scanf("%d",&T);
for(i=0;i<T;i++)
{ x='9'+1; memset(s,0,sizeof(s));
printf("case #%d:\n",i);
  scanf("%s",s+1);
  for(j=strlen(s)-1;s[j-1]>=s[j];j--)
  y=s[j-1];
  for(k=strlen(s)-1;k>=j;k--)
  if(s[k]>y&&s[k]<x) {x=s[k]; xi=k;}
  s[j-1]=x;s[xi]=y;
  qsort(s+j,strlen(s)-j,sizeof(s[0]),cmp);
  printf("%s\n",s+(s[0]=='0'));
}
    
}