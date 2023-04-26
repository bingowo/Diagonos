#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i,j,l,sign=1;
    long long int a,b,c,k;
    char s[40];
    scanf("%s",&s);
    l=strlen(s);
    for(i=0;i<l;i++){
        if(s[i]=='.'){
            sign=3;
            break;
        }
    }
    if(sign==1){
        k=1;
        a=0;
        for(j=l-1;j>=0;j--){
            if(s[j]=='1') a=a+k*1;
            else if(s[j]=='2') a=a-k;
            k=k*3;
        }
        printf("%d",a);
    }
    else{
        k=1;
        a=0;
        b=0;
        c=1;
        for(j=i-1;j>=0;j--){
            if(s[j]=='1') a += k*1;
            else if(s[j]=='2') a += -k;
            k=k*3;
        }
        for(j=0;j<l-i-1;j++)
            c=c*3;
        for(j=i+1;j<l;j++){
            b=b*3;
            if(s[j]=='1') b += 1;
            else if(s[j]=='2') b += -1;
        }
        for(k=b;k>1;k--){
            if((b%k==0)&&(c%k==0)){
                b=b/k;
                c=c/k;
            }
        }
        while(a&&b<0){
            a=a-1;
            b=b+c;
        }
        if(a<0){
            b=c-b;
            a=a+1;
        }
        if(a==0) printf("%lld %lld",b,c);
        else printf("%lld %lld %lld",a,b,c);
    }
    return 0;
}
