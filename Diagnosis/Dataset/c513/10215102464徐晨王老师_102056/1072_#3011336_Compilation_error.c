#include <stdio.h>
#include <string.h>
#include <math.h>
typedef long long int lli;
lli myabs(lli d){
    if(d<0)return -d;
    else return d;
}
void path(lli a,lli b,lli len,char s[100]){
    if(len==0)return;
    if(myabs(a)>myabs(b)){
        if(a>0){
            strcat(s,"E");
            path(a-len,b,len/2,s);
        }
        else{
            strcat(s,"W");
            path(a+len,b,len/2,s);
        }
    }
    else{
        if(b>0){
            strcat(s,"N");
            path(a,b-len,len/2,s);
        }
        else{
            strcat(,s"S");
            path(a,b+len,len/2,s);
        }
    }
}
int main(){
    lli x,y;
    scanf("%lld%lld",&x,&y);
    lli z=myabs(x)+myabs(y)+1;
    if(x==0&&y==0){printf("0");}
    else if(z%2==0){
    double zz=log(z)/log(2);
    lli zzz=0;
    while(zzz<zz)zzz++;
    printf("%lld\n",zzz);
    lli step=1;
    for(int i=1;i<zzz;i++){
        step=step*2;
    }
    char s[100]={"\0"};
    path(x,y,step,s);
    for(int i=strlen(s)-1;i>=0,i--){
        printf("%c",s[i]);
    }
    }
    else printf("-1");
    return 0;
}
