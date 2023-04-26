#include <stdio.h>
#include <string.h>

int tmp1[10010];
int tmp2[10010];
int ans[10010];
int len1,len2;

void init_set1()
{
    for(int i = 0;i < len1;i++) tmp1[i] = tmp2[i];
}

void init_set2()
{
    for(int i = 0;i < len2;i++) tmp2[i] = ans[i];
}

void Bigplus()
{
    int t = 0;
    for(int i = 0;i < len2;i++){
        t = t+tmp1[i]+tmp2[i];
        ans[i] = t%10;
        t /= 10;
    }
    if(t) ans[len2++]++;
}

int main()
{
    int T;scanf("%d",&T);
    for(int i = 0;i < T;i++){
        printf("case #%d:\n",i);
        int n;scanf("%d",&n);
        if(n <= 2){
            if(n == 0) printf("0\n");
            else printf("1\n");
        }
        else{
            tmp1[len1++] = 1;
            tmp2[len2++] = 1;
            for(int j = 0;j < n-2;j++){
                len1 = len2;
                Bigplus();
                init_set1();
                init_set2();
            }
            for(int j = len2-1;j >= 0;j--) printf("%d",ans[j]);
            printf("\n");
            len1 = 0;
            len2 = 0;
            memset(ans,0,sizeof(ans));
            memset(tmp1,0,sizeof(tmp1));
            memset(tmp2,0,sizeof(tmp2));
        }
    }
    return 0;
}