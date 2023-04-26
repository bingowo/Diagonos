#include <stdio.h>
#include <stdlib.h>

int cmpa(void* num1,void* num2);
int cmpb(void* num1,void* num2);

int
main()
{
    char sequence;
    int count=0;
    int jnum[101] = {0};
    int pnum[1000] = {0};
    
    scanf("%c",&sequence);
    while (~scanf("%d",pnum+count))
    {
        if (*(jnum + *(pnum+count)) == 1) count--;
        else *(jnum + *(pnum+count)) = 1;
        count++;
    }
    int *num = (int*)malloc(count*sizeof(int));
    for (int i=0; i<count; i++) {
        *(num+i) = *(pnum+i);
    }
    
    sequence=='A'?qsort(num, count, sizeof(int), cmpa):qsort(num, count, sizeof(int), cmpb);
    
    for (int i=0; i<count; i++) {
        printf("%d",*(num+i));
        if (i<count-1) printf(" ");
        else printf("\n");
    }
    
    free(num);
    
    return 0;
}

int
cmpa(void* num1,void* num2)
{
    int a = *(int*)num1;
    int b = *(int*)num2;
    
    if (a>b) return 1;
    else return -1;
}

int
cmpb(void* num1,void* num2)
{
    int a = *(int*)num1;
    int b = *(int*)num2;
    
    if (b>a) return 1;
    else return -1;
}
