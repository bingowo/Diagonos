#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char str[105][35];
char* ps[105];
int n;

int GetNum(const char* s){
    int r=0,flag=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]>='0'&&s[i]<='9'){
            flag = 1;
            r=r*10+s[i]-'0';
        }
    }
    if(flag) return r;
    else return -1;
}

int Cmp(const char** pa, const char** pb){
    int na=GetNum(*pa),
        nb=GetNum(*pb);
    if(na!=nb) return na-nb;
    return strcmp(*pa, *pb);
}

int main(){
    while(scanf("%s",str+n)!=EOF){
        ps[n]=str[n];
        n++;
    }

    qsort(ps,n,sizeof(ps[0]),Cmp);

    for(int i=0;i<n;i++)
        printf("%s ",ps[i]);
    printf("\n");

    return 0;
}
