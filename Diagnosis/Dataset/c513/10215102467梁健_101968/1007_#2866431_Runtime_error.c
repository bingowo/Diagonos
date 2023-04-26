#include<stdio.h>
#include<string.h>

int main()
{
    int T=0,i=0,step=0,length=0,res=1,RES=1,m=0;
    long long num=0;
    char aT[10];
    char a[300];
    scanf("%d",&T);
    for(m=0;m<T;m++){
        scanf("%d",aT[m]);
    }
    for(i=0;i<T;i++){
        while(aT[m]>0){
            a[step++]=aT[m]%2;
            aT[m]/=2;
            length++;
        }
        a[step]='\0';
        for(step=0;step<length-1;step++){
            for(int m=step;m<length-1;m++){
                if(a[m]!=a[m+1])res+=1;
                if(res>RES)RES=res;
                else {
                    res=1;
                    continue;
                }
            }
            res=1;
        }
        printf("case #%d:\n",i);
        printf("%d\n",RES);
        RES=1,step=0,length=0;
        m=0;
    }
    return 0;
}
