#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, void *b);
float fre[26];
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        for(int i=0;i<26;i++){
            scanf("%f",&fre[i]);
        }
        char a[100];
        char *p=a;
        while(scanf("%c",p++) != EOF){i++;}
        qsort(a,i,sizeof(char),cmp);
        printf("case #%d:\n",T);
        printf("%s\n",a);
    }
}
int cmp(const void *a, void *b){
    char m=*(char*)a;
    char n=*(char*)b;
    int m1=m-'A';
    int n1=n-'A';
    if(m-'a'>=0&&m-'A'<0){m1=m-'a';}
    if(n-'a'>=0&&n-'A'<0){n1=n-'a';}
    if(m1==n1){
        return m-n;
    }
    else{
        if(fre[m1]-fre[n1]>0){return 1;}
        else return -1;
    }
    }
