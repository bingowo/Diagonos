#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void become(long long int a){
    char s[15]={0};
    int i=0;
    int x=a;
    while(x!=0){
        s[i]=x%10+48;
        //printf("%c\n",s[i]);
        i=i+1;
        x=x/10;
    }
    int len=0;
    for(int i=0;i<strlen(s);i++){
       if(s[i]==s[strlen(s)-i-1])len=len+1;
       else break;
    }
    //printf("%d%d",len,strlen(s));
    if(len==strlen(s)){printf("%s",s);return;}
    else {//printf("%d\n",atoi(s));
            return become(atoi(s)+a);
    }

}
int main(){
    long long int n;
    scanf("%d",&n);
    become(n);
    return 0;
}
