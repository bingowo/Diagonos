#include <stdlib.h>
#include<string.h>
void multiply(int*a,int b)
{int i,temp,d=0,k;
for(k=1999;a[k]==0;k--);
for(i=0;i<=k;i++)
{temp=a[i]*b+d;
a[i]=temp%10;
d=temp/10;}
while(d){a[i]=d%10;i++;d/=10;}
}
int main()
{char a[1001];
int b[1001];
int c[2000]={0};
int i;
scanf("%s",a);
for(i=0;i<strlen(a);i++)
{if(i==0&&strlen(a)==1){b[0]=1;continue;}
if(i==0&&a[i+1]!=a[i]){b[0]=2;continue;}
if(i==0&&a[i+1]==a[i]){b[0]=1;continue;}
if(i==strlen(a)-1&&a[i-1]==a[i]){b[i]=1;continue;}
if(i==strlen(a)-1&&a[i-1]!=a[i]){b[i]=2;continue;}
if(a[i+1]==a[i]&&a[i-1]==a[i]){b[i]=1;continue;}
if(a[i+1]!=a[i]&&a[i-1]!=a[i]&&a[i-1]!=a[i+1]){b[i]=3;continue;}
b[i]=2;
}
c[0]=1;
for(i=0;i<strlen(a);i++)
multiply(c,b[i]);
for(i=1999;c[i]==0&&i>0;i--);
for(;i>=0;i--)
{printf("%d",c[i]);
}

}
