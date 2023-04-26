#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct {
    char s[101];
}word;
int strnumcmp(const void* a, const void* b){
    int i = 0,j = 0;
    char *pa = (*(word*)a).s,*pb = (*(word*)b).s;
    int lena = strlen(pa),lenb = strlen(pb);
    while(i<lena&&j<lenb&&pa[i]==pb[j]){
        i++;
        j++;
    }
    if(i==lena&&j<lenb) return -1;
    if(j==lenb&&i<lena) return 1;
    if(isdigit(pa[i])&&(!isdigit(pb[j]))) return 1;
    else if(!isdigit(pa[i])&&isdigit(pb[j])) return -1;
    else if(isdigit(pa[i])&&isdigit(pb[j])){
        int va = pa[i]-'0',vb = pb[j]-'0';
        i++;j++;
        while(i<lena&&isdigit(pa[i])){
            va = va*10+pa[i++]-'0';
        }
        while(j<lenb&&isdigit(pb[j])){
            vb = vb*10+pb[j++]-'0';
        }
        if(va!=vb) return va-vb;
        // return strnumcmp(pa+i,pb+j);
    }
    else{
        return pa[i]-pb[j];
    }
}
int main(){
    word Set[101];
    for(int j = 0; j<101; j++){
        memset(Set[j].s,0,sizeof(Set[j].s));
    }
    int i = 0;
    for(; i<101; i++){
        if(scanf("%s", Set[i].s) < 1) break;
    }
    qsort(Set, i, sizeof(word), strnumcmp);
    for(int k = 0; k<i; k++){
        printf("%s ", Set[k].s);
    }
    return 0;
}