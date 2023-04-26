#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void add(char* ans,char* s1,char* s2)
{
    int len1=strlen(s1),len2=strlen(s2);
    int len=0;
    if(s1[len1-1]==s2[len2-1]){
        int jinwei=0,jieguo=0;
        int i=0;
        for(;i<len1-1&&i<len2-1;i++){
            jieguo=s1[i]-'0'+s2[i]-'0'+jinwei;
            jinwei=jieguo/10;
            jieguo=jieguo%10;
            ans[len++]=jieguo+'0';
        }
        if(i<len1-1){
            for(;i<len1-1;i++){
                jieguo=s1[i]-'0'+jinwei;
                jinwei=jieguo/10;
                jieguo=jieguo%10;
                ans[len++]=jieguo+'0';
            }
        }
        else if(i<len2-1){
            for(;i<len2-1;i++){
                jieguo=s2[i]-'0'+jinwei;
                jinwei=jieguo/10;
                jieguo=jieguo%10;
                ans[len++]=jieguo+'0';
            }
        }
        if(jinwei>0) ans[len++]=jinwei+'0';
        ans[len++]=s1[len1-1];
        ans[len]=0;
    }
    else {
        char b[10000]={0},s[10000]={0};
        int blen=0,slen=0;
        if(len1>len2){
            strcpy(b,s1);
            blen=len1;
            strcpy(s,s2);
            slen=len2;
        }
        else if(len1<len2){
            strcpy(b,s2);
            strcpy(s,s1);
            blen=len2;
            slen=len1;
        }
        else{
            int k1=len1-2,k2=len2-2;
            for(;k1>=0;k1--,k2--){
                if(s1[k1]>s2[k2]){
                    strcpy(b,s1);
                    blen=len1;
                    strcpy(s,s2);
                    slen=len2;
                    break;
                }
                else if(s1[k1]<s2[k2]){
                    strcpy(b,s2);
                    blen=len2;
                    strcpy(s,s1);
                    slen=len1;
                    break;
                }
            }
            if(k1<0) {
                ans[len++]='0';
                ans[len++]='+';
                ans[len]=0;
                return ;
            }
        }
        int jieguo=0,jiewei=0,i=0;
        for(;i<slen-1;i++){
            jieguo=b[i]-s[i]-jiewei;
            if(jieguo<0){
                jieguo+=10;
                jiewei=1;
            }
            else jiewei=0;
            ans[len++]=jieguo+'0';
        }
        for(;i<blen-1;i++){
            jieguo=b[i]-'0'-jiewei;
            if(jieguo<0){
                jieguo+=10;
                jiewei=1;
            }
            else jiewei=0;
            ans[len++]=jieguo+'0';
        }
        if(ans[len-1]=='0') {
            ans[len-1]=b[blen-1];
            ans[len]=0;
            return ;
        }
        else{
            ans[len++]=b[blen-1];
            ans[len]=0;
        }
    }
    return ;
}

int pow(int n,int w)
{
    int x=1;
    for(int i=0;i<w;i++){
        x=x*n;
    }
    return x;
}

int change(char c)
{
    int x=0;
    if(isdigit(c)) x=c-'0';
    else x=c-'A'+10;
    return x;
}

