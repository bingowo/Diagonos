#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>

typedef long long ll;
typedef unsigned long long ull;

#define N 60
char s[60];

int Fun(int l,int r){
    if(r==l+1) return 1;
    int i,dep=0;
    for(i=l;i<=r;i++){
        if(s[i]=='(') dep++;
        else dep--;
        if(dep==0) break;
    }
    if(i==r) return 2*Fun(l+1,r-1);
    else return Fun(l,i)+Fun(i+1,r);
}

int main(){
    scanf("%s",s);
    printf("%d\n",Fun(0,strlen(s)-1));
    return 0;
}
