#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[127]={0};
int cmp(const void*e1,const void* e2){
char* m;
char* n;
m=(char*)e1;
n=(char*)e2;
int r=0;
for(int i=0;(m[i]!=0&&n[i]!=0);i++){
char n1,n2;
if(m[i]<='z'&&m[i]>='a') n1=m[i]-32;
else n1=m[i];
if(n[i]<='z'&&n[i]>='a') n1=n[i]-32;
else n2=n[i];
if(a[n1]>a[n2]) r=1;
else if(a[n1]<a[n2]) r=-1;

}
if(r==0) r=strlen(m)-strlen(n) ;
return r;





}





int main()
{


int flag=1;
while(flag){
 for(int i=0;i<127;i++){
    a[i]=0;
 }
int b[28];
int c[100][21];
int j=0;
char d;
scanf("%s",b);
getchar();
for(int i=0;i<27;i++){
a[b[i]]=i;
}
while(((flag=scanf("%s",c[j]))!=EOF)&&((d=getchar())!='\n')){
j++;
}
qsort(c,j,sizeof(c[0]),cmp);
for(int i=0;i<j;i++){
printf("%s ",c[i]);
}
}
}


