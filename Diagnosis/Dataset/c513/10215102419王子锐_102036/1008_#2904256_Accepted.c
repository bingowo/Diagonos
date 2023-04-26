#include<stdio.h>
#include<stdlib.h>

int compare(int a,int b){
    int add=a^b;
    int count=0;
    while(add!=0){
        if(add%2==1)count++;
        add/=2;
    }
    printf("%d\n",count);
}
    

int main()
{
    int T,num1,num2,add;
    scanf("%d",&T);
    for(int cas=0; cas<T; cas++){
        scanf("%d %d",&num1,&num2);
        compare(num1,num2);
    }
    return 0;
    
}