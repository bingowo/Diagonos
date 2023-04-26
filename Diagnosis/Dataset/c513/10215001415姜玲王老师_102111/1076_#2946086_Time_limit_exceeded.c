#include <stdio.h>
#include <stdlib.h>
int main()
{int n,flag;
scanf("%d",&n);
for(int i=0;i<n;i++)
{char a[100];
scanf("%s",a);
flag=0;
int k=1;
for(int i=0;i<strlen(a);i++)
{if(i<k) k=1;
switch(a[i])
{case('(') :{if(a[i-k]=='{') {flag=1;}break;}
case(')') :{if(a[i-k]=='(') k+=2;else flag=1;break;}
case('{') :{if(a[i-k]=='[') {flag=1;}break;}
case('}') :{if(a[i-k]='{') k+=2;else flag=1;break;}
case('[') :{if(a[i-k]=='(') {flag=1;}break;}
case(']') :{if(a[i-k]=='[') k+=2;else flag=1;break;}}
if(flag!=0) break;
}
if(flag==0) printf("Yes\n");
else printf("No\n");
}
}
