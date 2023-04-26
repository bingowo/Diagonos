#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
char b[31];
void acculate(int n,char*a,int t,int*c)
{if(strstr(b,a)){c[0]+=pow(2,n-t);b[t-1]=0;return;}
if(t==n){b[t-1]=0;return;}
for(int k=0;k<2;k++)
{b[t]=k+'0';
acculate(n,a,t+1,c);}}

int main()
{int n,m;
while(scanf("%d%d",&n,&m)&&(n!=-1||m!=-1))
{int c[1]={0};
char a[31];
for(int i=0;i<m;i++) {a[i]='1';}
acculate(n,a,0,c);
printf("%d\n",c[0]);
}
}
