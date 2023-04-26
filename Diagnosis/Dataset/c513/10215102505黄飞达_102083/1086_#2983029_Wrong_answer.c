#include<stdio.h>
#include<string.h>
#define M 2000

int main(){
    char a[M+5]={},b[M+5]={};
    memset(a, 0, M+5);memset(b,0,M+5);
    int n;
    scanf("%s %s %d", a, b, &n);
    int lena=strlen(a),lenb=strlen(b);
    char *pa=strstr(a, ".");
    if (pa==NULL) pa=a+lena;
    memmove(a+M/2-(pa-a), a, lena);
    for (int i=0; i<lena; i++) a[i]='\0';
    char *pb=strstr(b, ".");
    if (pb==NULL) pb=b+lenb;
    memmove(b+M/2-(pb-b), b, lenb);
    for (int i=0; i<lenb; i++) b[i]='\0';
    for (int i=0; i<M; i++){
        if (a[i]=='\0') a[i]='0';
        if (b[i]=='\0') b[i]='0';
    }
    int up=0;
    //小数相减
    for (int i=M;i>=M/2+1;i--){
        a[i]='0'+a[i]-b[i];
        if (a[i]<'0'){
            a[i]+=10;
            if (i==M/2+1) {up--;break;}
            a[i-1]-=1;
        }
    }
    //四舍五入
    if (a[M/2+n+1]>='5') a[M/2+n]++;
    for (int i=M/2+n; i>M/2; i--){
        if (a[i]>'9'){
            a[i]-=10;
            if (i==M/2+1) {up++;break;}
            a[i-1]++;
        }
    }
    a[M/2-1]+=up;
    up=0;
    int begin=0;
    //整数相减
    while(begin<M/2&&a[begin]=='0'&&b[begin]=='0') begin++;
    for (int i=M/2-1; i>=begin; i--){
        a[i]='0'+a[i]-b[i];
        if (a[i]<'0'){
            a[i]+=10;
            if (i==begin) {up=-1;break;}
            a[i-1]-=1;
        }
    }
    if (up==-1){
        if (a[M/2+n]!='0') a[M/2+n]='1'+('9'-a[M/2+n]);
        for (int i=M/2+n-1; i>=begin; i--) a[i]='0'+('9'-a[i]);
        printf("-");
    }
    begin-=2;
    while(begin<M/2&&a[begin]=='0') begin++;
    if (begin==M/2) printf("0");
    for (int i=begin; i<M/2; i++) printf("%c", a[i]);
    printf(".");
    for (int i=M/2+1; i<=M/2+n; i++) printf("%c", a[i]);
    return 0;
}