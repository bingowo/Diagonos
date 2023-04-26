#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cmp(const void*a,const void*b){
    char *p1,*p2;
    p1=*((char**)a);
    p2=*((char**)b);
    int i=0,j=0;
    int rec1=-1,rec2=-1;
    for(;i<strlen(p1);i++){
        if(*(p1+i)>='0' && *(p1+i)<='9'){
            rec1=i;
        }
    }
    for(;j<strlen(p2);j++){
        if(*(p2+j)>='0' && *(p2+j)<='9'){
            rec2=j;
        }
    }
    if(rec1==-1 && rec2==-1) return strcmp(p1,p2);
    else if(rec1==-1 && rec2!=-1) return -1;
    else if(rec1!=-1 && rec2==-1) return 1;
    else if(rec1!=-1 && rec2!=-1){
        int k=0;
        int ans;
        while (*(p1+rec1+k)==*(p2+rec2+k)){
           if(isdigit(*(p1+rec1+k))==0){
               if(isdigit(*(p2+rec2+k))==0) ans=strcmp(p1,p2);
               else ans=-1;
               return ans;
           }
           if(isdigit(*(p2+rec2+k))==0){
               if(isdigit(*(p1+rec1+k))==0) ans=strcmp(p1,p2);
               else ans=1;
               return ans;
           }
           k++;
        }
        if(isdigit(*(p1+rec1+k))==0){
            if(isdigit(*(p2+rec2+k))==0) ans=strcmp(p1,p2);
            else ans=-1;
            return ans;
        }
        if(isdigit(*(p2+rec2+k))!=0){
            if(isdigit(*(p1+rec1+k))!=0) ans=*(p1+rec1+k)-*(p2+rec2+k);
            else ans=1;
            return ans;
        }
    }
}

int main(){
    char str[101][31];
    int i=0;
    while(scanf("%s ",str[i])!=EOF) i++;//
    qsort(str,i+1,sizeof(str[0]),cmp);
    for(i=0;i<strlen(str);i++){
        printf("%s ",str[i]);
    }
    printf("\n");
    return 0;
}
