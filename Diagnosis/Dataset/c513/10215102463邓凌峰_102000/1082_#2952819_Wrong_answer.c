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

    if(xs==0) n.xiaoshu[0]=0;

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
    if(n.zhengshu[499]==-1) n.zhengshu[499]=0;
    if(n.xiaoshu[0]<0) n.xiaoshu[0]=0;
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
    for(int i=0;i<500;i++){//加法
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

    for(int i=N;i>0;i--){
        if(S.xiaoshu[i]>9){
            S.xiaoshu[i-1]+=S.xiaoshu[i]/10;
            S.xiaoshu[i]=S.xiaoshu[i]%10;
        }
    }
    if(S.xiaoshu[N]>4){
        S.xiaoshu[N-1]+=1;
    }
     for(int i=N-1;i>0;i--){
        if(S.xiaoshu[i]>9){
            S.xiaoshu[i-1]+=S.xiaoshu[i]/10;
            S.xiaoshu[i]=S.xiaoshu[i]%10;
        }
    }


    if(S.xiaoshu[0]>9){
        S.zhengshu[499]+=S.xiaoshu[0]/10;
        S.xiaoshu[0]=S.xiaoshu[0]%10;
    }

    int isNum=1;
    for(int i=499;isNum;i--){
        if(S.zhengshu[i]>9){
            if(S.zhengshu[i-1]==-1){
                S.zhengshu[i-1]=0;
                isNum=0;
            }
            S.zhengshu[i-1]+=S.zhengshu[i]/10;
            S.zhengshu[i]=S.zhengshu[i]%10;
        }
    }

    for(int i=0;i<500;i++){
        if(S.zhengshu[i]!=-1) printf("%d",S.zhengshu[i]);
    }
    printf(".");
    int z=0;
    for(int i=0;i<N;i++){
        if(S.xiaoshu[i]>=0) printf("%d",S.xiaoshu[i]);
        else printf("%d",z);
    }



}
