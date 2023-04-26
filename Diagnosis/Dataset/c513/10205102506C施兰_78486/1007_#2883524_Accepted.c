#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    int N;
    scanf("%d",&N);
    for(int n=0;n<N;n++){
        int x;
        scanf("%d",&x);
        int longest=0,pre=-1,temp=0;
        while(x){

            if((x&1)!=pre){
                temp++;
                longest=fmax(longest,temp);
            }
            else{temp=1;}
            pre=(x&1);
            x=x>>1;
        }
        printf("case #%d:\n%d\n",n,longest);
    }
    return 0;
}
