#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trans(int x,int y){
    if(x%y==0)return y;
    else return trans(y,x%y);
}

int main(){
    char a[31];
    gets(a);
    int b=strlen(a);

    int i=0;
    long long int sum1=0;
    int c;
    for(i=0;a[i]!='.',i<b;i++){
        if(a[i]=='0')c=0;
        if(a[i]=='1')c=1;
        if(a[i]=='2')c=-1;
        if(a[i]=='.')break;
        sum1=sum1*3+c;

        //printf("%d",sum1);
    }
    //printf("%d\n",i);
    printf("%lld\n",sum1);
    if(i<b-1){
    if(a[i+1]=='.')return 0;
    long long int sum2=3;
    int d=(b-i-1)*3;
    for(i=i+1;i<b;i++){
        if(a[i]=='0')c=0;
        if(a[i]=='1')c=1;
        if(a[i]=='2')c=-1;
        sum2=sum2*3+c;
    }
    long long int allhave=trans(d,sum2);
    //printf("%d\n",allhave);
    printf("%lld\nll%d\n",sum2/allhave,d/allhave);}
    return 0;

}
