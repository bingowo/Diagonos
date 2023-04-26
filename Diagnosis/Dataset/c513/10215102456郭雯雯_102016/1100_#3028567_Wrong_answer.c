#include<stdio.h>
#include<string.h>

struct point{
    int a,b;
};

int main(){
    char s[101];
    scanf("%s",s);
    int l=strlen(s);
    struct point p[l+1];
    p[0].a=0;p[0].b=0;
    for(int i=0;i<l;i++){
        if(s[i]=='U'){
            p[i+1].a=p[i].a;
            p[i+1].b=p[i].b+1;
        }
    }
    int q;
    scanf("%d",&q);
    
}