int main()
{
    char s0[100];
    scanf("%s",s0);
    int length=strlen(s0)-2;
    char a[2000]={0},b[2000]={0};
    a[0]='0';
    a[1]='+';
    a[2]=0;
    b[0]='0';
    b[1]='+';
    b[2]=0;
    int y=0;
    int r=0;
    if(length==1&&s0[2]=='0') printf("0");
    for (int k=0;k<length;k++){
    int x=change(s0[k+2]);
    int digit=4;
    for(int i=0;i<digit;i++){
        y=pow(2,digit-1-i);
        r=x&y;
        if(r>0) r=1;
        char a1[2000]={0},b1[2000]={0};
        strcpy(a1,a);
        strcpy(b1,b);
        char r1[2000]={0};
        int lenr=0;
        if(r>=0){
            do{
                r1[lenr++]=r%10+'0';
                r/=10;
            }while(r>0);
            r1[lenr++]='+';
            r1[lenr]=0;
        }
        else{
            r*=-1;
            do{
                r1[lenr++]=r%10+'0';
                r/=10;
            }while(r>0);
            r1[lenr++]='-';
            r1[lenr]=0;
        }
        char zhonga1[2000]={0},zhongb1[2000]={0};
        strcpy(zhonga1,a1);
        strcpy(zhongb1,b1);
        int lena1=strlen(zhonga1);
        int lenb1=strlen(zhongb1);
        if(zhonga1[lena1-1]=='+') zhonga1[lena1-1]='-';
        else zhonga1[lena1-1]='+';
        if(zhongb1[lenb1-1]=='+') zhongb1[lenb1-1]='-';
        else zhongb1[lenb1-1]='+';
        char zhong1[2000]={0};
        add(zhong1,r1,zhonga1);
        add(a,zhong1,zhongb1);
        add(b,a1,zhongb1);
        //a=r-a1-b1;
        //b=a1-b1;
    }}
    //printf("a=%s b=%s\n",a,b);
    int len1=strlen(a);
    int len2=strlen(b);
    for(int e=0;e<len1/2;e++){
        char c=a[e];
        a[e]=a[len1-1-e];
        a[len1-1-e]=c;
    }
    for(int e=0;e<len2/2;e++){
        char c=b[e];
        b[e]=b[len2-1-e];
        b[len2-1-e]=c;
    }
    int k=0;
    if(a[0]=='+'){
        for(int i=1;i<len1;i++){
            if(k==0&&a[i]!='0') k=1;
            if(k==1) printf("%c",a[i]);
        }
    }
    else {
        k=0;
        for(int i=1;i<len1;i++){
            if(k==0&&a[i]!='0') {k=1;printf("-");}
            if(k==1) printf("%c",a[i]);
        }
    }
    if(len2>2) {
        int q=1;
        if(k==1) printf("%c",b[0]);
        if(k==0&&b[0]=='-') printf("%c",b[0]);
        int ky=0;
        for(;q<len2;q++){
            int qq=0;
            if(b[q]!='0') {ky=1;qq=1;}
            if(ky==1){
                if(q!=len2-1) printf("%c",b[q]);
                    else if(q==len2-1&&qq!=1) printf("%c",b[q]);
            }
        }
        printf("i");
    }
    else {
        if(b[1]=='1'&&k==1) printf("%ci",b[0]);
        else if(b[1]=='1'&&k==0) {
            if(b[0]=='-') printf("-i");
            else printf("i");
        }
        else if(b[1]!='0'&&k==1) printf("%si",b);
        else if(b[1]!='0'&&k==0){
            if(b[0]=='-') printf("%si",b);
            else {
                for(int kk=1;kk<len2;kk++) printf("%c",b[kk]);
                printf("i");
            }
        }
        else if(k==1){
            printf("%c",b[0]);
            int ky=0,ww=0;
            for(;ww<len2;ww++){
                int qq=0;
                if(ky==0,b[ww]!='0') {ky=1;qq=1;}
                if(ky==1) {
                    if(ww!=len2-1) printf("%c",b[ww]);
                    else if(ww==len2-1&&qq!=1) printf("%c",b[ww]);
                }
            }
            printf("i");
        }
        else{
            if(b[0]=='-') printf("-");
            int ky=0,ww=0;
            for(;ww<len2;ww++){
                int qq=0;
                if(ky==0,b[ww]!='0') {ky=1;qq=1;}
                if(ky==1) {
                    if(ww!=len2-1) printf("%c",b[ww]);
                    else if(ww==len2-1&&qq!=1) printf("%c",b[ww]);
                }
            }
            printf("i");
        }
    }
    printf("\n");
    //if(a!=0) printf("%lld",a);
    //if(b>0&&a!=0) printf("+");
    //if(b>1) printf("%lldi",b);
    //if(b==1) printf("i");
    //if(b<-1) printf("%lldi",b);
    //if(b==-1) printf("-i");
    return 0;
}

