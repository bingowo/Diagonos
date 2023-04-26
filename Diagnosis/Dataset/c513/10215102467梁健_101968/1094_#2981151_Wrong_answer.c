#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
typedef struct dot
{
    char s[150];
    int len;
}DOT;
int cmp(const void *a,const void *b)
{
    DOT a1=*(DOT*)a,b1=*(DOT*)b;
    if(a1.len!=b1.len)return a1.len>b1.len?1:-1;
    else return strcmp(a1.s,b1.s);
}

int main()
{
    int n,m;scanf("%d",&n);
    DOT* a=NULL;
    a=(DOT*)malloc(sizeof(DOT)*n);
    for(int i=0;i<n;i++){
        scanf("%s",a[i].s);
        a[i].len=strlen(a[i].s);
    }
    qsort(a,n,sizeof(DOT),cmp);
    char A[150],B[150],c[150],d[150];
    strcpy(A,a[n-1].s);strcpy(B,a[0].s);
    int len1=strlen(A),len2=strlen(B);
    for(int i=0;i<len1;i++)c[len1-i-1]=A[i];
    strcpy(A,c);
    for(int i=0;i<len2;i++)d[len2-i-1]=B[i];
    strcpy(B,d);
    for(int i=0;i<len2;i++){
        m=i;
        A[i]=A[i]-B[i]+48;
        while(A[m]<48){
            A[m]+=10;
            A[m+1]--;
            m++;
        }
    }
    for(int i=0;i<len1;i++)c[i]=A[len1-i-1];
    strcpy(A,c);
    int startp=len1-1;
    for(int i=0;i<len1;i++){
        if(A[i]!='0'){
            startp=i;
            break;
        }
    }
    for(int i=startp;i<len1;i++)printf("%c",A[i]);
    printf("\n");
    return 0;
}
