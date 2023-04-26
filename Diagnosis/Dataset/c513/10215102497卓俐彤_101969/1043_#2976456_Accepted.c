#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void putin(char* s,char c,int i){
    int len=(int)strlen(s);
    memmove(s+i+1,s+i,len-i+1);
    *(s+i)=c;
}

int del(char* s){
    int res=0;
    int flag1=0,flag2=1,len;
    char *a=s;
    char *b=a+1;
    char *p1,*p2;
    while(1){
        len=(int)strlen(s);
        p1=s;
        p2=s+len;
        if(*a==*b){
            flag1=1;
        }else flag1=0;
        if(flag1){
            b++;
        }else{
            if(b-a>1){
                res+=(b-a);
                memmove(a,b,p2-b+1);
                flag2=0;
                if(*p1=='\0')break;
                else if(*a=='\0'){
                    a--;
                    b=a+1;
                    continue;
                }else{
                    b=a+1;continue;
                }
            }
            if(*b=='\0'){
                if(flag2==0){
                    a=s;
                    b=a+1;
                    flag2=1;
                }else break;
            }else{b++;a++;}
        }
    }
    return res;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char s[101],str[102];
        scanf("%s",s);
        int maxlen=0,len=0;
        for(int i=0;i<=strlen(s);i++){
            for(int j=0;j<3;j++){
                strcpy(str,s);
                putin(str,'A'+j,i);
                len=del(str);
                maxlen=maxlen>len?maxlen:len;
            }
        }
        printf("case #%d:\n%d\n",t,maxlen);
    }
}
