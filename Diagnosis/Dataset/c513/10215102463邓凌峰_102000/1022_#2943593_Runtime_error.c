#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char yongHu[51];
    char zhuJi[51];
}E;


E emails[10000]={0};


void inPut(char *tmp,char *yh,char *zj){
    int i;
    for(i=0;tmp[i]!='@';i++){
        yh[i]=tmp[i];
    }
    i++;
    for(int j=0;i<strlen(tmp);i++,j++){
        zj[j]=tmp[i];
    }
}

int cmp(const void *a,const void *b){
    E pa=*(E*)a,pb=*(E*)b;
    if(strcmp(pa.zhuJi,pb.zhuJi)!=0){
        return strcmp(pa.zhuJi,pb.zhuJi);
    }
    else return strcmp(pb.yongHu,pa.yongHu);

}



int main()
{
    int n;scanf("%d",&n);
    char start=getchar();
    for(int i=0;i<n;i++){
        char tmp[102];
        scanf("%s",tmp);
        inPut(tmp,emails[i].yongHu,emails[i].zhuJi);
    }


    qsort(emails,n,sizeof(E),cmp);

    for(int i=0;i<n;i++){
        printf("%s@%s\n",emails[i].yongHu,emails[i].zhuJi);
    }
}







