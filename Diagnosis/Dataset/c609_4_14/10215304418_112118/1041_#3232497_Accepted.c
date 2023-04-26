#include<stdio.h>
#include<math.h>
#include<stdlib.h>

char st[1234];
char c[1234];
char ans[65540][34];
char dpst[1234];
int num=0;
int k=0;

int dp(int deep){
    if (deep==k){
        strcpy(ans[num],dpst);
        num++;
        return 0;
    }
    else{
        int len=strlen(dpst);
        dpst[len]=c[deep];
        dp(deep+1);
        dpst[len]='\0';
        dp(deep+1);
    }
}

int cmp(const void* x1,const void* st2){
    char *xx=(char**)x1;
    char *yy=(char**)st2;
    return strcmp(xx,yy);
}

int cmp1(const void* c1,const void* c2){
    return *(char*)c1-*(char*)c2;
}

int main(){
    int t;
    scanf("%d",&t);
    for (int l=0;l<t;l++){
        scanf("%s",st);
        k=0;
        num=0;
        for (int i=0;i<strlen(st);i++){
            int f=0;
            for (int j=0;j<i;j++)
                if (st[i]==st[j]){
                    f=1;
                    break;
                }
            if (f==0){
                c[k]=st[i];
                k++;
            }
        }
        qsort(c,k,sizeof(char),cmp1);
        dpst[0]='\0';
        dp(0);
        num--;
        qsort(ans,num,sizeof(ans[0]),cmp);
        printf("case #%d:\n",l);
        for (int i=0;i<num;i++){
            printf("%s\n",ans[i]);
        }
    }
    return 0;
}
