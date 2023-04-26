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
{scanf("%s\n",s);
j=solve(s);
if(j==1) printf("Yes\n");
else if(j==-1) printf("No\n");
memset(s,o,sizeof(s));
}
}