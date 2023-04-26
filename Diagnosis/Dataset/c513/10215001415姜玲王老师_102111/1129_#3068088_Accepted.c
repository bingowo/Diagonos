#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
int main()
{char a[10001],temporary[10001],number[4],p[10001];
int j,i,k,s;
    scanf("%s",a);

for(j=0;j<strlen(a);j++)
{s=0;
    if(isdigit(a[j]))
{s=1,i=0;
    for(i=0;isdigit(a[j])&&isdigit(a[j+1]);j++,i++) number[i]=a[j];
if(isdigit(a[j])) number[i]=a[j];
number[i+1]=0;
k=atoi(number);
}
if(isalpha(a[j]))
    {for(i=0;isalpha(a[j])&&isalpha(a[j+1]);j++,i++) temporary[i]=a[j];
if(isalpha(a[j])) temporary[i]=a[j];
temporary[i+1]=0;    }

if(s==1){while(--k) { printf("%s",p);}}
else {strcpy(p,temporary);printf("%s",p);}}
return 0;
}