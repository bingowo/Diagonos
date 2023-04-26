#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    char s[501];
}string;
int cmp(const void *p1,const void *p2){
    string *a = (string *)p1;
    string *b = (string *)p2;
    return strcmp(a->s,b->s);
}
string a[501];
int main() {
    int T;
    scanf("%d",&T);
    getchar();
    for(int i=0;i<T;i++){
        char c;
        c=getchar();
        int len=0,p=0,t=0;
        while(c!='\n'){
            if(c!=' '&&c!=','&&c!='.'
               &&c!='!'&&c!='?')
            {
                a[p].s[t]=c;
                t++;
                len++;
            }else{
                a[p].s[t]=0;
                len=0;
                p++;
                t=0;
            }
            c = getchar();
        }
        qsort(a,p,sizeof(string),cmp);
        printf("case #%d:\n",i);
        printf("%s",a[0].s);
        for(int q=1;q<p;q++){
            if(strcmp(a[q].s,a[q-1].s)!=0){
                printf(" %s",a[q].s);
            }
        }
        printf("\n");
        memset(a,0,sizeof(a));
    }
    return 0;
}
