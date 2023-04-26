#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gongyin(int a,int b)
{
    int t=0;
    if(a>b){ //a<=b
        t=a;
        a=b;
        b=t;
    }
    if(b%a==0) return a;
    else{
        while(a>0){
            t=b%a;
            b=a;
            a=t;
        }
        return b;
    }
}

int main()
{
    int T=0,zi=0,mu=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char s[100];
        scanf("%s",s);
        int i=0,z=0,m=0,len=strlen(s);
        for(;i<len&&s[i]!='/';i++){
            z=z*10+s[i]-'0';
        }
        i++;
        for(;i<len;i++){
            m=m*10+s[i]-'0';
        }
        if(t==0){
            zi=z;
            mu=m;
        }
        else{
            int yin=gongyin(m,mu);
            z=z*mu/yin;
            zi=zi*m/yin;
            zi+=z;
            mu=m*mu/yin;
        }
        int y=gongyin(zi,mu);
        zi/=y;
        mu/=y;
    }
    printf("%d/%d\n",zi,mu);
    return 0;
}
