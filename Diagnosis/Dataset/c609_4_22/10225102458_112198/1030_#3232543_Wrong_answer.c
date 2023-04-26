#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
double alpa[123];
int cmp(const void* a,const void *b)
{
    char aa=*(char*)a;
    char bb=*(char*)b;
    if(fabs(alpa[(int)bb]-alpa[(int)aa])<1e-7)return bb-aa;
    else if(alpa[(int)bb]>alpa[(int)aa])return 1;
    else return -1;




}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char str[102];
        for(int j=65;j<91;j++){scanf("%lf",alpa+j);alpa[j+32]=alpa[j];};
        scanf("%s",str);
        qsort(str,strlen(str),sizeof(str[0]),cmp);
        printf("case #%d:\n",i);
        printf("%s\n",str);
    }
    return 0;
}
