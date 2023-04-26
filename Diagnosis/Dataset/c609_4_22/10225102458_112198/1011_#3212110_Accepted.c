#include <stdio.h>
#include <string.h>
int change(char m)
{
    switch(m){
    case '1':return 1;break;
    case '0':return 0;break;
    default:return -1;break;

    }

}
int main()
{
    char s[50];
    int m,index=1;
    long long int dex=1,max=0,min=0,f;
    scanf("%s",s);
    int cnt1=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='.'){index=0;break;}
        cnt1++;
    }
    for(int i=cnt1-1;i>=0;i--){
        m=change(s[i]);
        max+=m*dex;
        dex*=3;
    }
    dex=1;
    for(int j=cnt1+1;j<strlen(s);j++){
        dex*=3;
    }
    f=dex;
    for(int j=cnt1+1;j<strlen(s);j++){
        m=change(s[j]);
        f/=3;
        min+=f*m;
    }
    if(index)printf("%lld",max);
    else if(max==0)printf("%lld %lld",min,dex);

    else {
        if(max>0){
            if(min<0){min+=dex;max--;}
            printf("%lld %lld %lld",max,min,dex);
        }
        else {
            if(min>0){max++;min-=dex;}
             printf("%lld %lld %lld",max,-min,dex);
        }
    }
    return 0;
}
