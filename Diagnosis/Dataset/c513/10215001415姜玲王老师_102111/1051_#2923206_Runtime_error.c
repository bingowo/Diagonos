#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char a[65]={"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"};
void two(char*p1,int*p2)
{char p[101];
strcpy(p,p1);
for(int i=0;i<strlen(p1);i++)
{for(int k=0;p[i];k++)
{p2[8+8*i-k-1]=p[i]%2;
p[i]/=2;}
}
}
void base64(int*p,int q)
{char a[65]={"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"};
    for(int k=0;k<q;k++)
{int sum=0;
for(int i=0;i<6;i++)
{sum*=2;
sum+=p[k*6+i];
}
printf("%c",a[sum]);
}
}
int main()
{int n,k,j;
scanf("%d",&n);
for(int i=0;i<n;i++)
{printf("case #%d:\n",i);
char b[101];
int c[801]={0};
scanf("%s",b);
two(b,c);
k=strlen(b);
if((k*8)%6==0) j=(k*8)/6;
else j=(k*8)/6+1;
base64(c,j);
if(j%4){for(int v=0;v<4-(j%4);v++) printf("=");}
printf("\n");
}
return 0;}
