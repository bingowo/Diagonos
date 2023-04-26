#include<stdio.h>
#include<string.h>

int main()
{
    int T=1,length=1,res,Result=0;
    scanf("%d",&T);
    int a[100];
    for(int step=0;step<T;step++){
        scanf("%s",a);
        printf("case #%d:\n",step);
        length=strlen(a);
        for(int time=1;time<length;time++){
            res*=3;
        }
        for(int i=0;i<length;i++){
            if(a[i]=='1')Result+=res;
            else if(a[i]=='-')Result-=res;
            res/=3;
        }
        printf("%d",Result);
        Result=0,res=1,length=0;
    }
    return 0;
}