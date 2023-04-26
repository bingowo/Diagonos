#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char p0[20];
        scanf("%s",p0);
        int p1[255]={0};
        for(int i=0;i<strlen(p0);i++){
            p1[p0[i]]=p0[i];
        }
        int p2[20];
        int len=0;
        for(int i=0;i<254;i++){
            if(p1[i]!=0){
                p2[len]=p1[i];
                len++;
            }
        }
        printf("case #%d:\n",t);
        for(int i=0;i<len;i++){
            int p3[20]={0};
            p3[0]=p2[i];
            printf("%c\n",p3[0]);
            for(int j=1;j<len;j++){
                if(p2[j]>p3[j-1]){
                    p3[j]=p2[j];
                    for(int k=0;k<=j;k++){
                        printf("%c",p3[k]);
                    }
                    printf("\n");
                }
            }
        }
    }
    return 0;
}