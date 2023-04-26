#include <stdio.h>
#include <stdlib.h>

int main()
{int n=0;
scanf("%d",&n);
for(int i=0;i<n;i++){
char a[100]={0};
scanf("%s",a);
int j=0;
int sum=0;
for(j=0;a[j]!=0;j++){
int x=0;
if(a[j]=='-') x=-1;
else x=a[j]-'0';
sum=sum*3+x;
}
printf("case #%d:\n%d\n",i,sum);
}
return 0;
}
