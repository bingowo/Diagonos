#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
double alpa[91];
int cmp(const void* a,const void *b)
{
    char aa=*(char*)a;
    char bb=*(char*)b;
    char a1,b1;
    if('a'<=aa && aa<='z')a1=aa-32;else a1=aa;
    if('a'<=bb && bb<='z')b1=bb-32;else b1=bb;
    if(alpa[(int)b1]==alpa[(int)a1]){
        if(a1==b1)return bb-aa;
        else return a1-b1;
    }
    else if(alpa[(int)b1]>alpa[(int)a1])return 1;
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
