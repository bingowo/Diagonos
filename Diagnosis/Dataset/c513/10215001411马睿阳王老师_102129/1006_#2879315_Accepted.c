#include<stdio.h>
#include<string.h>
int main()
{int T,i,b,j;char a[1000]; 
scanf("%d",&T); 

for(i=0;i<T;i++) {

scanf("%s",a);

j=0,b=0;
 while (a[j]) 
 { if(a[j]=='-') { b=b*3-1;} 
 else if(a[j]=='1'){b=b*3+1;} 
 else { b=b*3;} 
 j++; 
 
 } 
printf("case #%d:\n",i);
 printf("%d\n",b); }
 return 0;
}