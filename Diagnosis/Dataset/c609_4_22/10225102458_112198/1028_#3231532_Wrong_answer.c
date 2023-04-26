#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{int** a[15];int mark;}student;
int cmp(const void* a,const void *b)
{
    char* aa=(char*)a;
    char* bb=(char*)b;
    return -strcmp(aa,bb);

}
int main()
{
    int n,t;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        getchar();
        char *str[t];
        char a[100000];
        for(int i=0;i<t;i++){
            gets(a);
            str[i]=(char*)malloc(sizeof(char)*(strlen(a)+2));
            strcpy(str[i],a);
        }
        qsort(str,t,sizeof(str[0]),cmp);
        for(int i=0;i<t;i++){
            for(int j=0;j<strlen(str[i])-3;j++)printf("%c",str[i][j]);
            printf("\n");
        }
    }
    return 0;
}
