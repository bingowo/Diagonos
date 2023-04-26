#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
int main()
{int n,i,j,k=0,m=0;
int num[25]={2,3,5,7,9,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91,97};
char s[100];
int a[26]={0};
int b[26]={0};
scanf("%d",&n);
for(i=0;i<n;i++)
{scanf("%s",s);
for(j=0;j<strlen(s);j++)
{if(s[j]!=',')
{for(;s[j]>='0'&&s[j]<='9'&&j<strlen(s);j++)
{a[k]=a[k]*10+s[j]-'0';}
k++;}
}
scanf("%s",s);
for(j=0;j<strlen(s);j++)
{if(s[j]!=',')
{k=0;
for(;s[j]>='0'&&s[j]<='9'&&j<strlen(s);j++)
{b[m]=b[m]*10+s[j]-'0';}
m++;}
}
}
for(int one=0;one<k;one++){printf("%d",a[one]);}}

