#include<stdio.h>
#include<string.h>

int main(){
    int T,i;
    scanf("%d",&T);
    char str[100];
    long long N=T,num=0;
    while(T--){
        scanf("%s",str);
        int len=strlen(str);
        for(i=0;i<len;i++){
            num*=3;
            if(str[i]=='0')
                num+=0;
            else if(str[i]=='-')
                num-=1;
            else if(str[i]=='1')
                num+=1;
        }
        printf("case #%d:\n%lld\n",N-T-1,num);
    }
}