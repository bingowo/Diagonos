#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(char* ans,char* s)
{
    int len1=strlen(ans);
    int len2=strlen(s);
    int i=0,jieguo=0,jinwei=0;
    if(len1<=len2){
        for(;i<len1;i++){
            jieguo=jinwei+ans[i]-'0'+s[i]-'0';
            jinwei=jieguo/10;
            jieguo%=10;
            ans[i]='0'+jieguo;
        }
        if(len2>len1){
            for(;i<len2;i++){
                jieguo=jinwei+s[i]-'0';
                jinwei=jieguo/10;
                jieguo%=10;
                ans[i]='0'+jieguo;
            }
        }
        if(jinwei>0){
            ans[i++]=jinwei+'0';
        }
    }
    else{
        for(;i<len2;i++){
            jieguo=jinwei+ans[i]-'0'+s[i]-'0';
            jinwei=jieguo/10;
            jieguo%=10;
            ans[i]='0'+jieguo;
        }
        for(;i<len1;i++){
            jieguo=ans[i]-'0'+jinwei;
            jinwei=jieguo/10;
            jieguo%=10;
            ans[i]='0'+jieguo;
        }
        if(jinwei>0) ans[i++]=jinwei+'0';
    }
    ans[i]=0;
}

int main()
{
    char s[1000][5000]={0};
    s[0][0]='1',s[0][1]=0;
    s[1][0]='2',s[1][1]=0;
    s[2][0]='3',s[2][1]=0;
    s[3][0]='6',s[3][1]=0;
    int n=0;
    scanf("%d",&n);
    for(int i=4;i<n;i++){
        add(s[i],s[i-1]);
        add(s[i],s[i-2]);
        add(s[i],s[i-4]);
    }
    int len=strlen(s[n-1]);
    for(int i=len-1;i>=0;i--){
        printf("%c",s[n-1][i]);
    }
    printf("\n");
    return 0;
}