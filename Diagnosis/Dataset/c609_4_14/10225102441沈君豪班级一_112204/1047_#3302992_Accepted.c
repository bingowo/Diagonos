#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int a,n;
        scanf("%d %d",&a,&n);
        int s[1001];
        memset(s,0,1001*sizeof(int));
        s[0]=a;
        if(n==0){
            printf("case #%d:\n1\n",i);
        }else{
            for(int j=0;j<n-1;j++){
                int jw=0;      //进位
                for(int k=0;k<1001;k++){
                    s[k]=s[k]*a+jw;
                    if(s[k]>=10){
                        jw=s[k]/10;
                        s[k]=s[k]%10;
                    }else{
                        jw=0;
                    }
                }
            }
            printf("case #%d:\n",i);
            int b=0;          //辅助结束前置零
            for(int j=1000;j>=0;j--){
                if(s[j]!=0){
                    b=1;
                }
                if(b==1)
                    printf("%d",s[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
