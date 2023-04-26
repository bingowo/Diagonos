#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int f[1234];
char st[123][123];
int n;

int cmp(const void *st1,const void *st2){
    char *stx;
    stx=(char**)st1;
    char *sty;
    sty=(char**)st2;
    for (int i=1;i<=30;i++)
        f[i]=0;
    int num1=0;
    for (int i=0;i<strlen(stx);i++){
        if (f[stx[i]-'A'+1]==0){
            num1++;
            f[stx[i]-'A'+1]=1;
        }
    }
    for (int i=1;i<=30;i++)
        f[i]=0;
    int num2=0;
    for (int i=0;i<strlen(sty);i++){
        if (f[sty[i]-'A'+1]==0){
            num2++;
            f[sty[i]-'A'+1]=1;
        }
    }
    if (num1==num2){
        return strcmp(stx,sty);
    }
    else return num2-num1;
}

int main(){
    int t;
    scanf("%d",&t);
    for (int l=1;l<=t;l++){
        scanf("%d",&n);
        int maxn=0;
        for (int i=0;i<n;i++){
            scanf("%s",st[i]);
            if (strlen(st[maxn])<strlen(st[i])) maxn=i;
        }
        qsort(st,n,sizeof(st[maxn]),cmp);
        printf("case #%d:\n",l-1);
        for (int i=0;i<n;i++){
            printf("%s\n",st[i]);
        }
    }
    return 0;
}
