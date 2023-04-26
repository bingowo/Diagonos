#include<stdio.h>
#include<string.h>
int main(){
int n;
scanf("%d",&n);
for(int i=0;i<n;i++)
  {printf("case #%d:\n",i);
char a[100];
scanf("%s",a);
int l=strlen(a);
double m=0;
for(;l>1;l--)
   m=m*0.125+a[l]-'0';
printf("%lf",m);
  }
}
