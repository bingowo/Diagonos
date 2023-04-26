#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxstr 100

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    char res[maxstr];
    int n,i=0;
    while(a){
        n=a%b;
        int a0=a;
        a/=b;
        if(n<0){
            a++;
            n=a0-a*b;
        }
        if(n<10)res[i++]=n+'0';
        else res[i++]=n+'A'-10;
    }
    res[i]='\0';
    for(int j=i-1;j>=0;j--)printf("%c",res[j]);
    return 0;
}
