#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t>0){
        int a,b;
        scanf("%d %d",&a,&b);
        int flag=0;
        if(a<0){
            a=-a;
            flag=1;
        }
        if(b<10){
            int res=0;
            int n=1;
            while(a!=0){
                res=res+(a%b)*n;
                n=n*10;
                a=a/b;

            }
            if(flag){
                printf("-");
            }
            printf("%d\n",res);

        }
        else{
            int i=0;
            char s[100];
            char str[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
            while(a){
                int k=a%b;
                s[i]=str[k];
                a=a/b;
                i++;
            }
            if(flag){
                printf("-");
            }
            for(int j=i-1;j>=0;j--){
                printf('%s',s[j]);

            }
            printf('\n');

        }

        t-=1;
    }

    return 0;
}
