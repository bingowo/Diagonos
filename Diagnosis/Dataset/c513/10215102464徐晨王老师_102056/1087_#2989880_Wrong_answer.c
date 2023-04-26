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

int pd(int p4[1100],int lens){
    for(int i=1;i<lens;i++){
        if(p4[i]==p4[i-1])return 1;
    }
    return 0;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
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
        int p3[1100]={0};
        p3[len-1]=1;
        plus(p,p3);
        while(pd(p,len)){
        for(int i=len-1;i>0;i--){
            int p2[1100]={0};
            p2[i]=1;
            if(i<(len-1)){
            while(p[i]==p[i-1]||p[i]==p[i+1]){
                plus(p,p2);
            }
            }
            else{
            while(p[i]==p[i-1]){
                plus(p,p2);
            }
            }
        }
        }
        int p1[1100];
        p1[0]=0;
        for(int i=1;i<len;i++){
            p1[i]=s[i-1]-48;
        }
        for(int i=len;i<1100;i++){
            p1[i]=0;
        }
        for(int j=0;j<len;j++){
            if(p1[j]<p[j]){
            int flag=1;
            p[j]=p1[j]+1;
            if(p[j]==p[j-1])p[j]=p1[j]+1;
            for(int i=j+1;i<len;i++){
                if(flag==1){
                    p[i]=0;
                    flag=-flag;
                }
                else{
                    p[i]=1;
                    flag=-flag;
                }
            }
            break;
        }
        }
        
        
        printf("case #%d:\n",t);
        if(p[0]!=0)printf("%d",p[0]);
        for(int i=1;i<len;i++){
            printf("%d",p[i]);
        }
        printf("\n");
    }
    return 0;
}