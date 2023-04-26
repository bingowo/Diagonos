#include <stdio.h>
#include <stdlib.h>

int main()
{int n=0;
scanf("%d",&n);
for(int i=0;i<n;i++){
char a[100]={0};
char b[128]={0};
char c[128]={0};
scanf("%s",a);
int flag=0;
for(int j=0;a[j]!=0;j++){
int x=0;
x=a[j];
if(b[x]==0){
if(flag==0){
c[x]=1;
}else if(flag==1){
c[x]=0;
}else{
c[x]=flag;
}
flag++;
}
b[x]++;

}
int num=0;
for(int k=0;k<128;k++){
if(b[k]>0) num++;
}
if(num==1) num=2;
long long  sum=0;
for(int l=0;a[l]!=0;l++){
int t;
t=a[l];
sum=sum*num+c[t];
}
printf("case #%d:\n%lld\n",i,sum);
}




return 0;
}