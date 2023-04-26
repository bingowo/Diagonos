#include<stdio.h>
#include<stdlib.h>
int solve(char*s)
{ if(*s==*(s+1)) return 1;
  else
  { if (*s=='{'&&*(s+1)=='[') solve(s+1);
    else if(*s=='['&&*(s+1)=='(') solve(s+1);
    else if (*s=='('&&*(s+1)=='{') solve(s+1);
    else  return -1;
      
  }
}
int main()
{ int i,j,t,n;
char s[200];
scanf("%d",&t);
for(i=0;i<t;i++)
{gets(s);
i=solve(s);
if(i==1) printf("Yes\n");
else if(i==-1) printf("No\n");
}
}