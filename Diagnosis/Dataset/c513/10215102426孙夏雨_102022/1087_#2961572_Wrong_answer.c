#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(char* s,int len)
{
    int jieguo=0,jinwei=1;
    for(int i=0;i<len;i++){
        jieguo=s[i]-'0'+jinwei;
        jinwei=jieguo/10;
        jieguo=jieguo%10;
        s[i]=jieguo+'0';
    }
    if(jinwei>0) {
        s[len]=jinwei+'0';
        s[len+1]=0;
    }
}

int panduan(char* s,int len)
{
    for(int j=len-2;j>=0;j--){
        if(s[j]==s[j+1]) return j;
    }
    return -1;
}

int cmp(char* s,char* s1,int len)
{
    for(int i=len-1;i>=0;i--){
        if(s[i]>s1[i]) return 1;
        if(s[i]<s1[i]) return -1;
    }
    return -1;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    char s[1000];
    for(int t=0;t<T;t++){
        scanf("%s",s);
        int len=strlen(s);
        char c;
        for(int i=0;i<len/2;i++){
            c=s[i];
            s[i]=s[len-1-i];
            s[len-1-i]=c;
        }
        char s0[1000];
        strcpy(s0,s);
        add(s,len);
        len=strlen(s);
        int jin=0;
        int weizhi=panduan(s,len);
        int e=0;
        while(weizhi!=-1){
            if(s[weizhi]=='0'||(e==0&&s[weizhi]<'9')) s[weizhi]++;
            else if(s[weizhi]<'9'&&e>0) {
                s[weizhi]--;
                int x=cmp(s,s0,len);
                if(x==-1) {
                    s[weizhi]+=2;
                    for(int ii=weizhi-1;ii>=0;ii--) s[ii]='0';
                }
            }
            else{
                int j=weizhi;
                s[j]='1';
                s[j+1]='0';
                int jinw=1,jieg=0;
                if(j+2>=len) jin=1;
                for(int w=j+2;w<len;w++){
                    jieg=jinw+s[w]-'0';
                    jinw=jieg/10;
                    jieg=jieg%10;
                    s[w]=jieg+'0';
                }
                if(jinw>0) jin=1;
            }
            weizhi=panduan(s,len);
            e++;
        }
        printf("case #%d:\n",t);
        if(jin==1) printf("1");
        for(int q=len-1;q>=0;q--) printf("%c",s[q]);
        printf("\n");
    }
    return 0;
}
