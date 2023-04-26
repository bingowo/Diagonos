#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct {
    int number;
    int total;
} ABC;
int main(){
    int m,n,i,j;
    int num=0;
    char a[1000];
    char b[1000];
    char c[1000];
    char d[1000];
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&n);
    for(j=0;j<n;j++){
        scanf("%d",&b[j]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(b[i]==a[j]){
                c[num]=b[i];
                d[num]=j;
                num++;
            }
        }
    }
    ABC s[n];
    for(i=0;i<num;i++){
        s[i].number=c[i];
        s[i].total=d[i];
    }
}