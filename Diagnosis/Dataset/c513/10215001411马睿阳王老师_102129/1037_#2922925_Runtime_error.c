#include<stdio.h>
#include<string.h>
void cmp(char*s)
{ int i=0,t,c;
 c=strlen(s);
 for(i=0;i<c;i++)
 {if(s[i]<s[i+1])
     {t=s[i];
      s[i]=s[i+1];
      s[i+1]=t;
     }
  }
}

int main()
{ int m,n,i=0;
 char s[1000000000000];
 scanf("%lldd %lld\n",&n,&m);
 for(i=0;i<n;i++)
 scanf("%d ",&s[i]);
  int j=1;
 n=strlen(s);
 cmp(s);
  int sum=0,min;
 for(j=1;j<m;j++)
 {sum+=s[j];}
  min=s[0]-sum;
  printf("%d",min);
  return 0;
}
