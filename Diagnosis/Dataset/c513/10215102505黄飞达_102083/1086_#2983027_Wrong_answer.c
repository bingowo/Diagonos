#include<stdio.h>
#include<string.h>

int main(){
    char a[1005]={},b[1005]={};
    memset(a, 0, 1005);memset(b,0,1005);
    int n;
    scanf("%s %s %d", a, b, &n);
    int lena=strlen(a),lenb=strlen(b);
    char *pa=strstr(a, ".");
    if (pa==NULL) pa=a+lena;
    memmove(a+500-(pa-a), a, lena);
    for (int i=0; i<lena; i++) a[i]='\0';
    char *pb=strstr(b, ".");
    if (pb==NULL) pb=b+lenb;
    memmove(b+500-(pb-b), b, lenb);
    for (int i=0; i<lenb; i++) b[i]='\0';
    for (int i=0; i<1000; i++){
        if (a[i]=='\0') a[i]='0';
        if (b[i]=='\0') b[i]='0';
    }
    int up=0;
    //小数相减
    for (int i=1000;i>=501;i--){
        a[i]='0'+a[i]-b[i];
        if (a[i]<'0'){
            a[i]+=10;
            if (i==501) {up--;break;}
            a[i-1]-=1;
        }
    }
    //四舍五入
    if (a[500+n+1]>='5') a[500+n]++;
    for (int i=500+n; i>500; i--){
        if (a[i]>'9'){
            a[i]-=10;
            if (i==501) {up++;break;}
            a[i-1]++;
        }
    }
    a[499]+=up;
    up=0;
    int begin=0;
    //整数相减
    while(begin<500&&a[begin]=='0'&&b[begin]=='0') begin++;
    for (int i=499; i>=begin; i--){
        a[i]='0'+a[i]-b[i];
        if (a[i]<'0'){
            a[i]+=10;
            if (i==begin) {up=-1;break;}
            a[i-1]-=1;
        }
    }
    if (up==-1){
        if (a[500+n]!='0') a[500+n]='1'+('9'-a[500+n]);
        for (int i=500+n-1; i>=begin; i--) a[i]='0'+('9'-a[i]);
        printf("-");
    }
    begin-=2;
    while(begin<500&&a[begin]=='0') begin++;
    if (begin==500) printf("0");
    for (int i=begin; i<500; i++) printf("%c", a[i]);
    printf(".");
    for (int i=501; i<=500+n; i++) printf("%c", a[i]);
    return 0;
}