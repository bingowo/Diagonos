#include <stdio.h>
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int k=0;k<cnt;k++)
    {
        int num=0;
        scanf("%d",&num);
        int res=0;
        if(num<5) res=0;
        else{
            for(int i=5;i<=num;i=i+5){
                int temp=0;
                while(i%5==0){temp++;i=i/5;}
                res+=temp;
            }
        }
        printf("case #%d:\n",k);
        printf("%d\n",res);
    }
    return 0;
}