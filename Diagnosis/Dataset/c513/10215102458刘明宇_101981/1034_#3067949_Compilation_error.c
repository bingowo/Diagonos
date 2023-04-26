#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

double p[27];

int cmp(const void *a,const void *b){
    char *d1 = (char*)a;
    char *d2 = (char*)b;
    int a1,a2;
    int ord1,ord2;
    if(*d1 >= 'a' && *d1 <='z'){
        ord1 = *d1 -'a';
        a1 = p[ord1];
    }
    else{
        ord1 = *d1 - 'A';
        a1 = p[ord1];
    }
    if(*d2 >= 'a' && *d2 <='z'){
    ord2 = *d2 -'a';
        a2 = p[ord2];
    }
    else{
        ord2 = *d2 - 'A';
        a2 = p[ord2];
    }
    if(a1 > a2){
        return 1;
    }
    else if(fabs(a1-a2){
        if(ord1 == ord2) return *d2 - *d1;
        else return ord1 - ord2;
    }
    else return -1;
    
}


int main(){
    int T;
    scanf("%d",&T);
    int cnt = 0;
    while(T-->0){
        for(int i = 0;i<26;i++){
            scanf("%lf",&p[i]);
        }
        char s[101];
        scanf("%s",s);
        qsort(s,strlen(s),sizeof(s[0]),cmp);
        printf("case #%d:\n",cnt);
        printf("%s\n",s);
        cnt++;
    }

}