#include<stdio.h>
#include<string.h>

int max(long long int *s)
{int n,i;
 n=strlen(s);
 for(i=0;i<n-1;i++)
 {if(s[i]>s[i+1]) return s[i];
  else return s[i+1];
 }
}

int min(long long int*s,int m)
{int n,c;
 n=strlen(s);
 c=max(s);
 
 
 
 
}
int main()
{int n,m,i=0;
 long long int s[1000000000000];
 scanf("%d %d\n",&n,&m);
 for(i=0;i<n;i++)
 scanf("%lld ",&s[i]);
 
 
 



}