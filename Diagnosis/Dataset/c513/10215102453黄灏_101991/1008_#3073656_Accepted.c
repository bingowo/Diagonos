#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>

int reverse(int x,int y){
    int a=x,b=y;
    int an[100]={0},bn[100]={0};
    int len_a=0,len_b=0;
    while(a!=0){
        an[len_a]=a%2;
        a/=2;
        len_a++;
    }
    while(b!=0){
        bn[len_b]=b%2;
        b/=2;
        len_b++;
    }
    int dif=0;
    for(int j=0;j<100;j++){
        if(an[j]!=bn[j]) dif++;
    }
    return dif;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        //printf("case #%d:\n",i);
        int x,y;
        scanf("%d%d",&x,&y);
        int dif=0;
        dif=reverse(x,y);
        printf("%d\n",dif);
    }
    return 0;
}
