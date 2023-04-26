#include<stdio.h>
int count(int T)
{
    int t[31],a,i=0;
    while(T!=0){
        a=T%2;
        T/=2;
        t[i]=a;
        i++;
    }
    int num=0;
    for(int j=0;j<i;j++){
        if(t[j]!=t[j+1]) num++;
    }
    return ;
}

int main()
{
    int T,i=0;
    int N[10];
    while(scanf("%d\n",&T)!=EOF){
        N[i]=count(T);
        i++;
    }
    for (int j=0;j<i;j++){
        printf("case #%d",j);
        printf("%d\n",N[j]);
    }
    return 0;
}