#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int zhengshu[500];
    int xiaoshu[500];
}Num;

Num inPut(Num n){
    char tmp[502]={0};
    scanf("%s",tmp);
    int zs=1,xs=0,cnt=0;
    for(int i=0;tmp[i];i++){
        if(tmp[i]=='.'){
            if(i==0) n.zhengshu[0]=0;
            zs=0;
            xs=1;i++;
            cnt=0;
        }
        if(zs==1){
            n.zhengshu[cnt++]=tmp[i]-'0';
        }
        if(xs==1){
            n.xiaoshu[cnt++]=tmp[i]-'0';
        }
    }
    for(int i=0;i<500;i++){
        int last=0;
        if(n.zhengshu[i]==-1){
            last=i;
            for(int j=0;j<i;j++){
                n.zhengshu[500-i+j]=n.zhengshu[j];
                n.zhengshu[j]=-1;
            }
            break;
        }
    }
    return n;
}





int main(){
    Num A,B;
    for(int i=0;i<500;i++){
        A.xiaoshu[i]=A.zhengshu[i]=B.xiaoshu[i]=B.zhengshu[i]=-1;
    }
    A=inPut(A);
    B=inPut(B);
    int N;scanf("%d",&N);
    Num S;
    for(int i=0;i<500;i++){
        if(A.zhengshu[i]!=-1 && B.zhengshu[i]!=-1){
            S.zhengshu[i]=A.zhengshu[i]+B.zhengshu[i];}
        else if(A.zhengshu[i]==-1){
            S.zhengshu[i]=B.zhengshu[i];}
        else if(B.zhengshu[i]==-1){
            S.zhengshu[i]=A.zhengshu[i];}

        if(A.xiaoshu[i]!=-1 && B.xiaoshu[i]!=-1){
            S.xiaoshu[i]=A.xiaoshu[i]+B.xiaoshu[i];}
        else if(A.xiaoshu[i]==-1){
            S.xiaoshu[i]=B.xiaoshu[i];}
        else if(B.xiaoshu[i]==-1){
            S.xiaoshu[i]=A.xiaoshu[i];}
    }





    printf("done");

}
