#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    int R;
    scanf("%d%d",&N,&R);
    if(R>=-10){
            int k=0,a[30];
            int tmp;
    do
    {
        tmp=N%R;
        if(tmp<0)tmp=tmp-R;
        N=(N-tmp)/R;
        a[k++]=tmp;
    }
    while(N);
    for(int i=k-1;i>=0;i--)
        printf("%d",a[i]);

    }
    else
    {
        int k=0;
        char a[30];
        int tmp;
        do
        {
            tmp=N%R;
            if(tmp<0) tmp=tmp-R;
            N=(N-tmp)/R;
            if(tmp>=10) a[k++]=tmp-10+'A';
            else a[k++]=tmp+'0';
        }
        while(N);
        for(int i=k-1;i>=0;i--)
            printf("%c",a[i]);
    }
    return 0;
}
