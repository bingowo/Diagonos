#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define length 130

struct data{
    char q;
   char ss[length];
};

int cmp(const void* a,const void* b){
    struct data x=*(struct data*)a;
    struct data y=*(struct data*)b;
    if(x.q==y.q&&x.q=='+'){
    if(strlen(x.ss)==strlen(y.ss))return strcmp(y.ss,x.ss);
    else return strlen(x.ss)<strlen(y.ss);
    }
    if(x.q==y.q&&x.q=='-'){
    if(strlen(x.ss)==strlen(y.ss))return strcmp(x.ss,y.ss);
    else return strlen(x.ss)>strlen(y.ss);
    }
    if(x.q=='+'&&y.q=='-')return -1;
    if(x.q=='-'&&y.q=='+')return 1;
}

void minus(char a1[],char b1[]){
int a[strlen(a1)+1],b[strlen(a1)+1];
a[0]=0;
for(int i=strlen(a1);i>=1;i--){
    a[i]=a1[i-1]-48;
}
b[0]=0;
for(int i=1;i<(strlen(a1)-strlen(b1)+1);i++){
    b[i]=0;
}

for(int i=strlen(a1)-strlen(b1)+1;i<strlen(a1)+1;i++){
    b[i]=b1[i-strlen(a1)+strlen(b1)-1]-48;
}

for(int i=strlen(a1);i>=0;i--){
a[i]=a[i]-b[i];
if(a[i]<0){
    a[i]=a[i]+10;
    a[i-1]=a[i-1]-1;
    }
}
int j=0;
for(;j<=strlen(a1);j++){
    if(a[j]!=0)break;
}
//if(j==strlen(a1)+1)printf("0");
for(;j<=strlen(a1);j++){
    printf("%d",a[j]);
}
printf("\n");
}

void plus(char a1[],char b1[]){
int a[strlen(a1)+1],b[strlen(a1)+1];
a[0]=0;
for(int i=strlen(a1);i>=1;i--){
    a[i]=a1[i-1]-48;
}
b[0]=0;
for(int i=1;i<(strlen(a1)-strlen(b1)+1);i++){
    b[i]=0;
}

for(int i=strlen(a1)-strlen(b1)+1;i<strlen(a1)+1;i++){
    b[i]=b1[i-strlen(a1)+strlen(b1)-1]-48;
}

for(int i=strlen(a1);i>=0;i--){
a[i]=a[i]+b[i];
if(a[i]>=10){
    a[i]=a[i]-10;
    a[i-1]=a[i-1]+1;
    }
}
int j=0;
for(;j<=strlen(a1);j++){
    if(a[j]!=0)break;
}
//if(j==strlen(a1)+1)printf("0");
for(;j<=strlen(a1);j++){
    printf("%d",a[j]);
}
printf("\n");
}

int main(){
    int n;
    scanf("%d",&n);
    struct data p[n];
    for(int i=0;i<n;i++){
        scanf("%s",p[i].ss);
        if(p[i].ss[0]=='-')p[i].q='-';
        else p[i].q='+';
    }
    qsort(p,n,sizeof(p[0]),cmp);
    /*printf("\n");
    for(int i=0;i<n;i++){
        printf("%s\n",p[i].ss);
    }*/
    if(p[0].q==p[n-1].q&&p[0].q=='+')minus(p[0].ss,p[n-1].ss);
    if(p[0].q==p[n-1].q&&p[0].q=='-'){
        p[0].ss[0]='0';
        p[n-1].ss[0]='0';
        minus(p[n-1].ss,p[0].ss);
    }
    if(p[0].q!=p[n-1].q){
        p[n-1].ss[0]='0';
        plus(p[0].ss,p[n-1].ss);
    }

}
