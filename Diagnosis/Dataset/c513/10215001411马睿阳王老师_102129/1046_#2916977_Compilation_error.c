#include<stdio.h>
#include<ctype.h>
#define N 100
void readpoly(char*p,int* co)
{while(*p)
 {int sign=1,c=0,d=0;
  if(*p=='+') p++;
  else if(*p=='-') {sign=-1;p++;}
  while(isdigit(*p)) {c=c*10+*p-'0';p++;}
  if(*p!='x') {co[0]=c*sign;return;} else p++;
  if(*p=='^') p++;
  while(isdigit(*p)) {d=d*10+*p-'0';p++;}
  co[d]=c*sign;
 }
}

void multiply(char *s1,char *s2,int *co)
{int co1[N]={0},co2[N]={0},i,j;
 readpoly(s1,co1);readpoly(s2,co2);
 for(i=0;i<N;i++)
 {for(j=0;j<N;j++)
  co[i+j]+=co1[i]*co2[j];
 }
}

int main()
{char s1[N+1],s2[N+2];
 while(scanf("%s%s",s1,s2)==2)
 {int *co[N]={0},out[N],n=0,i;
  multiply(s1,s2,co);
  for(i=0;i<N;i++)  if(co[i]) out[n++]=co(i);
  for(i=n-1;i>=0;i--)
  printf("%d",out[i]);
  if(i>0) printf(" ");
  else printf("\n");
 }
 return 0;
}

