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
        printf("%d/%d\n",sums,Sums);
        char b=getchar();
    }

    return 0;
}




