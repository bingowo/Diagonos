#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
double fre[128];
int cmp(const void* a, const void* b){
    char ca = *(char*)a,cb = *(char*)b;
    double fa = fre[ca],fb = fre[cb];
    if(fa!=fb){
        if(fa>fb) return -1;
        return 1;
    }
    if(islower(ca)){
        if(islower(cb)) return ca-cb;
        cb = tolower(cb);
        if(ca<=cb) return -1;
        return 1;
    }
    else{
        if(isupper(cb)) return ca-cb;
        cb = toupper(cb);
        if(ca<cb) return -1;
        return 1;
    }
}
void read(char *s){
	char c;
	int i = 0;
	while((c=getchar())!='\n'){
		s[i++] = c;
	}
	s[i] = 0;
}
int main(){
    int T; scanf("%d",&T);
    for(int i =0; i<T; i++){
        printf("case #%d:\n",i);
        for(char c = 'a',d = 'A';c<='z'; c++,d++){
            double frequ;
            scanf("%lf",&frequ);
            fre[c] = frequ;
            fre[d] = frequ;
        }
        char s[101] = {0};
        read(s);
        int len = strlen(s);
        qsort(s,len,sizeof(char),cmp);
        printf("%s\n",s);
    }
    return 0;
}