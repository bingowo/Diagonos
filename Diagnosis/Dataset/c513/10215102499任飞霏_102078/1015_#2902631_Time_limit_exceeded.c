#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,
                47,53,59,61,67,71,73,79,83,89,97};

int input(int p[])
{
    int i = 0;
    char c;
    do
        scanf("%d%c",&p[i++],&c);
    while(c==',');
    return i;
}

void add(int a[],int b[],int n)
{
    int i,k=0;
    for(i=24;i > n;i--){
        a[i]+=b[i];
        a[i-1]+=a[i]/prime[k++];
    }

}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        int a[25]={0};
        int b[25]={0};
        int x=input(a);
        int y=input(b);
        int k=0;
        int m = (x>y)?x:y;
        int n = (x<y)?x:y;
        for(int j = 0;;j++){
            if(n>=0){
                a[x-j]+=b[y-j];
                a[x-j-1]+=a[x-j]/prime[k++];
            }
            else
                break;
        }
        for(int t = 0;t < m;t++){
            printf("%d",a[t]);
        }

    }
    return 0;
}
