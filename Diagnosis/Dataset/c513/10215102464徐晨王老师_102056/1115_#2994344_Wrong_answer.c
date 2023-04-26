#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        char s[30];
        scanf("%s",s);
        int p[30];
        p[0]=0;
        for(int i=0;i<strlen(s);i++){
            p[i+1]=s[i]-48;
        }
        int len=strlen(s)+1;
        int flag=0;
        for(int i=len-2;i>=0;i--){
            for(int j=len-1;j>i;j--){
                if(p[j]>p[i]){
                    int x=p[j];
                    p[j]=p[i];
                    p[i]=x;
                    flag=1;
                    break;
                }
            }
            if(flag==1)break;
        }
        if(p[0]!=0)printf("%d",p[0]);
        for(int i=1;i<len;i++){
            printf("%d",p[i]);
        }
        printf("\n");
    }
}