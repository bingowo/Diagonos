#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    long long int a,b,c,i,j,k,l,sign=1;
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
        for(j=i-1;j>=0;j--){
            if(s[j]=='1') a += k*1;
            else if(s[j]=='2') a += -k;
            k=k*3;
        }
        a=1;
        for(j=0;j<l-i-1;j++)
            c=c*3;
        b=0;
        for(j=i+1;i<l;i++){
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
        printf("%d %d %d",a,b,c);
    }
    return 0;
}
