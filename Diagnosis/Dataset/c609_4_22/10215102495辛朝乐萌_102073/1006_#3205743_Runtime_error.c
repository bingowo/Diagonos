#include <stdio.h>
#include <string.h>


int caljinzhi(char s[])//计算进制
{
    int b[1000]={0};
    int jinzhi=0;
    for (int i = 0; i < strlen(s); ++i) {
        if (b[s[i]] == 0){
            jinzhi++;
            b[s[i]] = 1;
        }
        else{ continue;}
    }
    return jinzhi;

}



int main() {
    int a[1000];//0123的排序
    a[0]=1,a[1]=0;
    for (int i = 2; i <10000 ; ++i) {
        a[i]=i-1;
    }
    int t;
    int ch=1;
    char s[1000];
    scanf("%d",&t);
    for (int i = 0; i < t; ++i) {
        scanf("%s",s);
        printf("case #%d:\n",i);
        int num=0;
        int jinzhi = caljinzhi(s);
        int len= strlen(s);
        for(int i=len-1;i>=0;i-- ){
            num+=a[i]*t;
            t=t*jinzhi;
        }
        printf("%d",num);
    }

    return 0;
}
