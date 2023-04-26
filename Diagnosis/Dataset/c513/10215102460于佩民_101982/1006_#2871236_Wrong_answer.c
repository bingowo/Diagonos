#include <stdio.h>

int main(){
    int standard[100];
    standard['-']=-1;standard['0']=0;standard['1']=1;
    int num,a=0,i,j;
    long long int sum=0;
    char str[20];
    for(i=0;i<20;i++) {str[i] = '%';}
    scanf("%d",&num);
    while(a<num){
        scanf("%s",str);
        for(i=0;str[i]!='%';i++);
        j=i-1;
        for(i=0;i<j-1;i++){
            sum=(sum+standard[str[i]])*3;
        }
        sum=sum+standard[str[i]];
        printf("%s","case #");
        printf("%d:\n",a);
        printf("%lld\n",sum);
        a++;
        sum=0;
    }
    return 0;
}