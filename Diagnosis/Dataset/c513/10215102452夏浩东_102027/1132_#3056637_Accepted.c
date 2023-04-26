#include <stdio.h>
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int mm=0;mm<cnt;mm++){
        long long int num=0;
        int count=0,res=0;
        scanf("%lld %d",&num,&count);
        while(num!=0){
            res+=num%count;
            num=num/count;
        }
        int L[100],k=0;
        while(res!=0){
            L[k++]=res%count;
            res=res/count;
        }
        printf("case #%d:\n",mm);
        for(int i=k-1;i>=0;i--){
            if(L[i]>9) printf("%c",(char)(L[i]-10+'A'));
            else printf("%d",L[i]);
        }
        printf("\n");
    }
    return 0;
}