#include <stdio.h>
#include <stdlib.h>

int main()
{int n;
scanf("%d",&n);
for(int i=0;i<n;i++)
{char a[501];
printf("case #%d:",i);
gets(a);
for(int k=0;k<strlen(a);k++)
{int sum=1;
for(k;a[k]==a[k+1];k++)
{sum+=1;
}
printf("%d%c",sum,a[k]);
}
printf("\n");
}
}
