#include <stdio.h>
#include <stdlib.h>
int cmp1(const void*a,const void*b){
    int num1=*(int*)a;
    int num2=*(int*)b;
    return num1-num2;}
int cmp2(const void*a,const void*b){
    int num1=*(int*)a;
    int num2=*(int*)b;
    return num2-num1;}
int main(){
char ad;
scanf("%c",&ad);
int a[1000];
int i=0;
int n,k;
k=0;
int s[1000];
while(scanf("%d",&n)!=EOF){
    a[i++]=n;
}
if(ad=='A')
qsort(a,i,sizeof(a[0]),cmp1);
else qsort(a,i,sizeof(a[0]),cmp2);
for(int z=0;z<i;z++){
    if(a[z]!=a[z+1]){
        s[k]=a[z];k++;}
    else {s[k]=a[z+1];}
        }
for(int j=0;j<k;j++)
printf("%d ",s[j]);
return 0;

}
