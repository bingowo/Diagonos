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
    if(sum1==0&&b==1)printf("%lld ",sum1);

    int k=i;
    long long int allhave;
    long long int sum2=0;
    int d=1;
    int m=1;

    if(i<b-1){
    if(a[i+1]=='.')return 0;


    for(int j=0;j<(b-i-1);j++){
        d=d*3;
    }
    for(i=i+1;i<b;i++){
        if(a[i]=='0')c=0;
        if(a[i]=='1')c=1;
        if(a[i]=='2')c=-1;
        sum2=sum2*3+c;
        //printf("%d\n",sum2);
    }
    if(sum2<0&&sum1==0){
        m=-1;
    }
    if(sum2<0&&sum1>0){
        sum1=sum1-1;
        sum2=d+sum2;
    }
    //printf("%d\n",sum2);
    allhave=trans(d,sum2);
    //printf("%d\n",allhave);
    //printf("%lld %lld\n",sum2/allhave,d/allhave);
    }

    if(sum1!=0){
        printf("%lld ",sum1);
    }
    if(k<b-1){
    if(a[k+1]=='.')return 0;
    printf("%lld %lld\n",m*sum2/allhave,m*d/allhave);
    }
    return 0;

}

