#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d;
    char s[100]={0};
    void jinzhi(int n,int m,char x[])
    {
        char y[36]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        char p;
        int i=0,z=0;
        if(n<0) {
            x[0]='-';
            i++;
            n=-n;
        }
        while(n){
            z=n%m;
            n=n/m;
            x[i]=y[z];
            i++;
        }
        i--;
        for(int j=0;j<i;j++,i--){
            p=x[j];
            x[j]=x[i];
            x[i]=p;
        }
    }
    scanf("%d",&a);
    for(int i =0;i<a;i++){
        scanf("%d %d",&b,&c);
        jinzhi(b,c,s);
        printf("%s",s);
    }
    return 0;
}