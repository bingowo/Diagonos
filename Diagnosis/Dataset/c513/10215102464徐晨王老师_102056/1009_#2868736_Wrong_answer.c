#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trans(int m,int n){
if(n==0)return m;
else return trans(n,m%n);
}


int main() {
int T;
scanf("%d\n",&T);
char a[121];
for(int i=0;i<T;i++){
gets(a);
int b;
b=strlen(a);

int ret=0;
for(int j=0;j<b;j++){
    int num=1;
    for(int k=0;k<8;k++,num=num<<1){
    int m=a[j];
    if((m&num)==num)ret++;}

}

printf("%d/%d",ret/trans(b*8,ret),b*8/trans(b*8,ret));
}
return 0;
}
