#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>
typedef long long ll;
typedef unsigned long long ull;
int Min(int a,int b){return a<b?a:b;}
int Max(int a,int b){return a>b?a:b;}

#define N 105
char sa[N],sb[N],t[N],*w;
int a[N],b[N],r[N];
int sign=1;

int Findc(char* s,char c){
    for(int i=0;s[i]!='\0';i++)
        if(s[i]==c)
            return i;
    return -1;
}

void Single(int* m,char* w){
    int a,n,xi,xn;
    xi=Findc(w,'x');
    if(xi>=0){
        xn=Findc(w,'^');
        if(xn>=0)
            n=atoi(w+xn+1);
        else
            n=1;
        w[xi]='\0';
        if(xi) a=atoi(w);
        else a=1;
        m[n]=sign*a;
    }
    else
        m[0]=sign*atoi(w);
}

void Fun(int* m, char* s){
    if(s[0]=='-') sign=-1;
    else sign=1;
    strcpy(t,s);
    w=strtok(t,"+-");
    Single(m,w);
    while(w=strtok(NULL,"+-")){
        sign=(*(s+(ull)(w-t)-1)=='-'?-1:1);
        Single(m,w);
    }
}

void Mul(){
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            r[i+j]+=a[i]*b[j];
}

void Print(){
    for(int i=N-1;i>=0;i--)
        if(r[i])
            printf("%d ",r[i]);
    printf("\n");
}

int main(){
    while(scanf("%s%s",sa,sb)>=0){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(r,0,sizeof(r));

        Fun(a,sa);
        Fun(b,sb);
        Mul();
        Print();
    }

    return 0;
}
