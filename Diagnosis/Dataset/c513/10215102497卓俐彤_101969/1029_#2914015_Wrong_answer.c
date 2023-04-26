#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int compar(const void*a,const void*b){
    char d1,d2;
    d1=*((char*)a);
    d2=*((char*)b);
    if(d1<d2)return -1;
    else return 1;
}

int main(){
    int T;
    scanf("%d",&T);
    getchar();
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        char str[200]={0};
        int p=0;
        while((str[p++]=getchar())!='\n');
        char al[200];
        int j=0;
        for(int i=0;i<p;i++){
            if(isalpha(str[i]))al[j++]=str[i];
        }
        al[j]='\0';
        qsort(al,j,sizeof(al[0]),compar);
        j=0;
        for(int i=0;i<p;i++){
            if(isalpha(str[i]))str[i]=al[j++];
        }
        printf("%s",str);
    }
    return 0;
}
