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
        int i=0,z=0,t=0;//t来标记是否为负
        if(n<0) {
            x[0]='-';
            i++;
            n=-n;
            t=1;
        }
        while(n){
            z=n%m;
            n=n/m;
            x[i]=y[z];
            i++;
        }
        i--;
        if(t){
            for(int j=1;j<i;j++,i--){
            p=x[j];
            x[j]=x[i];
            x[i]=p;
        }
        }
        else{
            for(int j=0;j<i;j++,i--){
            p=x[j];
            x[j]=x[i];
            x[i]=p;
        }
    }
    }
    scanf("%d",&a);
    for(int i =0;i<a;i++){
        for(int j=0;j<100;j++){
            s[j]=0;
        }
        scanf("%d %d",&b,&c);
        jinzhi(b,c,s);
        printf("%s\n",s);
    }
    return 0;
}