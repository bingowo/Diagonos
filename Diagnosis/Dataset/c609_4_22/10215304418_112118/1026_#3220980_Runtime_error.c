#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int f[1234];
char **st;
int n;

int cmp(const void* st1,const void* st2){
    char *stx=*(char**)st1;
    char *sty=*(char**)st2;
    for (int i=1;i<=30;i++)
        f[i]=0;
    int num1=0;
    for (int i=0;i<strlen(stx);i++){
        if (f[stx[i]-'A'+1]==0){
            num1++;
            f[stx[i]-'A'+1]=1;
        }
    }
    printf("%d\n",num1);
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
    else return num1-num2;
}

int main(){
    int t;
    scanf("%d",&t);
    for (int l=1;l<=t;l++){
        scanf("%d",&n);
        char *str=(char *) malloc(sizeof(char)*(1000));
        for (int i=0;i<n;i++){
            scanf("%s",str);
            st[i]=(char*)malloc((strlen(str)+1)*sizeof(char));
            strcpy(st[i],str);
        }
        qsort(st,n,sizeof(char *),cmp);
        printf("case #%d:\n",l-1);
        for (int i=1;i<=n;i++){
            printf("%s\n",st[i]);
        }
    }
    return 0;
}
