/*  神秘信息  */

#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++) {
        char s[65];
        scanf("%s",&s);
        int len=strlen(s);
        char arr[128];
        for(int i=0;i<128;i++)
            arr[i]=-1;
        int N=1;  //用于记录进制
        for(int i=0;i<len;i++) {
            int num=(int)s[i];
            if(arr[num]==-1) {
                if(i==0)
                    arr[num]=1;
                else if(i!=0 && N==1) {
                    N++;
                    arr[num]=0;
                }
                else {
                    N++;
                    arr[num]=N-1;
                }
            }
        }
        if(N==1)
            N=2;
        long long int plus=0;
        for(int i=0;i<len;i++) {
            int num=(int)s[i];
            plus=plus*N;
            plus+=arr[num];
        }
        printf("case #%d:\n",t);
        printf("%lld\n",plus);
    }
    return 0;
}