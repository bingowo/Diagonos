#include<stdio.h>
#include<string.h>
void cmp(char*s)
{ int i=0,t,c;
 c=strlen(s);
 for(i=0;i<c-1;i++)
 {if(s[i]<s[i+1])
     {t=s[i];
      s[i]=s[i+1];
      s[i+1]=t;
     }
  }
}

int main()
{ int m,n,i=0;
 char s[10000];
 n=strlen(s);
 scanf("%d %d",&n,&m);
 for(i=0;i<n;i++)
 scanf("%d ",&s[i]);
  int j=1;
 cmp(s);
  int sum=0,min;
 for(j=1;j<m;j++)
 {sum+=s[j];}
  min=(m-1)*s[0]-sum;
  printf("%d",min);
  return 0;
}
