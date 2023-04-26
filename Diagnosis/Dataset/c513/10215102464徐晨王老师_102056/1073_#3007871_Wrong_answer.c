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

int cmp(int p1[1100],int p2[1100]){
    for(int i=0;i<1100;i++){
        if(p1[i]!=p2[i])return 1;
    }
    return 0;
}

int main(){
    int p1[1100],p2[1100];
    for(int i=0;i<1100;i++){
        p1[i]=0;
        p2[i]=0;
    }
    char s1[20],s2[20];
    scanf("%s%s",s1,s2);
    int len1=strlen(s1)-1;
    for(int i=1099;;i--){
        p1[i]=s1[len1]-48;
        if(len1==0)break;
        len1--;
    }
    int len2=strlen(s2)-1;
    for(int i=1099;;i--){
        p2[i]=s2[len2]-48;
        if(len2==0)break;
        len2--;
    }
    int q1[1100];
    for(int i=0;i<1100;i++){
        q1[i]=0;
    }
    q1[1099]=1;
    plus(p2,q1);
    int sum[1100];
    for(int i=0;i<1100;i++){
        sum[i]=0;
    }
    sum[0]=1;
    int flag=0;
    do{
        // for(int i=0;i<1100;i++){
        //     printf("%d ",p1[i]);
        // }
        // printf("\n");
        // for(int i=0;i<1100;i++){
        //     printf("%d ",p2[i]);
        // }
        // printf("\n");
        flag=0;
        for(int i=0;i<1100;i++){
            if(p1[i]==9){
                flag=1;
                break;
            }
        }
        if(flag){plus(p1,q1);continue;}
        if(pd(p1,1100)){plus(p1,q1);continue;}
        plus(sum,q1);
        plus(p1,q1);
    }while(cmp(p1,p2));
    printf("%llu",sum);
    return 0;

}
