#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Email
{
    char s1[1000];
    char s2[1000];
}email;

int cmp(const void *a,const void *b)
{
    email A = *(email*)a,B = *(email*)b;
    if(strcmp(A.s2,B.s2)!=0){return strcmp(A.s2,B.s2);}
    else {return -1*strcmp(A.s1,B.s1);}
}

int main()
{
    int n = 0;
    scanf("%d",&n);
    getchar();//清除回车

    email* e = (email*)calloc(n,sizeof(email));
    for(int i = 0;i<n;i++)
    {
        scanf("%[0-9||a-z||A-Z||_]@%s",e[i].s1,e[i].s2);
        getchar();//清除回车
    }

    qsort(e,n,sizeof(email),cmp);

    for(int i = 0;i<n;i++)
    {
        printf("%s@%s\n",e[i].s1,e[i].s2);
    }
    free(e);
    return 0;
}
