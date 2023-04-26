#include <stdio.h>
#include <stdlib.h>
char p[100]={0};
int i=0;
void push(char a)
{p[i]=a;
i++;
}
void pop()
{p[i-1]=0;
i--;
}
int main()
{int n,flag;
scanf("%d",&n);
for(int i=0;i<n;i++)
{char a[100];
scanf("%s",a);
flag=0;
for(int i=0;i<strlen(a);i++)
{if(p[0]==0) {push(a[i]);continue;}
switch(a[i])
{case('(') :{if(p[i-1]=='{') {flag=1;}else {push(a[i]);}break;}
case(')') :{if(p[i-1]=='(') pop();else flag=1;break;}
case('{') :{if(p[i-1]=='[') {flag=1;}else {push(a[i]);}break;}
case('}') :{if(p[i-1]=='{') pop();else flag=1;break;}
case('[') :{if(p[i-1]=='(') {flag=1;}else {push(a[i]);}break;}
case(']') :{if(p[i-1]=='[') pop();else flag=1;break;}}
}
if(flag==0) printf("Yes\n");
else printf("No\n");
}
}
