#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int a[27];
typedef struct {
    string[20];
}str;
int cmp(const void *p1,const void *p2){
    
}
int main() {
    char s[27];
    scanf("%s",s);
    do{
        str b[100];
        for(int i =0;i<26;i++){
            a[s[i]-'A']=i;
        }
        char c;
        int j=0;
        do{
            scanf("%s",b[j].string);
            j++;
            c=getchar();
        } while (c!='\n');
        qsort(b,j,sizeof(b[0]),cmp);
        for(int m=0;m<j;m++){
            printf("%s%c",b[m].string,m==j-1?'\n':' ');
        }
    }while (scanf("%s",s)!=EOF);
    return 0;
}
