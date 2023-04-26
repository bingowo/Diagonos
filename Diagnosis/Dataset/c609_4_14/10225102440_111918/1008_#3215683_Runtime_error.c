#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
char* ith(int x){
    char *s=(char*)malloc(8*sizeof(char));
    int i=0;
    if(x==0) return s="00000000";
    while(x){
        if(x%16<10) s[i++]=x%16+'0';
        else s[i++]=x%16+'a'-10;
        x=x/16;
    }
    while (i<8) s[i++]='0';
    s[i]=0;
    return s;
}
char* itb(int x){
    char *s=(char*)malloc(11*sizeof(char));
    int i;
    for(i=0;i<11;i++){
        s[i]=x%2;
        x=x/2;
    }
    return s;
}
char* dtb(double x){
    char *s=(char*)malloc(52*sizeof(char));
    int i;
    for(i=0;i<52;i++){
        if(x*2>=1){
            s[i]='1';
            x=x*2-1;}
        else {
            s[i]='0';
            x=x*2;}
    }
}
char cth(char* s){
    int x=0,k=8,i;
    for(i=0;i<4;i++){
        if(s[i]=='1')x=x+k;
        k=k/2;
    }
    if(x>10) return x+'a'-10;
    return x+'0';
}
char* fth(double x){
    char *s=(char*)malloc(16*sizeof(char)),*m=(char*)malloc(64*sizeof(char));
    int i=0,j,a,n=-1;
    double b;
    if(x==0) s="0000000000000000";
    else{
        if(x<0) m[0]='1',x=-x;
        else m[0]='0';
        a=(int)x;
        while(a/2!=0) a=a/2,n++;
        m[1]=itb(n+127);
        printf("%s",m);
        while(x>=2) x=x/2;
        x=x-1;
        m[12]=dtb(x);
        for(i=0;i<16;i++){
            s[i]=cth(m[i]);
        }
    }
    return s;
}

int main()
{
    char a[100],*s;
    int x,i,j,k,l=0;
    double y;
    while(scanf("%s",a)!=0){
        for(j=0;j<strlen(a);j++){
            if(a[j]=='.') {
                y=atof(a);
            break;}
        }
        if(j==strlen(a)){
            x=atoi(a);
            printf("%d",x);
            if(x>=0)s=ith(x);
            else s=ith(INT_MAX+x);
            for(k=0;k<4;k++){
                printf("%c%c ",*(char*)(s+2*k+1),*(char*)(s+k*2));
            }
            printf("\n");
        }
        else{
            s=fth(y);
            s[64]=0;
            for(k=0;k<8;k++){
                printf("%c%c ",*(s+k*2),*(s+k*2+1));
            }
            printf("\n");
        }
    }
    return 0;
}

