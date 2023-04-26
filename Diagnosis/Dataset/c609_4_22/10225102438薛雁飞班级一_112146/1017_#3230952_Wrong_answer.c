#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmpd(const void* p1,const void* p2)
{
    int a,b;
    a=*(int*)p1;
    b=*(int*)p2;
    if(a>b) return -1;
    else return 1;
}
int cmpa(const void* p1,const void* p2)
{
    int a,b;
    a=*(int*)p1;
    b=*(int*)p2;
    if(a>b) return 1;
    else return -1;
}
int main()
{
    char c;
    int s[1002],i=0;
    scanf("%c",&c);
    while(scanf("%d",&s[i])!=EOF)
        i++;
    if(c=='A')
        qsort(s,i+1,sizeof(s[0]),cmpa);
    else qsort(s,i+1,sizeof(s[0]),cmpd);
    printf("%d ",s[1]);
    for(int n=1;n<i;n++){
        if(s[n-1]!=s[n]){
            printf("%d ",s[n]);
        }
    printf("\n");
    }
    return 0;
}
