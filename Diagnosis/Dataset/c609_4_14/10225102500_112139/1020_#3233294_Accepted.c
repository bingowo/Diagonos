#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*e1,const void* e2){
char* m;
char* n;
m=(char*)e1;
n=(char*)e2;
int flag1=0,flag2=0;
int sum1=-1;
int sum2=-1;
for(int i=0;m[i]!=0;i++){
if(m[i]<='9'&&m[i]>='0'){
if(flag1==0) sum1=sum1+1+m[i]-'0';
else sum1=10*sum1+m[i]-'0';
flag1=1;
}}
for(int i=0;n[i]!=0;i++){
if(n[i]<='9'&&n[i]>='0'){
if(flag2==0) sum2=sum2+1+n[i]-'0';
else sum2=10*sum2+n[i]-'0';
flag2=1;
}}
if(sum1>sum2) return 1;
else if(sum2>sum1) return -1;
else return strcmp(m,n);
}





int main()
{char a[101][31]={0};
int k=0;
while (scanf("%s",a[k])!=EOF){
k++;
}
qsort(a,k,sizeof(a[0]),cmp);
for(int j=0;j<k;j++){
printf("%s ",a[j]);
}
}

