#include <stdio.h>
#include<stdlib.h>
#include <string.h>
int cmp1(char *a){
int sum=0;
int r=0;
int l=strlen(a);
for(int i=0;i<l;i++)
    {if(a[i]>'0'&&a[i]<'9')
    sum=sum*10+a[i]-'0';r=1;}
    if(r==0)return-1;
    else return sum;
}
int cmp2(const void*a,const void*b){
  int num1,num2;
  char*str1;char*str2;
  str1=*(char(*)[100])a;
  str2=*(char(*)[100])b;
  num1=cmp1(str1);
  num2=cmp1(str2);
  if(num1==num2)
  return strcmp(str1,str2);
  else
    return num1-num2;
  }
int main(){
char a[100][100];
int n=0;
while (scanf("%s",a[n])!=EOF)
n++;
qsort(a,n,sizeof(a[0]),cmp2);
for(int i=0;i<n;i++)
printf("%s ",a[i]);
return 0;





}