#include <stdio.h>
#include <stdlib.h>


int ones(int a)
{
    int count=0;
    while(a!=0){
        int tmp=a&1;
        if(tmp==1) count++;
        a=a>>1;
    }
    return count;
}


int sum(char x)
{
    int xx=x;
    return ones(xx);

}

void put(int x,int y)
{
    int max=1;
    for(int i=2;i<=y;i++){
        while(x%i==0 && y%i==0){max=i;break;}
    }
    x=x/max;
    y=y/max;
    printf("%d/%d",y,x);

}


int main()
{
    int T=1;
    scanf("%d",&T);
    char a=getchar();
    for(int i=0;i<T;i++){
        char c;
        int sums=0;
        int Sums=0;
        while((c=getchar())!='\n' && EOF){
            sums+=sum(c);
            Sums+=8;
        }
        put(Sums,sums);
    }

    return 0;
}




