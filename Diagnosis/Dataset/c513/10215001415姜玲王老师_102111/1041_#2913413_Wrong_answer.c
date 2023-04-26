#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{char a[51];
scanf("%s",a);
int t=1,max=1;
for(int i=0;i<strlen(a)-1;i++)
{if(a[i]!=a[i+1])
{t++;
i++;
while(a[i]!=a[i+1]){t++;i++;}
if(t>max) max=t;
}
t=1;}
printf("%d",max);}
