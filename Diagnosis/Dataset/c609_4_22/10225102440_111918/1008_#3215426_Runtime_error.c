#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* ith(int x){
    char *s=(char*)malloc(8*sizeof(char));
    int i=0;
    if(x==0) s="00000000";
    else if(x<0) x=256+x;
    while(x){
        if(x%16<10) s[i++]=x%16+'0';
        else s[i++]=x%16+'a'-10;
        x=x/16;
    }
    while (i<8) s[i++]='0';
    s[i]=0;
    printf("%s",s);
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

char* fth(double x){
    char *s=(char*)malloc(16*sizeof(char)),m[64];
    int i=0,j,a,n=-1;
    double b;
    if(x==0) s="0000000000000000";
    else{
        if(x<0) m[0]='1',x=-x;
        else m[0]='0';
        a=(int)x;
        while(a/2!=0) a=a/2,n++;
        for(j=0;j<11;j++){
            
        }
    }
}

int main()
{
    char a[100],*s;
    int x,i,j,k,l=0;
    double y;
    while(scanf("%s",a)!=0){
        for(j=0;j<strlen(a);j++){
            if(a[j]=='.') y=atof(a);
        }
        if(j==strlen(a)){
            x=atoi(a);
            s=ith(x);
            for(k=0;k<4;k++){
                printf("%c%c ",*(char*)(s+2*k+1),*(char*)(s+k*2));
            }
            printf("\n");
        }
        else{

        }
    }
    return 0;
}
