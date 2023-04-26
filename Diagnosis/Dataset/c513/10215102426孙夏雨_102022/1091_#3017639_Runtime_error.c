#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
        char b[1000]={0},s[1000]={0};
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

void mul(char* ans,char* s1,char* s2)
{
    int len1=strlen(s1),len2=strlen(s2),blen=0,slen=0;
    char b[1000]={0},s[1000]={0};
    if(len1>len2){
        strcpy(b,s1);
        strcpy(s,s2);
        blen=len1;
        slen=len2;
    }
    else{
        strcpy(b,s2);
        strcpy(s,s1);
        blen=len2;
        slen=len1;
    }
    int i=0;
    char zhong[1000]={0};
    zhong[0]='0';
    zhong[1]='+';
    zhong[2]=0;
    for(;i<slen-1;i++){
        char zheci[1000]={0};
        int zlen=0,jinwei=0,jieguo=0;
        for(int k=0;k<i;k++) zheci[zlen++]='0';
        for(int j=0;j<blen-1;j++){
            jieguo=(s[i]-'0')*(b[j]-'0')+jinwei;
            jinwei=jieguo/10;
            jieguo=jieguo%10;
            zheci[zlen++]=jieguo+'0';
        }
        if(jinwei>0){
            zheci[zlen++]=jinwei+'0';
        }
        zheci[zlen++]='+';
        zheci[zlen]=0;
        add(ans,zheci,zhong);
        strcpy(zhong,ans);
    }
    if(s1[len1-1]!=s2[len2-1]){
        int len=strlen(ans);
        ans[len-1]='-';
    }
    return ;
}

int main()
{
    char s0[1000]={0};
    int ci=0;
    scanf("%s %d",s0,&ci);
    int sig1=1,sig2=1;
    int len=strlen(s0),len1=0,len2=0;
    char shi[1000]={0},xu[1000]={0};
    int x1=1;
    for(int i=len-1;i>=0;i--){
        if(x1==0){
            if(isdigit(s0[i])) xu[len2++]=s0[i];
            else if(s0[i]=='-'||s0[i]=='+'){
                if(s0[i]=='-') sig2=-1;
                if(len2==0) xu[len2++]='1';
                x1=1;
            }
        }
        else if(s0[i]=='i') x1=0;
        else if(x1==1){
            if(isdigit(s0[i])) shi[len1++]=s0[i];
            else if(s0[i]=='-'||s0[i]=='+'){
                if(s0[i]=='-') sig1=-1;
            }
        }
        if(i==0&&s0[i]=='i') xu[len2++]='1';
    }
    if(len1==0) shi[len1++]='0';
    if(len2==0) xu[len2++]='0';
    if(sig1>0) shi[len1++]='+';
    else shi[len1++]='-';
    if(sig2>0) xu[len2++]='+';
    else xu[len2++]='-';
    shi[len1]=0;
    xu[len2]=0;
    //printf("shi=%s xu=%s\n",shi,xu);
    if(ci==0){printf("1\n");return 0;}
    char s[1000]={0},x[1000]={0};
    strcpy(s,shi);
    strcpy(x,xu);
    for(int j=1;j<ci;j++){
        char shi1[1000]={0},xu1[1000]={0},zs[1000]={0},zx[1000]={0};
        char ashi[1000]={0},axu[1000]={0};
        strcpy(shi1,shi);
        strcpy(xu1,xu);
        mul(shi,shi1,s);
        //printf("shi %s\n",shi);
        mul(zs,xu1,x);
        //printf("zs %s\n",zs);
        int lenzs=strlen(zs);
        if(zs[lenzs-1]=='+') zs[lenzs-1]='-';
        else zs[lenzs-1]='+';
        add(ashi,shi,zs);
        //printf("ashi %s\n",ashi);
        mul(xu,shi1,x);
        //printf("xu %s\n",xu);
        mul(zx,xu1,s);
        //printf("zx %s\n",zx);
        add(axu,xu,zx);
        //printf("axu %s\n",axu);
        strcpy(shi,ashi);
        strcpy(xu,axu);
    }
    len1=strlen(shi);
    len2=strlen(xu);
    for(int e=0;e<len1/2;e++){
        char c=shi[e];
        shi[e]=shi[len1-1-e];
        shi[len1-1-e]=c;
    }
    for(int e=0;e<len2/2;e++){
        char c=xu[e];
        xu[e]=xu[len2-1-e];
        xu[len2-1-e]=c;
    }
    //printf("shi=%s xu=%s\n",shi,xu);
    int k=0;
    if(shi[0]=='+'){
        for(int i=1;i<len1;i++){
            if(k==0&&shi[i]!='0') k=1;
            if(k==1) printf("%c",shi[i]);
        }
    }
    else {
        k=0;
        for(int i=1;i<len1;i++){
            if(k==0&&shi[i]!='0') {k=1;printf("-");}
            if(k==1) printf("%c",shi[i]);
        }
    }
    if(len2>2) {
        int q=1;
        for(;q<len2;q++){
            if(xu[q]!='0') break;
        }
        if(q!=len2&&k==1) printf("%si",xu);
        else if(q!=len2&&k==0){
            if(xu[0]=='-') printf("%si",xu);
            else {
                for(int kk=1;kk<len2;kk++) printf("%c",xu[kk]);
                printf("i");
            }
        }
    }
    else {
        if(xu[1]=='1'&&k==1) printf("%ci",xu[0]);
        else if(xu[1]=='1'&&k==0) {
            if(xu[0]=='-') printf("-i");
            else printf("i");
        }
        else if(xu[1]!='0'&&k==1) printf("%si",xu);
        else if(xu[1]!='0'&&k==0){
            if(xu[0]=='-') printf("%si",xu);
            else {
                for(int kk=1;kk<len2;kk++) printf("%c",xu[kk]);
                printf("i");
            }
        }
    }
    printf("\n");
    return 0;
}
