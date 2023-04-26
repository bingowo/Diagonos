#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>

typedef long long ll;
typedef unsigned long long ull;

#define N 1000005
char s[N];
int ri=0,rj=0;
int book[256];


int main(){
    memset(book,-1,sizeof(book));
    scanf("%s",s);
    int i,j;
    for(i=0,j=0;s[j]!='\0';j++){
        if(book[s[j]]>=0){
            if(j-1-i>rj-ri)
                rj=j-1,ri=i;
            for(int k=i;k<book[s[j]];k++) book[s[k]]=-1;
            i=book[s[j]]+1;
            book[s[j]]=j;
        }
        else{
            book[s[j]]=j;
        }
    }
    if(j-1-i>rj-ri)
        rj=j-1,ri=i;
    for(i=ri;i<=rj;i++)
        printf("%c",s[i]);
    printf("\n");

    return 0;
}
