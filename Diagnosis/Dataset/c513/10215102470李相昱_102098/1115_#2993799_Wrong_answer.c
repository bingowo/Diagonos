#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *p1,const void *p2){
    int a=*(int *)p1;
    int b=*(int *)p2;
    return a-b;
}
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char s[21];
        int num[20];
        scanf("%s",s);
        int len= strlen(s);
        for(int p=0;p<len;p++){
            num[p]=s[p]-'0';
        }
        int sign=0;
        for(int j=len-2;j>=0;j--){
            if(num[j]<num[len-1]){
                sign=j;
                break;
            }
        }
        int temp=num[sign];
        num[sign]=num[len-1];
        num[len-1]=temp;
        qsort(&num[sign+1],len-sign-1,sizeof(int),cmp);
        printf("case #%d:\n",i);
        for(int q=0;q<len;q++){
            printf("%d",num[q]);
        }
        printf("\n");
    }
    return 0;
}
