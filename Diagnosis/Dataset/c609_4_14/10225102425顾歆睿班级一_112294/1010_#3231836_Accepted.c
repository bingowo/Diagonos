#include <stdio.h>
char ans[100];
int num[100];
void trans(int j)
{
    int i;
    for(i=0;i<j;i++){
        if(num[i]>=0&&num[i]<=9)
            ans[i]=num[i]+'0';
        else
            ans[i]=num[i]-10+'A';
    }
}

int main()
{
    int n,r;
    scanf("%d%d",&n,&r);
    int i=0;
    if(n==0)printf("0");
    else{
        while(n){
            if(n%r<0){
                num[i]=n%r-r;
                n=n/r+1;
            }
            else{
                num[i]=n%r;
                n /=r;
            }
        i++;
    	}
	}
    trans(i);
    for(int j=i-1;j>=0;--j)
        printf("%c",ans[j]);
    return 0;
}
