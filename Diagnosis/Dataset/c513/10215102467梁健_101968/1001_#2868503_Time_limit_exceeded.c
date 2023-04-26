#include<stdio.h>
#include<string.h>
int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int num,R,m=0;
        scanf("%d %d",&num,&R);
        char N[100];
        if (num<0)printf("-"),num=-num;
        if (num==0)printf("0\n");
        while(num>0){
            if(0<=num%R&&num%R<=9)N[m++]=num%R+48;
            else N[m++]=num%R+55;
        }
        N[m]=0;
        for(int p=m;p>0;p--){
            printf("%c",N[p-1]);
        }
        printf("\n");
    }
    return 0;
}
