#include <stdio.h>
#include <stdlib.h>
char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
    int a,b;
    char s[1000];
    scanf("%d %d",&a,&b);
    int c,i=0;
    if(a==0){
        printf("0");
    }
    else{
        while(a!=0){
            c=a%b;
            if(c>=0){
                a=a/b;
                s[i]=table[c];

            }
            else{
                s[i]=table[c-b];
                a=a/b+1;

            }
            i++;
        }
        for(int j=i-1;j>=0;j=j-1){
            printf("%c",s[j]);
        }
    }



    return 0;
}
