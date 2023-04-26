#include<stdio.h>
#include<string.h>
#include<math.h>
typedef unsigned long long int ull;
ull gcd(ull a,ull b){
    return a%b==0?b:gcd(b,a%b);
}
int main(){
    int t;
    scanf("%d",&t);
    int cas=0;
    while(t--){
        char s[20];
        scanf("%s",s);
        ull fz=0,fm=0;
        ull zfz=0,zfm=1;
        sscanf(s,"%llu",&zfz);
        ull g=gcd(zfz,zfm);
        zfz/=g;zfm/=g;
        if(strchr(s,'[')==NULL){
            char *p=strchr(s,'.')+1;
            fm=pow(10,strlen(p));
            sscanf(p,"%llu",&fz);
            ull g=gcd(fz,fm);
            fz/=g;fm/=g;//
        }
        else {
            char *p=strchr(s,'[')+1;
            while(*p!=']'){
                fm=fm*10+9;p++;
            }
            p=strchr(s,'.')+1;
            int l=0;
            while(*p!='['){l++;p++;}
            fm*=pow(10,l);
            p=strchr(s,'.')+1;
            sscanf(p,"%d",&fz);
            int minus=fz;
            p=strchr(s,'[')+1;
            while(*p!=']'){
                fz=fz*10+*p-'0';p++;
            }
            fz=fz-minus;
            ull g=gcd(fz,fm);
            fz/=g;fm/=g;
        }
        ull tfz=fz*zfm+zfz*fm,tfm=fm*zfm;
        fz=tfz;fm=tfm;
        g=gcd(fz,fm);fz/=g;fm/=g;
        printf("case #%d:\n%llu/%llu\n",cas++,fz,fm);
    }
}