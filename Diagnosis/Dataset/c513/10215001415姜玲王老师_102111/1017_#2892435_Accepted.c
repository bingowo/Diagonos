#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{long long sum=0,digit=1;
int k=0,i=0,j;
int number[130];
long long each[51];
number['I']=1;
number['V']=5;
number['X']=10;
number['L']=50;
number['C']=100;
number['D']=500;
number['M']=1000;
char s[51];
scanf("%s",s);
for(i=0;k<strlen(s);)
{if(s[k]=='(') {k++;digit*=1000;continue;}
if(s[k]==')') {k++;;digit/=1000;continue;}
each[i++]=number[s[k]]*digit;k++;}
for(j=0;j<i-1;j++)
{if(each[j]<each[j+1]) sum-=each[j];
else sum+=each[j];}
sum+=each[j];
printf("%lld",sum);}
