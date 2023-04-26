#include <stdio.h>
#include <stdlib.h>
#include<string.h>
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
{char f[100]=0;
int n,flag,j,k;
scanf("%d",&n);
for( j=0;j<n;j++)
{char a[100];
scanf("%s",a);
flag=0;
i=0;
memset(p,0,sizeof(char)*100);
for(k=0;k<strlen(a);k++)
{if(p[0]==0) {push(a[k]);continue;}
switch(a[k])
{case('(') :{if(p[i-1]=='{'||p[i-1]=='(') {flag=1;}else {push(a[k]);}break;}
case(')') :{if(p[i-1]=='(') pop();else flag=1;break;}
case('{') :{if(p[i-1]=='['||p[i-1]=='{') {flag=1;}else {push(a[k]);}break;}
case('}') :{if(p[i-1]=='{') pop();else flag=1;break;}
case('[') :{if(p[i-1]=='('||p[i-1]=='[') {flag=1;}else {push(a[k]);}break;}
case(']') :{if(p[i-1]=='[') pop();else flag=1;break;}}
if(flag!=0) break;
}

if(flag==0&&!strcmp(p,f)) printf("Yes\n");
else printf("No\n");
}
}
