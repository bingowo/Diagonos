#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ans[1000];

void mul(char* s,int x)
{
    int len=strlen(s);
    int jinwei=0,jieguo=0,num=0;
    for(int i=0;i<len;i++){
        jieguo=jinwei+(s[i]-'0')*x;
        jinwei=jieguo/10;
        jieguo=jieguo%10;
        ans[num++]=jieguo+'0';
    }
    if(jinwei>0) ans[num++]=jinwei+'0';
    ans[num]=0;
}

int main()
{
    char s[1001];
    scanf("%s",s);
    int len=strlen(s),butong=1;
    int* p=(int* )malloc(len*sizeof(int));
    if(len==1) printf("1");
    else{for(int i=0;i<len;i++){
        butong=1;
        if(i==0) {
            if(s[i+1]!=s[i]) butong++;
        }
        else if(i==len-1) {
            if(s[i-1]!=s[i]) butong++;
        }
        else {
            if(s[i+1]!=s[i]) butong++;
            if(s[i-1]!=s[i]) butong++;
        }
        *(p+i)=butong;
    }
    int num=0;
    ans[num]=(*p)+'0';
    num++;
    ans[num]=0;
    for(int k=1;k<len;k++){
        int x=*(p+k);
        mul(ans,x);
    }
    int length=strlen(ans);
    for(int i=0;i<length;i++) printf("%c",ans[length-1-i]);}
    printf("\n");
    free(p);
    return 0;
}
