#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,R;
    scanf("%d",&T);

    for(R=0;R<T;R++){
        char in[62];
        int value[128];
        int digit=-1;
        long long int ans=0;

        printf("case #%d:\n",R);

        //for(int i=0;i<60;i++) in[i]=0;
        for(int i=0;i<128;i++) value[i]=-1;
        scanf("%s",in);

        char *p=in;

        for(value[*p]=1;*++p; ){
            if(value[*p]==-1){
                if(digit==0){
                    digit=2;
                    value[*p]=2;
                }
                else {
                    digit++;
                    value[*p]=digit;
                }
            }
        }

        if(digit==-1 || digit==0) digit=1;

        p=in;
        while(*p){
            ans=ans*(digit+1)+value[*p];
            p++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
