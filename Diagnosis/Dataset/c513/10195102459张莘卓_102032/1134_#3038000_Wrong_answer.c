#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *id;
    int *grade;
}S;

int flag;
char subject[4] = {'A','C','M','E'};
int cmp(const void* pa, const void* pb) {
    S *a=(S*)pa, *b=(S*)pb;
    if(a->grade[flag] == b->grade[flag])
        return strcmp(a->id,b->id);
    else return b->grade[flag] - a->grade[flag];
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        int n;
        scanf("%d",&n);
        S* a = (S*) malloc(n*sizeof(S));
        for(int i=0; i<n; ++i) {
            a[i].id = (char*) malloc(12*sizeof(char));
            scanf("%s",a[i].id);
            a[i].grade = (int*) malloc(4*sizeof(int));
            for(int k=1; k<4; ++k){
                scanf("%d",&a[i].grade[k]);
                a[i].grade[0] += a[i].grade[k];
            }
            *a[i].grade = (int)(*a[i].grade/3.0 + 0.5);
        }
        printf("case #%d:\n",j);
        for(flag=0; flag<4; ++flag) {
            qsort(a, n, sizeof(a[0]), cmp);
            printf("%c:\n",subject[flag]);
            int max = a->grade[flag];
            for(int i=0; i<n && a[i].grade[flag]==max; ++i)
                printf("%s\n",a[i].id);
        }
        for(int i=0; i<n; ++i) { free(a[i].id);  free(a[i].grade);}
        free(a);
    }
    return 0;
}
