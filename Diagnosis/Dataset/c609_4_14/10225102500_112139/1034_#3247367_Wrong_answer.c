#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
char a[100001];
int num=0;
scanf("%s",a);
for(int i=1;i<100001;i++){


if(a[i]=='x'&&a[i-1]=='0'){

unsigned int sum;
sum=0;
for(int k=i+1;k<100001;k++){
int n;
if(a[k]>='0'&&a[k]<='9'){
n=a[k]-'0';
}else if(a[k]>='a'&&a[k]<='f'){
n=a[k]-'a'+10;
}else{
break;
}
sum=sum*16+n;
}
printf("%u ",sum);
num++;
}

}
if(num==0) printf("-1");
return 0;
}
