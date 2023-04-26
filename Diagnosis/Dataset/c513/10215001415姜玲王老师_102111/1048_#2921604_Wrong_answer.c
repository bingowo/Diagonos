#include <stdio.h>
#include <stdlib.h>
void transfer(char*a,int*b)
{while(*a)
{int sign=1,number=0,d;
if(*a=='+'){a++;}
if(*a=='-'){a++;sign=-1;}
while(*a>='0'&&*a<='9')
{number*=10;number+=*a-'0';a++;}
if(number==0) {number=1;}
if(*a!='x') {b[0]=number*sign;return;}
a++;
if(a=='^'){a++;while(*a>='0'&&*a<='9')
{d*=10;d+=*a-'0';a++;}
b[d]=number*sign;}
else{a[1]=sign*number;}}}
void multiply(char*a,char*b,char*c)
{for(int i=0;i<50;i++)
for(int j=0;j<50;j++)
{c[i+j]+=a[i]*b[j];
}
}
int main()
{char a1[101];char a2[101];

while(scanf("%s%s",a1,a2)==2)
{int c1[51]={0},c2[52]={0},c0[52]={0};
transfer(a1,c1);
transfer(a2,c2);
multiply(c1,c2,c0);
for(int k=50;k<=0;k--)
{if(c0[k]) printf("%d ",c0[k]);
}
printf("\n");
}
}
