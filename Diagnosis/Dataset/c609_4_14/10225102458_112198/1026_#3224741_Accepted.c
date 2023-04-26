#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void* a,const void *b)
{
    char* aa=(char*) a;
    char* bb=(char*) b;
    int cnt1=1,cnt2=1,dex1,dex2;
    for(int i=1;i<strlen(aa);i++){
        dex1=1;
        for(int j=0;j<i;j++){if(aa[i]==aa[j]){dex1=0;break;}}
        if(dex1)cnt1++;
    }
    for(int i=1;i<strlen(bb);i++){
        dex2=1;
        for(int j=0;j<i;j++){if(bb[i]==bb[j]){dex2=0;break;}}
        if(dex2)cnt2++;
    }
    if(cnt1==cnt2)return strcmp(aa,bb);
    else return cnt2-cnt1;
}
int main()
{
    int n,m;
    scanf("%d",&n);
    for(int j=0;j<n;j++){
        scanf("%d",&m);
        char mm[m][25];
        for(int i=0;i<m;i++)scanf("%s",mm[i]);
        qsort(mm,m,sizeof(mm[0]),cmp);
        printf("case #%d:\n",j);
        for(int i=0;i<m;i++){
            printf("%s\n",mm[i]);
        }
    }
    return 0;
}
