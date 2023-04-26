#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*a, const void* b){
    return strcmp((char*)a,(char*)b);
}
int main(){
    int T; scanf("%d",&T);
    for(int i = 0; i<T; i++){
        printf("case #%d:\n");
        char *Words[255];
        char c;
        int i = 0,j = 0;
        while((c = getchar())!='\n'){
            if(c==' '||c==','||c=='.'||c=='!'||c=='?') {
                Words[i][j] = 0;
                j = 0;
                i++;
                continue;
            }
            Words[i][j] = c;
            j++;
        }
        qsort()    
    }
    return 0;
}