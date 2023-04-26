#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*a,const void* b)
{
    char* aa=(char*)a;
    char* bb=(char*)b;
    int m=0,n=0,cnt1=0,cnt2=0;
    for(int i=0;aa[i]!='\0';i++){
        if(aa[i]>='0' && aa[i]<='9'){
            cnt1=1;
            m=m*10+aa[i]-'0';
        }
    }
    for(int i=0;bb[i]!='\0';i++){
        if(bb[i]>='0' && bb[i]<='9'){
            cnt2=1;
            n=n*10+bb[i]-'0';
        }
    }
    if(!cnt1)m=-1;
    if(!cnt2)n=-1;
    if(m==n){
        return strcmp(aa,bb);
    }
    else if(m>n)return 1;
    else return -1;
}
int main()
{
    int cnt=0;
    char a[100][60];

    while(scanf("%s",a[cnt++])==1);
    qsort(a,cnt,sizeof(a[0]),cmp);
    for(int i=0;i<cnt;i++){
        printf("%s",a[i]);
        i==cnt-1?printf("\n"):printf(" ");
    }
    return 0;
}
