#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int cmp(char*a)
{if(!strcmp(a,"the")) return 0;
if(!strcmp(a,"tHe")) return 0;
if(!strcmp(a,"thE")) return 0;
if(!strcmp(a,"THe")) return 0;
if(!strcmp(a,"tHE")) return 0;
if(!strcmp(a,"ThE")) return 0;
if(!strcmp(a,"THE")) return 0;
if(!strcmp(a,"The")) return 0;
if(!strcmp(a,"a")) return 0;
if(!strcmp(a,"A")) return 0;
if(!strcmp(a,"an")) return 0;
if(!strcmp(a,"An")) return 0;
if(!strcmp(a,"AN")) return 0;
if(!strcmp(a,"of")) return 0;
if(!strcmp(a,"Of")) return 0;
if(!strcmp(a,"OF")) return 0;
if(!strcmp(a,"Of")) return 0;
if(!strcmp(a,"for")) return 0;
if(!strcmp(a,"fOr")) return 0;
if(!strcmp(a,"foR")) return 0;
if(!strcmp(a,"FOr")) return 0;
if(!strcmp(a,"fOR")) return 0;
if(!strcmp(a,"FoR")) return 0;
if(!strcmp(a,"FOR")) return 0;
if(!strcmp(a,"For")) return 0;
if(!strcmp(a,"and")) return 0;
if(!strcmp(a,"aNd")) return 0;
if(!strcmp(a,"anD")) return 0;
if(!strcmp(a,"ANd")) return 0;
if(!strcmp(a,"aND")) return 0;
if(!strcmp(a,"AnD")) return 0;
if(!strcmp(a,"AND")) return 0;
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
