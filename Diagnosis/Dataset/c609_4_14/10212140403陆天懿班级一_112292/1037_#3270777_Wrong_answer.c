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
    scanf("%s",s);
    book[s[0]]=1;
    int i,j;
    for(i=0,j=0;s[j]!='\0';j++){
        if(book[s[j]]){
            if(j-1-i>rj-ri)
                rj=j-1,ri=i;
            i=j;
            memset(book,0,sizeof(book));
            book[s[i]]=1;
        }
        else{
            book[s[j]]=1;
        }
    }
    if(j-1-i>rj-ri)
        rj=j-1,ri=i;
    for(i=ri;i<=rj;i++)
        printf("%c",s[i]);
    printf("\n");

    return 0;
}
