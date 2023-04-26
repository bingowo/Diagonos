#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    char *A = (char**)a, *B = (char**)b;
    //printf("A = %s, B = %s\n",A,B);
    //printf("A[0] = %s, B[0] = %s\n",A,B);
    return A[0]-B[0];
}

int cmp1(const void *a, const void *b)
{
    return strcmp((char*)a,(char*)b);
}

char s[1000][1000];
//memset(s,0,1000*1000*sizeof(char));

int main()
{
    int n = 0;
    int i = 0;
    //char *p[1000];memset(p,0,1000*sizeof(char*));
    scanf("%d",&n);


    for(i = 0;i<n;i++)
    {
        //char* s = malloc(1000*sizeof(char));memset(s,0,1000*sizeof(char));
        scanf("%s",s[i]);
        //p[i] = s;
    }
    //qsort(p,i,sizeof(char*),cmp);
    qsort(s,i,sizeof(s[0]),cmp1);

    for(int j = 0;j<i;j++)
    {
        printf("%s\n",s[j]);
    }
    //for(int k = 0;k<i;k++)
    //{
    //    printf("%s\n",p[k]);
    //}

    //for(int k1 = 0;k1<i;k1++)
    //{
    //    free(p[k1]);
    //}
    return 0;
}
