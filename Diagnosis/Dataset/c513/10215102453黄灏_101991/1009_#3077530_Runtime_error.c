#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void result(int all,int ones){
    int a=all,b=ones,temp;
    temp=a%b;
    while (temp!=0){
        a=b;
        b=temp;
        temp=a%b;
    }
    all/=b;ones/=b;
    printf("%d/%d",ones,all);
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        char a[1000]={'\0'};
        char c;int j=0;
        while(c=getchar()!='\n') a[j++]=c;
        int ones=0,all;
        int len= strlen(a);
        for(int j=0;j<len;j++){
            int mark=1;
            for(int k=0;k<8;k++){
                if(a[j]&mark) ones++;
                mark=mark<<1;
            }
        }
        all=8*len;
        result(all,ones);
    }
    return 0;
}