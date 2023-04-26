#include<stdio.h>
#include<string.h>

int main(){
    int T,i,num=0;
    scanf("%d",&T);
    char str[100];
    int N=T;
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
        printf("case #%d:\n%d\n",N-T-1,num);
    }
}