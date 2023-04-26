#include<stdio.h>
#include<math.h>

int main(){
    int x,y,k;
    scanf("%d %d",&x,&y);
    int sum=abs(x)+abs(y);
    if(sum%2==0)k=-1;
    else{
        sum++;
        k=(int)log(sum)/log(2);
        int m=pow(2,k-1);
        if(sum<=m)k=-1;
    }
    printf("%d\n",k);
}