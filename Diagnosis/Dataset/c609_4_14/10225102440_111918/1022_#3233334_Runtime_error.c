#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000000
int cmp(void* a,void* b){
    char* m=(char*)a,*n=(char*)b;
    int i=0,j=0,k;
    while(m[i]!="@")i++;
    while(n[j]!="@")j++;
    i++,j++;
    while(i<strlen(m)&&j<strlen(n)){
        if(m[i]!=n[j]) return m[i]-n[j];
        i++,j++;
    }
    if(i==strlen(m)&&j<strlen(n)) return -1;
    else if(i<strlen(m)&&j==strlen(n)) return 1;
    else{
        i=j=0;
        while(1){
        if(m[i]!=n[j]) return m[i]-n[j];
        i++,j++;
        }
    }
}
int main()
{
    int n,i;
    scanf("%d",n);
    char s[n][100];
    for(i=0;i<n;i++) scanf("%s",&s[i]);
    qsort(s,i,sizeof(s[0]),cmp);
    for(i=0;i<n;i++)printf("%s",s[i]);
    return 0;
}
