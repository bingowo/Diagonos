#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A=0,B=0;
    int fu=1,zheng=0,ci=0,len1=0,len2=0,z=0,x=0;
    char zs[10000]={0},xs[10000]={0};
    scanf("%d %d",&A,&B);
    if(A<0) {
        fu=-1;
        A*=(-1);
    }
    z=A/B;
    x=A%B;
    if(B==1) {
        zheng=1;
    }
    else{
        while(B>1){
            ci++;
            B/=3;
            xs[len2++]='0';
        }
        xs[len2]=0;
    }
    while(z>0){
        zs[len1++]='0'+z%3;
        z/=3;
    }
    zs[len1]=0;
    int k=0;
    while(x>0){
        xs[k++]='0'+x%3;
        x/=3;
    }
    int jinwei=0,jieguo=0;
    for(int i=0;i<len2;i++){
        jieguo=xs[i]-'0'+1+jinwei;
        jinwei=jieguo/3;
        jieguo%=3;
        xs[i]=jieguo+'0';
    }
    for(int j=0;j<len1;j++){
        jieguo=zs[j]-'0'+1+jinwei;
        jinwei=jieguo/3;
        jieguo%=3;
        zs[j]=jieguo+'0';
    }
    while(jinwei>0){
        jieguo=jinwei+1;
        jinwei=jieguo/3;
        jieguo%=3;
        zs[len1++]='0'+jieguo;
    }
    zs[len1]=0;
    if(fu>0){
        int ke=0;
        for(int k=len1-1;k>=0;k--){
            int aaa=zs[k]-'0'-1;
            if(aaa==1) {printf("%d",aaa);ke=1;}
            else if(aaa==-1) {printf("2");ke=1;}
            else if(aaa==0&&ke==1) printf("0");
        }
        if(ke==0) printf("0");
        if(zheng!=1) {
            int xx[10000]={0};
            for(int w=len2-1;w>=0;w--){
                xx[len2-1-w]=xs[w]-'0'-1;
            }
            for(int w=len2-1;w>=0;w--){
                if(xx[w]==0) len2--;
                else break;
            }
            if(len2>0) {
                printf(".");
                for(int f=0;f<len2;f++) {
                    if(xx[f]>0) printf("1");
                    else if(xx[f]<0) printf("2");
                    else printf("0");
                }
            }
        }
    }
    else{
        int ke=0;
        for(int k=len1-1;k>=0;k--){
            int aaa=zs[k]-'0'-1;
            if(aaa==1) {printf("2");ke=1;}
            else if(aaa==-1) {printf("1");ke=1;}
            else if(aaa==0&&ke==1) printf("0");
        }
        if(ke==0) printf("0");
        if(zheng!=1) {
            int xx[10000]={0};
            for(int w=len2-1;w>=0;w--){
                xx[len2-1-w]=xs[w]-'0'-1;
            }
            for(int w=len2-1;w>=0;w--){
                if(xx[w]==0) len2--;
                else break;
            }
            if(len2>0) {
                printf(".");
                for(int f=0;f<len2;f++) {
                    if(xx[f]>0) printf("2");
                    else if(xx[f]<0) printf("1");
                    else printf("0");
                }
            }
        }
    }
    printf("\n");
    return 0;
}
