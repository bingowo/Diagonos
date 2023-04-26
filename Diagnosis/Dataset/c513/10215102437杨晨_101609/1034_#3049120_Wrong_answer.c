#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a, void *b);
float fre[26];
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        for(int j=0;j<26;j++){
            scanf("%f",&fre[j]);
        }
        char a[100];
        scanf("%s",a);
        int len=strlen(a);
        qsort(a,len,sizeof(char),cmp);
        printf("case #%d:\n",T);
        printf("%s\n",a);
    }
}
int cmp(const void *a, void *b){
    char m=*(char*)a;
    char n=*(char*)b;
    if('a'<=m<='z'&'a'<=n<='z'){
        if(fre[m-'a']<fre[n-'a']) return 1;
        else return -1;
        }
    else if('A'<=m<='Z'&'A'<=n<='Z'){
        if(fre[m-'A']<fre[n-'A']) return 1;
        else return -1;
        }
    else if('A'<=m<='Z'&'a'<=n<='z'){
        if(fre[m-'A']==fre[n-'a']) return 1;
        else {
            if(fre[m-'A']<fre[n-'a']) return 1;
            else return -1;
        }
        }
    else{
         if(fre[m-'a']<fre[n-'A']) return 1;
            else return -1;
    }
    }
