#include <stdio.h>
#include <stdlib.h>
#include<string.h>
unsigned long long trans()
{unsigned long long k=0;
int l;
    char s[10000];
    scanf("%s",s);
    for(l=0;l<strlen(s);l++)
    {switch(s[l])
    {case '1':k=k*3+1;break;
    case '0':k=k*3;break;
    case '-':k=k*3-1;break;}}
return k;}
int main()
{int n,i;
scanf("%d",&n);
for(i=0;i<n;i++)
{printf("case #%d:\n",i);
printf("%llu\n",trans());
}
}
