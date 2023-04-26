#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char c;
    int cnt;
}PAIR;

int stat(char* s,PAIR* r)
{
    int rcnt=0,cnt=0,len=strlen(s);//rcnt:多少个不同的位置  cnt:相同位置的字母数
    char prev=s[0];
    for(int i=1;i<len;i++){
        if(s[i]!=prev){
            r[rcnt].c=prev;
            r[rcnt].cnt=cnt;
            cnt=0;
            rcnt++;
            prev=s[i];
        }
        else cnt++;
        if(i==len-1){
            r[rcnt].c=prev;
            r[rcnt].cnt=cnt;
            rcnt++;
        }
    }
    return rcnt;
}

int allSame(PAIR(*f)[100],int n,int *fn)
{
    int i=0,j=0;
    for(i=1;i<n;i++) if (fn[i]!=fn[0]) return 0;
    for(i=0;i<fn[0];i++){
        for(j=1;j<n;j++) if(f[j][i].c!=f[0][i].c) return 0;
    }
    return 1;
}

int cmp(const void* p3,const void* p4)
{
    int* p1=(int* )p3;
    int* p2=(int* )p4;
    return *p1-*p2;
}

int main()
{
    int n=0,ans=0,i=0,j=0;
    int fn[100000],a[100000];//fn存每个字符串的位置数 a存每个位置字符的个数
    PAIR f[100000][100];
    char s[101];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",s);
        fn[i]=stat(s,*(f+i));
    }
    if(allSame(f,n,fn)){
        for(i=0;i<fn[0];i++){
            for(j=0;j<n;j++) a[j]=f[j][i].cnt;
            qsort(a,n,sizeof(int),cmp);
            for(int k=0;k<n;k++) ans+=abs(a[k]-a[n/2]);
        }
        printf("%d\n",ans);
    }
    else printf("-1\n");
    return 0;
}
