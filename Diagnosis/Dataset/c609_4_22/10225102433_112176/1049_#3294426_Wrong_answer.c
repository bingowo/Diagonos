#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max(x,y) x >= y ? x : y

char a[10010];
char b[10010];
int A[10010];
int B[10010];
int ans[10010];
int len1,len2;

void Bigsub(int *x,int *y)
{
    int len = max(len1,len2);
    for(int i = 0,t = 0;i < len;i++)
    {
        t = x[i]-t;
        t -= y[i];
        ans[i] = (t+10)%10;
        if(t < 0) t = 1;
        else t = 0;
    }
    for(;len > 0;len--) if(ans[len] != 0) break;
    for(int i = len;i >= 0;i--) printf("%d",ans[i]);
    printf("\n");
}

int cmp(char *m,char *n)
{
    if(strlen(m) != strlen(n)){
        if(strlen(m) > strlen(n)) return 1;
        else return 0;
    }
    else
    {
        int len = strlen(m);
        for(int i = 0;i < len;i++){
            if(m[i] != n[i]){
                if(m[i] < n[i]) return 0;
                else return 1;
            }
        }
    }
    return 1;
}

int main()
{
    while((scanf("%s %s",a,b)) != EOF)
    {
        len1 = strlen(a);
        len2 = strlen(b);
        for(int i = len1-1,j = 0;i >= 0;i--,j++) A[j] = a[i]-'0';
        for(int i = len2-1,j = 0;i >= 0;i--,j++) B[j] = b[i]-'0';
        if(cmp(a,b))
        {
            Bigsub(A,B);
        }
        else
        {
            printf("-");
            Bigsub(B,A);
        }
        memset(a,'\0',sizeof(a));
        memset(b,'\0',sizeof(b));
        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));
        len1 = 0;
        len2 = 0;
    }
    return 0;
}