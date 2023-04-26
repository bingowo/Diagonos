#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print(int num){
if(num>=0&&num<=25){
printf("%c",num-0+'A');
}else if(num>=26&&num<=51){
printf("%c",num-26+'a');
}else if(num>=52&&num<=61){
printf("%c",num-52+'0');
}else if(num==62) printf("+");
else if(num==63) printf("/");



}
int main(){
int t;
scanf("%d",&t);
getchar();
for(int i=0;i<t;i++){
printf("case #%d:\n",i);
char a[101]={0};
char c;
int j=0;
while((c=getchar())!='\n'){
a[j]=c;
j++;
}
if(j%3==0){
for(int k=0;k<j/3;k++){
int m,n;
n=(int)a[k*3];
m=n;
n=(int)a[k*3+1];
m=m<<8;
m=m+n;
n=(int)a[k*3+2];
m=m<<8;
m=m+n;
int o;
o=m>>18;
print(o);
o=(m>>12)&(~((~0)<<6));
print(o);
o=(m>>6)&(~((~0)<<6));
print(o);
o=m&(~((~0)<<6));
print(o);
}
printf("\n");
}
else if(j%3==1){
for(int k=0;k<j/3;k++){
int m,n;
n=(int)a[k*3];
m=n;
n=(int)a[k*3+1];
m=m<<8;
m=m+n;
n=(int)a[k*3+2];
m=m<<8;
m=m+n;
int o;
o=m>>18;
print(o);
o=(m>>12)&(~((~0)<<6));
print(o);
o=(m>>6)&(~((~0)<<6));
print(o);
o=m&(~((~0)<<6));
print(o);
}
int m;
m=(int)a[j-1];
m=m<<4;
int o;
o=m>>6;
print(o);
o=m&(~((~0)<<6));
print(o);
printf("==\n");
}else if(j%3==2){
for(int k=0;k<j/3;k++){
int m,n;
n=(int)a[k*3];
m=n;
n=(int)a[k*3+1];
m=m<<8;
m=m+n;
n=(int)a[k*3+2];
m=m<<8;
m=m+n;
int o;
o=m>>18;
print(o);
o=(m>>12)&(~((~0)<<6));
print(o);
o=(m>>6)&(~((~0)<<6));
print(o);
o=m&(~((~0)<<6));
print(o);
}
int m,n;
m=(int)a[j-2];
n=(int)a[j-1];
m=m<<8;
m=m+n;
m=m<<2;
int o;
o=m>>12;
print(o);
o=(m>>6)&(~((~0)<<6));
print(o);
o=m&(~((~0)<<6));
print(o);
printf("=\n");

}
}
return 0;

}
