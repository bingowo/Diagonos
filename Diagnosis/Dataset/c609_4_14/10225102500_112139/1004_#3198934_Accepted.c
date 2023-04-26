#include <stdio.h>
#include <stdlib.h>

int main()
{int n=0;
scanf("%d ",&n);
char a[50]={0};
scanf("%s",a);
int sum=0;
for(int i=0;a[i]!=0;i++){
int x=0;
if('1'<=a[i]&&a[i]<='9') x=a[i]-'1'+1;
else if('A'<=a[i]&&a[i]<='Z') x=a[i]-'A'+10;
else if('a'<=a[i]&&a[i]<='z') x=a[i]-'a'+10;
sum=sum*n+x;
}
if(sum==0) printf("0");
else{
int n1;
scanf("%d",&n1);
int b[64]={0};
int k=0;
while(sum/n1>0){
b[k]=sum%n1;
k++;
sum=sum/n1;

}
b[k]=sum;
int j=0;
for( j=49;j>=0;j--){
if(b[j]!=0) break;
}

for(;j>=0;j--){
if(b[j]>9) printf("%c",b[j]-10+'A');
else printf("%d",b[j]);
}
return 0;
}
}
