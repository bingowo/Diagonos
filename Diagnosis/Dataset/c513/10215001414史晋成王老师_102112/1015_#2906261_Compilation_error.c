#include<stdio.h>
#include<stdlib.h>
void add(int* a,int* b,int* c)
{int prime[26]=
{97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2},i=0,j=0,d=0,digit=0;
  while(a[d]&&b[d])
  { c[d]=a[d]+b[d]+digit;
    digit=c[d]/prime[d];
    c[d]=c[d]%prime[d];
    d++;
      }
      c[d]+=digit;
      for(i=0;i<d-1;i++)
      printf("%d,",c[d-1-i]);
      printf("%d\n",c[d-1-i]);
}
int main()
{ int a=0,b=0,j,T,i,n[30]={0},m[30]={0},c[30]={0},k,s,f,g;
 char s1[60],s2[60];
  scanf("%d",&T);
  for(i=0;i<T;i++)
  {scanf("%s %s",s1,s2);
   f=strlen(s1);g=strlen(s2);
   a=0;b=0;k=0;s=0;
  while(s1[a])
  {n[k]=s1[f-1-a]-'0';
   a+=2; k+=1;   
  }
  while(s2[b])
  {m[s]=s2[g-1-b]-'0';
   b+=2; s+=1;   
  }
  printf("case #%d:\n",i)
  add(n,m,c);
  }   
}