#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char str[501],res[501]={0};
        int numres[500];
        scanf("%s",str);
        char a=str[0];
        int num=1,j=0,i;
        for(i=1;i<strlen(str);i++){
            if(num==255){
                numres[j]=num;
                res[j++]=a;
                a=str[i];
                num=1;
            }
            if(str[i]==a)num++;
            else{
                numres[j]=num;
                res[j++]=a;
                a=str[i];
                num=1;
            }
        }
        numres[j]=num;
        res[j++]=a;
        a=str[i];
        num=1;
        res[j]='\0';
        printf("case #%d:\n",t);
        for(int i=0;i<strlen(res);i++){
            printf("%d%c",numres[i],res[i]);
        }
        printf("\n");
    }
}
