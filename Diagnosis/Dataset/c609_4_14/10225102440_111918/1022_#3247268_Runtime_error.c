#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(void* a,void* b){
    char* m=(char*)a,*n=(char*)b;
    long long int i=0,j=0,k;
    while(m[i]!='@')i++;
    while(n[j]!='@')j++;
    i++,j++;
    while(i<strlen(m)&&j<strlen(n)){
        if(m[i]!=n[j]) return m[i]>n[j];
        i++,j++;
    }
    if(i==strlen(m)&&j<strlen(n)) return -1;
    else if(i<strlen(m)&&j==strlen(n)) return 1;
    else{
        i=j=0;
        while(1){
        if(m[i]!=n[j]) return n[j]>m[i];
        if(m[i]=='@')break;
        i++,j++;
        }
    }
    return 0;
}
int main()
{
    long long int n,i;
    scanf("%lld",&n);
    char **s;
    s=(char**)malloc(sizeof(char*)*n);
    for(i=0;i<n;i++){
        char* a=(char*)malloc(sizeof(char)*1000001);
        scanf("%s",&a);
        s[i]=(char*)malloc(sizeof(char)*(strlen(a)+1));
        strcpy(s[i],a);
        free(a);
    }
    qsort(s,n,sizeof(s[0]),cmp);
    for(i=0;i<n;i++)printf("%s\n",s[i]);
    return 0;
}
