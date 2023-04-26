#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
int a;int b;
scanf("%d%d",&a,&b);
char n[32]="\0";
int i=0;
while(a!=0){
    int j=a%b;
    a/=b;
    if(j<0){
        j-=b;
        a+=1;
    }
    if(j>=10){
        n[i++]='A'+(j-10);
    }else{n[i++]='0'+j;}
}
    if(i==0){
        n[i++]='0';
    }
    if(b<0&&i>0){
        n[i++]='-';
    }
    int t=0;int k=i-1;
    while(j<k){
        char q=n[t];
        n[t++]=n[k];
        n[k--]=q;
    }
    printf("%s\n",n);
    }
    return 0;

}
