#include<stdio.h>
#include<math.h>

void trans(int N, int R);

int main()
{
    int T;
    int N,R;
    int i;
    scanf("%d",&T);
    for (i=0;i<T;i++){
        scanf("%d%d",&N,&R);
        trans(N,R);
    }
    return 0;
}

void trans(int N,int R)//N是十进制数，R是需要转换的进制
{
    int n=0;
    int i;
    while(pow(R,n)<=N)
        n++;
    int *a= (int)malloc(sizeof(int)*n);//数组保存转换后的数
    n=0;
    while(N>0){//进制转换并保存
        a[n]=N%R;
        N=N/R;
        n++;
    }
    n--;
    for (i=n;i>=0;i--){
        if (a[i]<=10)
            printf("%d",a[i]);
        else    
            printf("%c",'A'+a[i]-10);
    }
    printf('\n');
    return;
}