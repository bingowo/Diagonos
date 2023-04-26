#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{int n;
scanf("%d",&n);
getchar();
for(int i=0;i<n;i++)
{char a[501];
printf("case #%d:\n",i);
gets(a);
for(int k=0;k<strlen(a);k++)
{int sum=1;
for(;a[k]==a[k+1]&&sum<255;k++)
{sum+=1;
}
printf("%d%c",sum,a[k]);
}
printf("\n");
}
}
