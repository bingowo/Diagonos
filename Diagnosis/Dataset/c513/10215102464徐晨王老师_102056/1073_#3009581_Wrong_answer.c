#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned long long int llu;
llu p[18][180];
llu find(int index,int d[18],llu sum,int flag){
    if(index==-1){
        if(sum%9==0){
            return 0;
        }
        else return 1;
    }
    if(p[index][sum]!=-1){
        return p[index][sum];
    }
    if(d[index]==9){
        return 0;
    }
    int ret=0;
    if(flag==1){
        for(int i=0;i<d[index];i++){
            ret=ret+find(index-1,d,sum+i,1);
        }
        ret=ret+find(index-1,d,sum+d[index],0);
    }
    else if(flag==0){
        for(int i=0;i<9;i++){
            ret=ret+find(index-1,d,sum+i,1);
        }
    }
    p[index][sum]=ret;
    return ret;
}
int main(){
    for(int i=0;i<18;i++){
        for(int j=0;j<180;j++){
            p[i][j]=-1;
        }
    }
    char s1[20],s2[20];
    scanf("%s%s",s1,s2);
    int p1[20],p2[20];
    for(int i=0;i<strlen(s1);i++){
        p1[strlen(s1)-1-i]=s1[i]-48;
    }
    for(int i=0;i<strlen(s2);i++){
        p2[strlen(s2)-1-i]=s2[i]-48;
    }
    p1[0]=p1[0]-1;
    int x=find(strlen(s1)-1,p1,0,1);
    int y=find(strlen(s2)-1,p2,0,1);
    printf("%llu %llu %llu",x,y,y-x);
}
