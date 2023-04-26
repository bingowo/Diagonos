#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void minus(char* s1,char* s2,int weizhi1,int weizhi2,char* ans,int N)
{
    int len1=strlen(s1),len2=strlen(s2);
    int n1=len1-1,n2=len2-1,num=0;
    int jieguo=0,jiewei=0;
    if((len1-weizhi1)==(len2-weizhi2)){
        for(;n1>weizhi1;n1--,n2--){
            jieguo=s1[n1]-s2[n2]-jiewei;
            if(jieguo<0){
                jiewei=1;
                jieguo+=10;
            }
            else jiewei=0;
            ans[num++]=jieguo+'0';
        }
    }
    else if((len1-weizhi1)>(len2-weizhi2)){
        for(int i=0;i<((len1-weizhi1)-(len2-weizhi2));i++){
            jieguo=s1[n1--]-'0';
            ans[num++]=jieguo+'0';
        }
        for(;n1>weizhi1;n1--,n2--){
            jieguo=s1[n1]-s2[n2]-jiewei;
            if(jieguo<0){
                jiewei=1;
                jieguo+=10;
            }
            else jiewei=0;
            ans[num++]=jieguo+'0';
        }
    }
    else {
        for(int i=0;i<((len2-weizhi2)-(len1-weizhi1));i++){
            jieguo='0'-s2[n2--]-jiewei;
            jiewei=1;
            jieguo+=10;
            ans[num++]=jieguo+'0';
        }
        for(;n1>weizhi1;n1--,n2--){
            jieguo=s1[n1]-s2[n2]-jiewei;
            if(jieguo<0){
                jiewei=1;
                jieguo+=10;
            }
            else jiewei=0;
            ans[num++]=jieguo+'0';
        }
    }
    int weizhi3=num;
    ans[num++]='.';
    n1--;
    n2--;
    if(n2<0){
        if(n1<0) ans[num++]='0';
        else {
            for(;n1>=0;n1--){
                jieguo=s1[n1]-'0'-jiewei;
                if(jieguo<0){
                    jiewei=1;
                    jieguo+=10;
                }
                else jiewei=0;
                ans[num++]=jieguo;
            }
        }
        ans[num]=0;
    }
    else {
        for(;n2>=0;n1--,n2--){
            jieguo=s1[n1]-s2[n2]-jiewei;
            if(jieguo<0){
                jiewei=1;
                jieguo+=10;
            }
            else jiewei=0;
            ans[num++]=jieguo+'0';
        }
        if(n1>0){
            for(;n1>=0;n1--){
                jieguo=s1[n1]-'0'-jiewei;
                if(jieguo<0){
                    jiewei=1;
                    jieguo+=10;
                }
                else jiewei=0;
                ans[num++]=jieguo+'0';
            }
        }
        ans[num]=0;
    }
    int len=strlen(ans);
    int xiao=weizhi3;
    if(xiao>N){
        int k=weizhi3-N-1;
        if(ans[k]>'4'){
            int jinwei=1;
            k++;
            for(;k<weizhi3;k++){
                jieguo=ans[k]-'0'+jinwei;
                if(jieguo>=10){
                    jinwei=1;
                    jieguo-=10;
                }
                else jinwei=0;
                ans[k]=jieguo+'0';
            }
            if(jinwei>0){
                k++;
                for(;k<len;k++){
                    jieguo=ans[k]-'0'+jinwei;
                    if(jieguo>=10){
                        jinwei=1;
                        jieguo-=10;
                    }
                    else jinwei=0;
                    ans[k]=jieguo+'0';
                }
            }
            if(jinwei>0) ans[num++]='1';
            ans[num]=0;
        }
    }
}

int main()
{
    char A[501],B[501],ans[502];
    ans[0]=0;
    int N=0;
    scanf("%s %s %d",A,B,&N);
    int len1=strlen(A),len2=strlen(B);
    int weizhi1=0,weizhi2=0,sig=1;
    for(int i=0;i<len1;i++) {
        if(A[i]=='.') {
            weizhi1=i;
            if(i==len1-1){
                A[i+1]='0';
                A[i+2]=0;
                len1++;
            }
            break;
        }
        if(i==len1-1) {
            A[i+1]='.';
            A[i+2]='0';
            A[i+3]='\0';
            len1+=2;
            weizhi1=i+1;
            break;
        }
    }
    if(weizhi1==0){
        len1++;
        A[len1]=0;
        for(int ii=len1-1;ii>0;ii--){
            A[ii]=A[ii-1];
        }
        A[0]='0';
        weizhi1=1;
    }
    for(int j=0;j<len2;j++) {
        if(B[j]=='.') {
            weizhi2=j;
            if(j==len2-1){
                B[j+1]='0';
                B[j+2]=0;
                len2++;
            }
            break;
        }
        if(j==len2-1) {
            B[j+1]='.';
            B[j+2]='0';
            B[j+3]='\0';
            len2+=2;
            weizhi2=j+1;
            break;
        }
    }
    if(weizhi2==0){
        len2++;
        B[len2]=0;
        for(int ii=len2-1;ii>0;ii--){
            B[ii]=B[ii-1];
        }
        B[0]='0';
        weizhi2=1;
    }
    if(weizhi1>weizhi2) minus(A,B,weizhi1,weizhi2,ans,N);
    else if(weizhi1<weizhi2) {sig=-1;minus(B,A,weizhi2,weizhi1,ans,N);}
    else{
        int k=strcmp(A,B);
        if(k>0) minus(A,B,weizhi1,weizhi2,ans,N);
        else {sig=-1;minus(B,A,weizhi2,weizhi1,ans,N);}
    }
    int len=strlen(ans);
    if(sig<0) printf("-");
    int weizhi=0;
    for(;weizhi<len;weizhi++){
        if(ans[weizhi]=='.') break;
    }
    int keyi=0;
    if(N<weizhi){
        for(int w=len-1;w>=weizhi-N;w--) {
            if(ans[w]>'0'&&keyi==0) keyi=1;
            if(w==weizhi&&keyi==0)  {keyi=1;printf("0");}
            if(keyi) printf("%c",ans[w]);
        }
    }
    else {
        for(int r=len-1;r>=0;r--) {
            if(ans[r]>'0'&&keyi==0) keyi=1;
            if(r==weizhi&&keyi==0)  {keyi=1;printf("0");}
            if(keyi) printf("%c",ans[r]);
        }
        for(int e=0;e<N-weizhi;e++) printf("0");
    }
    printf("\n");
    return 0;
}
