#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* p3,const void* p4)
{
    char* p1=(char* )p3;
    char* p2=(char* )p4;
    if(strcmp(p1,p2)>0) return 1;
    else return -1;
}

int main()
{
    int n=0,n1=0;
    scanf("%d",&n);
    char p[100][500]={0};
    for(int i=0;i<n;i++){
        char p1[500]={0};
        scanf("%s",p1);
        if(p1[4]!='s') {
            strcpy(p[n1++],p1);
        }
    }
    qsort(p,n1,sizeof(char[500]),cmp);
    for(int i=0;i<n1;i++){
        printf("%s\n",p[i]);
    }
    return 0;
}
