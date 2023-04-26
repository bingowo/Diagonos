// 关键是对于进制的理解程度
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int T,n,l;
char s[1005];
char get(int x){
    if(x>=0&&x<26) return x+'A';
    else if(x<52) return x-26+'a';
    else if(x<62) return x-52+'0';
    else if(x==62) return '+';
    else return '/';
}
char stk[10];
int main() {
    scanf("%d\n",&T);
    for(int c=0;c<T;c++){
        scanf("%s",s);
        l=strlen(s);
        printf("case #%d:\n",c);
        int p,cnt;
        for(int i=0;i<l/3;i++){ //处理正常的情况
            p=65536*s[i*3]+256*s[i*3+1]+s[i*3+2],cnt=0;  //关键
            while(p) stk[++cnt]=get(p%64),p/=64;
            for(int j=cnt;j;j--) putchar(stk[j]);
        }
        p=cnt=0;
        for(int i=l/3*3;i<l;i++) p=p*256+s[i]; //再处理特殊情况
        if(l%3==1) p<<=4,stk[++cnt]='=',stk[++cnt]='=';
        else if(l%3==2) p<<=2,stk[++cnt]='=';
        while(p) stk[++cnt]=get(p%64),p/=64;
        for(int j=cnt;j;j--) putchar(stk[j]);
        puts("");
    }
    return 0;
}
