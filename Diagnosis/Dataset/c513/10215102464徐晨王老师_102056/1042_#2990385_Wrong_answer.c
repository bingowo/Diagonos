#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(int* p,int p4[20],int index,int lens){
    if(p[index]>p4[index]){
        p4[index]=p[index];
        for(int i=0;i<=index;i++){
            printf("%c",p4[i]);
        }
        printf("\n");
        for(int i=index;i<lens;i++){
            add(p,p4,i,lens);
        }
    }
    else return;
}

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
            int p3[20];
            for(int j=0;j<len;j++){
                add(p2,p3,j,len);
            }
            }
        }


    return 0;
}
