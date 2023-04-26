#include <stdio.h>
#include <stdlib.h>

int f(int a,int b)
{
    if(a%b==0)return b;
    else return f(b,a%b);
}

int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    while(t--){
        char c;
        int cnt=0;
        int j=0;
        while((c=getchar())!='\n'&&c!=EOF){
            int m=(int)c;
        for(int i=0;i<8;i++){
            if((1&(m>>i))==1)cnt++;
        }
        j++;
        }
        int temp=f(8*j,cnt);
        int ans=8*j/temp;
        printf("%d/%d\n",cnt/temp,ans);
    }
    return 0;
}
