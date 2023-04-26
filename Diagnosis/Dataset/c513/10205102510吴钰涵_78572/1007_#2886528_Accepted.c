#include <stdio.h>

int arr[40]={-1};

int trans(int n) {
    int i;
    for(i=0;n/2!=0;i++) {
        arr[i]=n%2;
        n=n/2;
    }
    arr[i]=n;
    return i;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int I=0;I<T;I++) {
        int num;
        scanf("%d",&num);
        int i=trans(num);
        int curmax=1,lastmax=1;
        for(;i>0;i--) {
            if(arr[i]!=arr[i-1]) {
                curmax++;
                if(i==1) {  //读到最后一位时的处理
                    if(lastmax<curmax)
                        lastmax=curmax;
                }
            }
            else {
                if(lastmax<curmax)
                    lastmax=curmax;
                curmax=1;
            }
        }
        printf("case #%d:\n",I);
        printf("%d\n",lastmax);
        for(int i=0;i<40;i++)
            arr[i]=-1;
    }
    return 0;
}

