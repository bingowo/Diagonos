#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*e1,const void* e2){
char* m=(char*)e1;
char* n=(char*)e2;
int i,j;
int num1=0,num2=0;
int flag1=0,flag2=0;
for(i=0;i<31;i++){
if(m[i]<='9'||m[i]>='0'){
flag1=1;
break;
}}
for(j=30;j>=0;j--){
if(m[j]<='9'||m[j]>='0'){
flag1=1;
break;
}
}
if(flag1==0) num1=-1;
else{
for(;i<=j;i++){
num1=num1*10+m[i]-'0';

}


}
for(i=0;i<31;i++){
if(n[i]<='9'||n[i]>='0'){
flag2=1;
break;
}}
for(j=30;j>=0;j--){
if(n[j]<='9'||n[j]>='0'){
flag2=1;
break;
}
}
if(flag2==0) num2=-1;
else{
for(;i<=j;i++){
num2=num2*10+n[i]-'0';

}


}
if(num1>num2) return 1;
else if(num1<num2) return -1;
else return strcmp(m,n);
}
int main()
{ char a[100][31];
int k=0;
while(scanf("%s",a[k])){
k++;
}
qsort(a,k,sizeof(char*),cmp);
for(int l=0;l<k;l++){
printf("%s",a[l]);
}
}
