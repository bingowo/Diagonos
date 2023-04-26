#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{long long int answer=0;
int l,j,digit,k;
int value[128];
char string[61];
for(l=0;l<128;l++) value[l]=-1;
int number,i;
scanf("%d",&number);
for(i=0;i<number;i++)
{scanf("%s",string);
value[string[0]]=1;
digit=1;
for(j=1;j<strlen(string);j++)
{if (value[string[j]]==-1)
{if(digit==1)  {value[string[j]]=0;digit++;}
else {value[string[j]]=digit;digit++;}  }
}
for(k=0;k<j;k++)
{answer=answer*10+value[string[k]];
}
printf("case #%d:\n",i);
printf("%lld\n",answer);}}
