
#include<stdio.h>
#include<string.h>

int main()
{
    int T=1,length=0,res=1,Result=0;
    scanf("%d",&T);
    int a[100];
    for(int step=0;step<T;step++){
        printf("case #%d:\n",step);
        scanf("%s",a);
        length=strlen(a);
        for(int time=1;time<length;time++)res=res*3;
        for(int i=0;i<length;i++){
            if(a[i]==49)Result=Result+res;
            else if(a[i]==45)Result=Result-res;
            res=res/3;
        }
        printf("%d\n",Result);
        Result=0,res=1,length=0;
    }
    return 0;
}
