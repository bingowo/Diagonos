#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef long long int lli;

struct string{
    char s[20];
    lli minvalue;
};

int readnum(char c){
    int res;
    if(isdigit(c)){
        res=c-'0';
    }else if(isupper(c)){
        res=c-'A'+10;
    }else{
        res=c-'a'+36;
    }
    return res;
}

lli value(char s[]){
    int find[62],num[62];
    int r=0;
    for(int i=0;i<62;i++){
        find[i]=-1;
        num[i]=-1;
    }
    for(int i=0;i<strlen(s);i++){
        find[i]=readnum(s[i]);
    }
    num[find[0]]=1;
    for(int i=1;i<strlen(s);i++){
        if(num[find[i]]==-1){
            if(!r){
                num[find[i]]=r;
                r=2;
            }else{
                num[find[i]]=r++;
            }
        }
    }
    if(!r)r=2;
    lli v=0;
    for(int i=0;i<strlen(s);i++)v=v*r+num[find[i]];
    return v;
}

int cmp(const void*a,const void*b){
    struct string d1,d2;
    d1=*((struct string*)a);
    d2=*((struct string*)b);
    if(d1.minvalue==d2.minvalue)return strcmp(d1.s, d2.s);
    else if(d1.minvalue>d2.minvalue)return 1;
    else return -1;
}

int main(){
    int T;
    scanf("%d",&T);
    struct string strings[T];
    for(int t=0;t<T;t++){
        scanf("%s",strings[t].s);
        strings[t].minvalue=value(strings[t].s);
    }
    qsort(strings,T,sizeof(strings[0]),cmp);
    for(int t=0;t<T;t++)printf("%s\n",strings[t].s);
    return 0;
}
