#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void mutiply(char*b,char*a, char*c)
{int i=strlen(b),k=strlen(a),l,m,d,temp;
for(l=0;l<i;l++)
{d=0;
for(m=0;m<k;m++)
{if(c[l+m]>='0') c[l+m]-='0';
temp=(b[l]-'0')*(a[m]-'0')+d+c[l+m];
c[l+m]=temp%10+'0';
d=temp/10;}
c[l+m]+=d;}
if(c[l+m-1]){c[l+m-1]+='0';}
}
int main()
{int t,i,n,k,m,j;
char a[2],b[100]={0},c[100]={0};
scanf("%d",&t);
for(i=0;i<t;i++)
{printf("case #%d:\n",i);
scanf("%s%d",a,&n);
if(n==0){printf("1\n");continue;}
b[0]='1';
for(k=0;k<n;k++)
{memset(c,0,sizeof(char)*100);
mutiply(b,a,c);
strcpy(b,c);}
m=strlen(c);
for(i=m-1;i>=0;i--)
printf("%c",c[i]);
printf("\n");

}
}
