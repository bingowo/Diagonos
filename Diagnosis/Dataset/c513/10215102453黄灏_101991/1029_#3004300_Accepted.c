#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int cmp(const void *a,const void *b){
    char x = *(char *)a;
    char y = *(char *)b;
    return x-y;
}

int main(){
    int T;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++){
        char s[250],ans[250];
        gets(s);
        int l= strlen(s);
        for(int j=0;j<250;j++) ans[j]='a';
        char a[200];
        int count=0;
        for(int j=0;j<l;j++){
            if(s[j]<='Z' && s[j]>='A') {
                a[count]=s[j]; count++;
            } else{ans[j]=s[j];}
        }
        qsort(a,count,sizeof(a[0]),cmp);
        count=0;
        for(int k=0;k<l;k++){
            if(ans[k]=='a') {ans[k]=a[count];count++;}
        }
        printf("case #%d:\n",i);
        for(int k=0;k<l;k++){
            printf("%c",ans[k]);
        }
        printf("\n");
    }
    return 0;
}
