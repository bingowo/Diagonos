#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    for(int i=0;i<T;i++){
        int a,n;
        scanf("%d %d",&a,&n);
        int s[1001];
        memset(s,0,1001);
        s[0]=a;
        int x=1;      //索引长度
        for(int j=0;j<n;j++){
            int jw=0;      //进位
            int k=0;
            while(!(s[k]==0&&jw==0)){
                s[k]=s[k]*a+jw;
                if(s[k]>=10){
                    jw=s[k]/10;
                    s[k]=s[k]%10;
                }
                k++;
            }
            x=k;
        }
        printf("case #%d:\n",i);
        for(int j=x-1;i>=0;j--){
            printf("%d",s[j]);
        }
        printf("\n");

    }
    return 0;
}
