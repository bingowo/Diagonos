#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void plus(int p[1100],int q[1100]){
    for(int i=0;i<=1099;i++){
        p[i]=p[i]+q[i];
    }
    for(int i=1099;i>=0;i--){
        p[i-1]=p[i-1]+p[i]/10;
        p[i]=p[i]%10;
    }
}

int pd(int p1[1100],int lens){
    unsigned long long int sum=0;
    for(int i=0;i<lens;i++){
        sum=sum+p1[i];
    }
    if(sum%9==0)return 1;
    else return 0;
}

int main(){
    int p[1100];
    p[0]=0;
    char s[1100];
    scanf("%s",s);
    int len=strlen(s)+1;
    for(int i=1;i<len;i++){
        p[i]=s[i-1]-48;
    }
    for(int i=len;i<1100;i++){
        p[i]=0;
    }
    int q1[1100];
    q1[len-1]=1;
    plus(p,q1);
    while(pd(p,len)){
        plus(p,q1);
    }
    for(int i=len-1;i>=0;i--){
        if(p[i]==9){
            int q[1100];
            for(int j=0;j<1100;j++){
                q[j]=0;
            }
            q[i]=1;
            plus(p,q);
            for(int k=i+1;k<=len;k++){
                p[k]=0;
            }
        }
    }
    if(p[0]!=0)printf("%d",p[0]);
    for(int i=1;i<len;i++){
        printf("%d",p[i]);
        }
    return 0;

}