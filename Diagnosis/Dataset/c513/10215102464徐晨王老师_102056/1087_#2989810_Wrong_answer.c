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
        int p1[1100];
        strcpy(p1,p);
        for(int i=len-1;i>0;i--){
            int p2[1100]={0};
            p2[i]=1;
            while(p1[i]==p1[i-1]){
                plus(p1,p2);
            }
        }
        printf("case #%d:\n",t);
        if(p1[0]!=0)printf("%d",p1[0]);
        for(int i=1;i<len;i++){
            printf("%d",p1[i]);
        }
        printf("\n");
    }
    return 0;
}