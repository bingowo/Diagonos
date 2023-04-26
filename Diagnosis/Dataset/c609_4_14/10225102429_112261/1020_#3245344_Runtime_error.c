#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int strnumcmp(const void* a, const void* b){
    int i = 0,j = 0;
    char *pa = (char*)a,*pb = (char*)b;
    while(pa[i]==pb[j]){
        i++;
        j++;
    }
    if(isdigit(pa[i])&&(!isdigit(pb[j]))) return 1;
    else if(!isdigit(pa[i])&&isdigit(pb[j])) return -1;
    else if(isdigit(pa[i])&&isdigit(pb[j])){
        int va = pa[i]-'0',vb = pb[j]-'0';
        i++;j++;
        while(isdigit(pa[i])){
            va = va*10+pa[i++]-'0';
        }
        while(isdigit(pb[j])){
            vb = vb*10+pb[j++]-'0';
        }
        if(va!=vb) return va-vb;
        return strnumcmp(a+i,b+j);
    }
    else{
        return pa[i]-pb[j];
    }
}
int main(){
    char* WordPtr[101];
    int i = 0;
    for(; i<101; i++){
        if(scanf("%s",WordPtr+i)<1) break;
    }
    qsort(WordPtr,i,sizeof(char*),strnumcmp);
    for(int k = 0; k<i; k++){
        printf("%s ",WordPtr[k]);
    }
    return 0;
}