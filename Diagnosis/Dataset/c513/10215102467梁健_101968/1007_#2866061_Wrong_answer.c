#include<stdio.h>
#include<string.h>

int main()
{
    int T=0,num=0,i=0;
    char a[32];
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&num);
        while(num>0){
            a[i++]=num%2;
            num/=2;
        }
        int length=strlen(a),res=1,RES=1;
        for(int step=0;step<length-1;step++){
            if(a[step]!=a[step+1])res+=1;
            else {
                if(res>RES)RES=res;
                res=1;
                continue;
            }
        }
        
    }
    return 0;
}