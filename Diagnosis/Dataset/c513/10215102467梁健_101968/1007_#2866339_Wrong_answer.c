#include<stdio.h>
#include<string.h>

int main()
{
    int T=0,num=0,i=0,step=0,length=0,res=1,RES=1;
    char a[300];
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&num);
        while(num>0){
            a[step++]=num%2;
            num=num/2;
            length++;
        }
        a[step]='\0';
        for(step=0;step<length-1;step++){
            if(a[step]!=a[step+1])res+=1;
            if(res>RES)RES=res;
            else {
                res=1;
                continue;
            }
        }
        res=1;
        printf("case #%d:\n",i);
        printf("%d\n",RES);
        RES=1,step=0,length=0;
    }
    return 0;
}
