#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void readnumber(char*s,int*a)
{ int i,k=0,e=1;
for(i=strlen(s)-1;i>=0;i--)
{if(s[i]!=','){a[k]=a[k]+(s[i]-'0')*e;e=e*10;}
    else {k++;e=1;}
}
    
}
void add(int* a,int* b,int* c)
{int prime[26]=
{97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2},i=0,j=0,d=0,digit=0,sign=25;
 for(d=0;d<26;d++)
  { c[d]=a[d]+b[d]+digit;
    digit=c[d]/prime[25-d];
    c[d]=c[d]%prime[25-d];
      }
     while(c[sign--]==0&&sign>=0);
      for(i=sign+1;i>0;i--)
      printf("%d,",c[i]);
      printf("%d\n",c[i]);
}
int main()
{ int a=0,b=0,j,T,i,k,s,f,g,t,r,p;
 char s1[60],s2[60];
  scanf("%d",&T);
  for(i=0;i<T;i++)
  {   int n[30]={0},m[30]={0},c[30]={0};
      scanf("%s%s",s1,s2);
   f=strlen(s1);g=strlen(s2);
   for(t=0;t<30;t++)
   {n[t]=0;m[t]=0;}
   a=0;b=0;k=0;s=0;
  readnumber(s1,n);
  readnumber(s2,m);
  printf("case #%d:\n",i);
  add(n,m,c);
  }   
}