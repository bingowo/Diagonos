#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
char a[51];
scanf("%s",a);
int n=strlen(a);
int max=0;
for(int i=0;i<n;i++){
    int num=0;
for(int j=i;j<n;j++){
if(a[j]!=a[j+1]&&a[j+1]!=0){
num++;
}else{
 num++;

     break;
}
}
 if(num>max) max=num;
}

printf("%d",max);
}
