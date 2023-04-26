#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(char* s1,char*s2,char* ans)
{
    int len1=strlen(s1),len2=strlen(s2);
    int jinwei=0,jieguo=0,min=len1>len2?len2:len1;
    int i=0;
    for(;i<min;i++){
        jieguo=s1[i]-'0'+s2[i]-'0'+jinwei;
        jinwei=jieguo/10;
        jieguo=jieguo%10;
        ans[i]=jieguo+'0';
    }
    if(i<len1) {
        for(;i<len1;i++){
            jieguo=s1[i]-'0'+jinwei;
            jinwei=jieguo/10;
            jieguo=jieguo%10;
            ans[i]=jieguo+'0';
        }
    }
    else if(i<len2) {
        for(;i<len2;i++){
            jieguo=s2[i]-'0'+jinwei;
            jinwei=jieguo/10;
            jieguo=jieguo%10;
            ans[i]=jieguo+'0';
        }
    }
    if(jinwei>0) ans[i++]=jinwei+'0';
    ans[i]=0;
}

void minus(char* s1,char* s2,char* ans)
{
    int len1=strlen(s1),len2=strlen(s2);
    int jiewei=0,jieguo=0,i=0;
    for(;i<len2;i++){
        jieguo=s1[i]-s2[i]-jiewei;
        if(jieguo<0){
            jieguo+=10;
            jiewei=1;
        }
        else jiewei=0;
        ans[i]=jieguo+'0';
    }
    for(;i<len1;i++){
        jieguo=s1[i]-'0'-jiewei;
        if(jieguo<0){
            jieguo+=10;
            jiewei=1;
        }
        else jiewei=0;
        ans[i]=jieguo+'0';
    }
    ans[i]=0;
}

int main()
{
    int k=0,n=0;
    scanf("%d %d",&k,&n);
    if(n<=2) printf("%d\n",n-1);
    else{
        char shu[100][50];
        shu[0][0]='0';
        shu[0][1]=0;
        shu[1][0]='1';
        shu[1][1]=0;
        char all[50];
        add(shu[0],shu[1],all);
        for(int i=2;i<n;i++){
            if(i<k){
                strcpy(shu[i],all);
                add(shu[i],all,all);
            }
            else {
                strcpy(shu[i],all);
                minus(all,shu[i-k],all);//all-=shu[i-k];
                add(shu[i],all,all);
            }
        }
        int len=strlen(shu[n-1]),k=0;
        for(int j=len-1;j>=0;j--){
            if(shu[n-1][j]>'0'&&k==0) k=1;
            if(k) printf("%c",shu[n-1][j]);
        }
        printf("\n");
    }
    return 0;
}
