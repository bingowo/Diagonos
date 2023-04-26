#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int Letter[129];
struct mystring{
    char str[21];
    int dif;
};

int compar(const void*a,const void*b);

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int N;
        scanf("%d",&N);
        struct mystring strings[N];
        for(int n=0;n<N;n++)strings[n].dif=0;
        for(int n=0;n<N;n++){
            scanf("%s",strings[n].str);
            unsigned long int len=strlen(strings[n].str);
            for(int l=0;l<129;l++)Letter[l]=1;
            for(int i=0;i<len;i++){
                if(Letter[strings[n].str[i]]==1){
                    strings[n].dif++;
                    Letter[strings[n].str[i]]=0;
                }
            }
        }
        qsort(strings,N,sizeof(strings[0]),compar);
        printf("case #%d:\n",t);
        for(int n=0;n<N;n++)printf("%s\n",strings[n].str);
    }
    return 0;
}


int compar(const void*a,const void*b){
    struct mystring d1,d2;
    d1=*((struct mystring*)a);
    d2=*((struct mystring*)b);
    if(d1.dif==d2.dif)return strcmp(d1.str,d2.str);
    else return d2.dif-d1.dif;
}
