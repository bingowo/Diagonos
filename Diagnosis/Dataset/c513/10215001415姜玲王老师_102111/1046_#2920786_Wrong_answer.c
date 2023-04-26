#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int cmp(char*a)
{if(!strcmp(a,"the")) return 0;
if(!strcmp(a,"a")) return 0;
if(!strcmp(a,"an")) return 0;
if(!strcmp(a,"of")) return 0;
if(!strcmp(a,"for")) return 0;
if(!strcmp(a,"and")) return 0;
if(!strcmp(a,"The")) return 0;
if(!strcmp(a,"A")) return 0;
if(!strcmp(a,"An")) return 0;
if(!strcmp(a,"Of")) return 0;
if(!strcmp(a,"For")) return 0;
if(!strcmp(a,"And")) return 0;
return 1;
}
int main()
{int n;
char a[101];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
{int sum=0;
printf("case #%d:\n",i);
do{scanf("%s",a);
sum+=cmp(a);}
while(getchar()!='\n');
printf("%d\n",sum);

}}
