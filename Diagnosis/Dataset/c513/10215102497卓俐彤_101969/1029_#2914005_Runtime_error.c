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
    char useless[10];
    gets(useless);
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        char str[200];
        gets(str);
        unsigned long int len=strlen(str);
        char al[200];
        int j=0;
        for(int i=0;i<len;i++){
            if(isalpha(str[i]))al[j++]=str[i];
        }
        al[j]='\0';
        qsort(al,j,sizeof(al[0]),compar);
        j=0;
        for(int i=0;i<len;i++){
            if(isalpha(str[i]))str[i]=al[j++];
        }
        printf("%s\n",str);
    }
    return 0;
}
