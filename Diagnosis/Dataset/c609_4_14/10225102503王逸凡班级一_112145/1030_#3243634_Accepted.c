#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double table[26];

int cmp(const void *a,const void *b){
    char *p1 = (char*)a;
    char *p2 = (char*)b;
    int c1,c2;
    if (*p1 - 'A' >=0 && *p1 - 'A' <=26){
        c1 = *p1 - 'A';
    }else{
        c1 = *p1 - 'a';
    }
    if (*p2 - 'A' >=0 && *p2 - 'A' <=26){
        c2 = *p2 - 'A';
    }else{
        c2 = *p2 - 'a';
    }
    if (table[c1]>table[c2]){
        return -1;
    }else if (table[c2]>table[c1]){
        return 1;
    }else if (toupper(*p1)==toupper(*p2)){
        return *p2-*p1;
    }else{
        return toupper(*p1)-toupper(*p2);
    }

}


int main()
{
    int T;
    scanf("%d",&T);
    int i = 0;
    int j = 0;
    for (i=0;i<T;i++){
        char z[100]={0};
        for (j = 0;j<26;j++){
            scanf("%f",&table[j]);
        }
        scanf("%s",z);
        int len = strlen(z);
        qsort(z,len,sizeof(char),cmp);
        printf("case #%d:\n",i);
        printf("%s\n",z);
    }
    return 0;
}
