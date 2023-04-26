#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char s[30];
    scanf("%s",s);
    int len=strlen(s);
    int p,i,a,b,c;
    p = 0;
    while (p<len){
        if (s[p]=='.'){
            break;
        }
        p++;
    }
    a=0;b=0;c=0;
    for (i=0;i<len;i++){
        if (i==p){
            continue;
        }
        else{
            if (i<p){
                if (s[i]=='1'){
                    a += pow(3,p-i-1);
                }
                if (s[i]=='2'){
                    a -= pow(3,p-i-1);
                }
            }
            if (i>p){
                c = pow(3,len-p-1);
                if (s[i]=='1'){
                    b += pow(3,len-1-i);
                }
                if (s[i]=='2'){
                    b -= pow(3,len-1-i);
                }
            }
        }
    }
    if (b<0 && a!=0){
        a = a-1;
        b = c-b;
        }
    if (a=0){
        printf("%d %d",b,c);
    }
    else if (b=0){
        printf("%d",a);
    }
    else{
        printf("%d %d %d",a,b,c);
    }
    return 0;
}
