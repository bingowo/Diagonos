#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int GCD(int m,int n)
{
    if(n%m && n!=m )
        return GCD(n%m,m);
    else
        return m;

}
int main()
{
    long long aa=0,ab=0,ac=1;
    int t=0,d=1;//判据 是否有小数
    char s[100];
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='.'){
            t=i;
            break;
        }
    }
    if(t){
        for(int i=0;i<t;i++){
            aa = aa*3;
            if(s[i]=='1') aa+=1;
            if(s[i]=='2') aa-=1;
        }
        for(int i=t+1;i<strlen(s);i++){
            ab= ab*3;
            if(s[i]=='1') ab +=1;
            if(s[i]=='2') ab -=1;
            ac= ac*3;
        }
        if(ab<0){
            aa-=1;
            ab = ac+ab;
        }
        d=abs(GCD(ab,ac));
        ab=ab/d;
        ac=ac/d;
        if(aa==0) printf("%lld %lld",ab,ac);
        else{
        printf("%lld %lld %lld",aa,ab,ac);
        }
    }
    else{
        for(int i=0;i<strlen(s);i++){
            aa = aa*3;
            if(s[i]=='1') aa+=1;
            if(s[i]=='2') aa-=1;
        }
        printf("%lld",aa);
    }
    return 0;
}
