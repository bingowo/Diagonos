#include<stdio.h>
#include<string.h>

struct point{
    int a,b;
};

int main(){
    char s[101];
    scanf("%s",s);
    int l=strlen(s),q;
    struct point p[l+1];
    p[0].a=0;p[0].b=0;
    for(int i=0;i<l;i++){
        if(s[i]=='U'){
            p[i+1].a=p[i].a;
            p[i+1].b=p[i].b+1;
        }
        else if(s[i]=='D'){
            p[i+1].a=p[i].a;
            p[i+1].b=p[i].b-1;
        }
        else if(s[i]=='L'){
            p[i+1].a=p[i].a-1;
            p[i+1].b=p[i].b;
        }
        else if(s[i]=='R'){
            p[i+1].a=p[i].a+1;
            p[i+1].b=p[i].b;
        }
    }
    int x=p[l].a,y=p[l].b;
    scanf("%d",&q);
    while(q--){
        int a,b;
        scanf("%d %d",&a,&b);
        int i;
        ///for(i=0;i<=l;i++){
        //    if((a-p[i].a)/x==(b-p[i].b)/y){
       //         printf("Yes\n");
       //         break;
       //     }
       // }
        if(i>l)printf("No\n");
    }
}