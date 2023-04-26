#include <stdio.h>


int main()
{
    int T,a,b,i,k=0;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d %d",&a,&b);
        if(a<0){
         printf("-");
         a=-a;
        }
        char s[100];
        int j=0,c;
        while(a/b!=0){
            c=a%b;
            if(b<10){
                s[j]=c+48;
            }
            if(b>=10){
                if(c<=9){
                    s[j]=c+48;
                }
                else{
                    s[j]=c-10+65;
                }

            }

            a=a/b;
            j++;

        }
        if(b<10){
            s[j]=a%b+48;
        }
        if(b>=10){
            if(a%b<=9){
                s[j]=a%b+48;
            }
            else{
                s[j]=a%b-10+65;
            }
        }



        for(;j>=0;j=j-1){
            if(j==0)
                printf("%c\n",s[j]);
            else
                printf("%c",s[j]);
        }

    }



    return 0;
}
