#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int strnumcmp(const void* a, const void* b){
    int i = 0,j = 0;
    while((char*a)[i]==(char*b)[j]){
        i++;
        j++;
    }
    if(isdigit((*(char*)a)[i])&&(!isdigit((char*b)[j])) return 1;
    else if(!isdigit((char*a)[i])&&isdigit((char*b)[j])) return -1;
    else if(isdigit((char*a)[i])&&isdigit((char*)b[j])){
        int va = (char*a)[i]-'0',vb = (char*b)[j]-'0';
        i++;j++;
        while(isdigit((char*a)[i])){
            va = va*10+(char*a)[i++]-'0';
        }
        while(isdigit((char*b)[j])){
            vb = vb*10+(char*b)[j++]-'0';
        }
        if(va!=vb) return va-vb;
        return strnumcmp(a+i,b+j);
    }
    else{
        return (char*a)[i]-(char*b)[j];
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