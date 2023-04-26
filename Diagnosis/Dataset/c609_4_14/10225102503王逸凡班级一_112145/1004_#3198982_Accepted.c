#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char table[]="0123456789ABCDEF";

int main()
{
    int A,B;
    char n[50000];
    int m[50000];
    scanf("%d %s %d",&A,n,&B);
    int i=0;
    int l=strlen(n);
    long long count=0;
    for(i=0;i<l;i++){
        if(n[i]>='A'&& n[i]<='F'){
            m[i]=n[i]-'A'+10;
        }else if(n[i]>='a'&& n[i]<='f'){
            m[i]=n[i]-'a'+10;
        }else{
            m[i]=n[i]-'0';
        }
        count=(count+m[i])*A;
    }
    count=count/A;
    char k[50000];
    int j=0;
    do{
        k[j]=table[count%B];
        count=count/B;
        j++;
    }while(count!=0);

    int c;
    for(c=j-1;c>=0;c--){
        printf("%c",k[c]);

    }

    return 0;
}
