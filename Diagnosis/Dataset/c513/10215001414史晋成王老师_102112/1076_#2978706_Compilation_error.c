#include<stdio.h>
#include<stdlib.h>
int a[10000];
int l;
char c[500];
int solve(char*s)
{   if(a[*s]==a[*(c+l-(s-c)-1)]-1)
  { if (*s=='{'&&*(s+1)=='[') solve(s+1);
    else if(*s=='['&&*(s+1)=='(') solve(s+1);
    else if (*s=='('&&*(s+1)=='{') solve(s+1);
    else if (a[*s]==a[*(s+1)]&&(s-c)==l-(s-c)-2)
    else  return -1;
      
  }
  else return -1;
}
int main()
{ int i,j,t,n;
a['(']=1; a[')']=2;
a['{']=3; a['}']=4;
a['[']=5; a[']']=6;
scanf("%d",&t);
for(i=0;i<t;i++)
{scanf("%s\n",c);
l=strlen(c);
j=solve(c);
if(j==1) printf("Yes\n");
else if(j==-1) printf("No\n");
memset(c,0,sizeof(c));
}
}