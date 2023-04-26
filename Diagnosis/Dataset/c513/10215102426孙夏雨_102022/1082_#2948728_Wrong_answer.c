#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char zheng[501];
    char xiao[501];
}SHU;

SHU ans;

/*int add(SHU ans,SHU p1,SHU p2,int num1z,int num1x,int num2z,int num2x,int N)
{
    int jieguo=0,jinwei=0,numx=0,numz=0;
    if(num1x==0){
        for(int i=0;i<num2x;i++) ans.xiao[numx++]=p2.xiao[num2x-1-i];
    }
    else if(num2x==0){
        for(int i=0;i<num1x;i++) ans.xiao[numx++]=p1.xiao[num1x-1-i];
    }
    else{
        if(num1x<=num2x){
            int len1x=num1x-1,len2x=num2x-1;
            for(;len2x>len1x;len2x--) ans.xiao[numx++]=p2.xiao[len2x];
            for(;len1x>=0;len1x--,len2x--) {
                jieguo=(p1.xiao[len1x])-'0'+(p2.xiao[len2x])-'0'+jinwei;
                jinwei=jieguo/10;
                jieguo=jieguo%10;
                ans.xiao[numx++]=jieguo+'0';
            }
        }
        else {
            int len1x=num1x-1,len2x=num2x-1;
            for(;len1x>len2x;len1x--) ans.xiao[numx++]=p1.xiao[len1x];
            for(;len1x>=0;len1x--,len2x--) {
                jieguo=(p1.xiao[len1x])-'0'+(p2.xiao[len2x])-'0'+jinwei;
                jinwei=jieguo/10;
                jieguo=jieguo%10;
                ans.xiao[numx++]=jieguo+'0';
            }
        }
    }
    ans.xiao[numx]=0;
    if(num1z>=num2z){
        int len1z=num1z-1,len2z=num2z-1;
        for(;len2z>=0;len2z--,len1z--){
            jieguo=(p1.zheng[len1z])-'0'+(p2.zheng[len2z])-'0'+jinwei;
            jinwei=jieguo/10;
            jieguo=jieguo%10;
            ans.zheng[numz++]=jieguo+'0';
        }
        for(;len1z>=0;len1z--) {
            jieguo=(p1.zheng[len1z])-'0'+jinwei;
            jinwei=jieguo/10;
            jieguo=jieguo%10;
            ans.zheng[numz++]=jieguo+'0';
        }
    }
    else {
        int len1z=num1z-1,len2z=num2z-1;
        for(;len1z>=0;len1z--,len2z--){
            jieguo=(p1.zheng[len1z])-'0'+(p2.zheng[len2z])-'0'+jinwei;
            jinwei=jieguo/10;
            jieguo=jieguo%10;
            ans.zheng[numz++]=jieguo+'0';
        }
        for(;len2z>=0;len2z--) {
            jieguo=(p2.zheng[len2z])-'0'+jinwei;
            jinwei=jieguo/10;
            jieguo=jieguo%10;
            ans.zheng[numz++]=jieguo+'0';
        }
    }
    if(jinwei>0) ans.zheng[numz++]=jinwei+'0';
    ans.zheng[numz]=0;
    if(numx>N) {
        int kk=N-1;
        if((ans.xiao[numx-2-kk])>'4'){
            jinwei=1,jieguo=0;
            for(int qq=numx-1-kk;qq<numx;qq++){
                jieguo=jinwei+(ans.xiao[qq])-'0';
                jinwei=jieguo/10;
                jieguo=jieguo%10;
                ans.xiao[qq]=jieguo+'0';
            }
            if(jinwei>0){
                for(int ww=0;ww<numz;ww++){
                    jieguo=jinwei+(ans.zheng[ww])-'0';
                    jinwei=jieguo/10;
                    jieguo=jieguo%10;
                    ans.zheng[ww]=jieguo+'0';
                }
                if(jinwei>0) ans.zheng[numz++]=jinwei+'0';
                ans.zheng[numz]=0;
            }
        }
    }
    if(numz>num1z&&numz>num2z) return 1;
    else return 0;
}
*/
int main()
{
    char A[501],B[501];
    int N=0;
    scanf("%s %s %d",A,B,&N);
    int len1=strlen(A),len2=strlen(B),zu=1,num1z=0,num2z=0,num1x=0,num2x=0;
    SHU p1;
    SHU p2;
    for(int i=0;i<len1;i++){
        if(isdigit(A[i])&&zu==1) p1.zheng[num1z++]=A[i];
        else if(isdigit(A[i])&&zu==0) p1.xiao[num1x++]=A[i];
        else if (A[i]=='.') zu=0;
    }
    zu=1;
    p1.zheng[num1z]=0;
    p1.xiao[num1x]=0;
    for(int i=0;i<len2;i++){
        if(isdigit(B[i])&&zu==1) p2.zheng[num2z++]=B[i];
        else if(isdigit(B[i])&&zu==0) p2.xiao[num2x++]=B[i];
        else if (B[i]=='.') zu=0;
    }
    p2.zheng[num2z]=0;
    p2.xiao[num2x]=0;
    int jieguo=0,jinwei=0,numx=0,numz=0;
    if(num1x==0){
        for(int i=0;i<num2x;i++) ans.xiao[numx++]=p2.xiao[num2x-1-i];
    }
    else if(num2x==0){
        for(int i=0;i<num1x;i++) ans.xiao[numx++]=p1.xiao[num1x-1-i];
    }
    else{
        if(num1x<=num2x){
            int len1x=num1x-1,len2x=num2x-1;
            for(;len2x>len1x;len2x--) ans.xiao[numx++]=p2.xiao[len2x];
            for(;len1x>=0;len1x--,len2x--) {
                jieguo=(p1.xiao[len1x])-'0'+(p2.xiao[len2x])-'0'+jinwei;
                jinwei=jieguo/10;
                jieguo=jieguo%10;
                ans.xiao[numx++]=jieguo+'0';
            }
        }
        else {
            int len1x=num1x-1,len2x=num2x-1;
            for(;len1x>len2x;len1x--) ans.xiao[numx++]=p1.xiao[len1x];
            for(;len1x>=0;len1x--,len2x--) {
                jieguo=(p1.xiao[len1x])-'0'+(p2.xiao[len2x])-'0'+jinwei;
                jinwei=jieguo/10;
                jieguo=jieguo%10;
                ans.xiao[numx++]=jieguo+'0';
            }
        }
    }
    ans.xiao[numx]=0;
    if(num1z>=num2z){
        int len1z=num1z-1,len2z=num2z-1;
        for(;len2z>=0;len2z--,len1z--){
            jieguo=(p1.zheng[len1z])-'0'+(p2.zheng[len2z])-'0'+jinwei;
            jinwei=jieguo/10;
            jieguo=jieguo%10;
            ans.zheng[numz++]=jieguo+'0';
        }
        for(;len1z>=0;len1z--) {
            jieguo=(p1.zheng[len1z])-'0'+jinwei;
            jinwei=jieguo/10;
            jieguo=jieguo%10;
            ans.zheng[numz++]=jieguo+'0';
        }
    }
    else {
        int len1z=num1z-1,len2z=num2z-1;
        for(;len1z>=0;len1z--,len2z--){
            jieguo=(p1.zheng[len1z])-'0'+(p2.zheng[len2z])-'0'+jinwei;
            jinwei=jieguo/10;
            jieguo=jieguo%10;
            ans.zheng[numz++]=jieguo+'0';
        }
        for(;len2z>=0;len2z--) {
            jieguo=(p2.zheng[len2z])-'0'+jinwei;
            jinwei=jieguo/10;
            jieguo=jieguo%10;
            ans.zheng[numz++]=jieguo+'0';
        }
    }
    if(jinwei>0) ans.zheng[numz++]=jinwei+'0';
    ans.zheng[numz]=0;
    if(numx>N) {
        int kk=N-1;
        if((ans.xiao[numx-2-kk])>'4'){
            jinwei=1,jieguo=0;
            for(int qq=numx-1-kk;qq<numx;qq++){
                jieguo=jinwei+(ans.xiao[qq])-'0';
                jinwei=jieguo/10;
                jieguo=jieguo%10;
                ans.xiao[qq]=jieguo+'0';
            }
            if(jinwei>0){
                for(int ww=0;ww<numz;ww++){
                    jieguo=jinwei+(ans.zheng[ww])-'0';
                    jinwei=jieguo/10;
                    jieguo=jieguo%10;
                    ans.zheng[ww]=jieguo+'0';
                }
                if(jinwei>0) ans.zheng[numz++]=jinwei+'0';
                ans.zheng[numz]=0;
            }
        }
    }
    if(numz==0) printf("0");
    for(int ii=numz-1;ii>=0;ii--) printf("%c",ans.zheng[ii]);
    printf(".");
    if(numx<=N){
        for(int jj=numx-1;jj>=0;jj--) printf("%c",ans.xiao[jj]);
        for(int k=0;k<(N-numx);k++) printf("0");
    }
    else {
        for(int ee=0;ee<N;ee++) printf("%c",ans.xiao[numx-1-ee]);
    }
    printf("\n");
    return 0;
}
