#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t>0){
        long a,b;
        scanf("%ld%ld",&a,&b);
        int flag=0;
        if(a<0){
            a=-a;
            flag=1;
        }
        if(b<10){
            long  res=0;
            int n=1;
            while(a!=0){
                res=res+(a%b)*n;
                n=n*10;
                a=a/b;

            }
            if(flag){
                printf("-");
            }
            printf("%ld\n",res);

        }
        else{
            int i=0;
            char s[1000000];
            
            while(a){
                int k=a%b;
                if(k>=10){
                    s[i]=k+55;
                }
                else{
                    s[i]=k+48;
                }
                
                a=a/b;
                i++;
            }
            if(flag){
                printf("-");
            }
            for(int j=i-1;j>=0;j--){
                printf("%c",s[j]);

            }
            printf("\n");

        }

        t=t-1;
    }

    return 0;
}