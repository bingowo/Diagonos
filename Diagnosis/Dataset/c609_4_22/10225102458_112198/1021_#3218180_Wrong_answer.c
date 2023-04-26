#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int s[100];
int cmp(const void*a,const void* b)
{
    char* aa=(char*)a;
    char* bb=(char*)b;
    int len;
    len=(strlen(aa)>=strlen(bb)?strlen(bb):strlen(aa));
    for(int i=0;i<len;i++){
        int dex1=0,dex2=0;
        if('a'<=aa[i]&& 'z'>=aa[i]){dex1=1;aa[i]-=32;}
        if('a'<=bb[i]&& 'z'>=bb[i]){dex2=1;bb[i]-=32;}
        if(s[*(aa+i)]>s[*(bb+i)]){
            if(dex1)aa[i]+=32;
            if(dex2)bb[i]+=32;
            return 1;}
        else if(s[*(aa+i)]>s[*(bb+i)]){
            if(dex1)aa[i]+=32;
            if(dex2)bb[i]+=32;
            return -1;}
        else {
            if(dex1)aa[i]+=32;
            if(dex2)bb[i]+=32;
        }
    }
    return strlen(aa)-strlen(bb);
}
int main()
{
    char c;
    char ss[101][25];
    while((c=getchar())!=EOF){
            s[c]=0;
        for(int i=1;i<26;i++){
            c=getchar();
            s[c]=i;
        }
        getchar();
        int cnt=0;
        do{
            scanf("%s",ss[cnt++]);
        }while((c=getchar())!='\n');
        qsort(ss,cnt,sizeof(ss[0]),cmp);
        for(int i=0;i<cnt;i++){
            printf("%s",ss[i]);
            i==cnt-1?printf("\n"):printf(" ");
        }
    }


}
