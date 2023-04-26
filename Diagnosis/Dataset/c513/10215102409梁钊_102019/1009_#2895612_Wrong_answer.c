#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i!=n;i++){
        char s[121]={'0'};
        int slen=0;
        while((s[slen++]=getchar()) !='\n') ;
        int sum=0;
        for(int j=0;j!=slen;j++){
            int tmp=s[j];
            while(tmp){
                tmp &= tmp - 1 ;
                sum++;
            }
        }
        printf("%d/%d\n",sum,slen*8);
    }
}
