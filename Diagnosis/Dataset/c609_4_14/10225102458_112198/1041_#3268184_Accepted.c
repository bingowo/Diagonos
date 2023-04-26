#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void* a,const void* b)
{
    char* aa=(char*)a;
    char* bb=(char*)b;
    return strcmp(aa,bb);
}
int change(int cnt)
{
    int a=1;
    for(int i=0;i<cnt;i++){
        a*=2;
    }
    return a;
}
int main()

{
    int n;
    scanf("%d",&n);
    char s[20];
    int alpa[123];
    for(int i=0;i<n;i++){
        int cnt=0,num,nuf,count;
        char a[20]={0};
        char aa[100000][20];
        memset(alpa,0,sizeof(alpa));
        scanf("%s",s);
        for(int j=0;s[j]!='\0';j++){
            alpa[s[j]]=1;
        }
        for(int i=0;i<123;i++){
            if(alpa[i])a[cnt++]=i;
        }
        num=change(cnt);
        count=0;
        for(int i=1;i<num;i++){
            nuf=0;
            for(int j=0;j<cnt;j++){
                if((i>>j)&1){aa[count][nuf++]=a[j];}
            }
            aa[count][nuf]='\0',count++;
        }
        qsort(aa,count,sizeof(aa[0]),cmp);
        printf("case #%d:\n",i);
        for(int i=0;i<count;i++){
            printf("%s\n",aa[i]);
        }
    }
    return 0;
}
