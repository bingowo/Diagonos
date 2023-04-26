#include<stdio.h>


void f(int *m, int *n);
int main()
{
    int n,s;
    int h;
    int max=0;
    int i,j;
    int m=0,n=0;
    int a[1000][1000]={0};
    int space[1000]={0};
    scanf("%d %d",&n,&s);
    for (i=0;i<n;i++){//构建山谷,地形信息保存至a数组中
        scanf("%d",&h);
        if (h > max){
            max=h;
        }
        j=0;
        while(h > 0){
            a[i][j]=1;
            j++;
        }
    }
    for (i=0;i<max;i++){//将每一层的空白格保存至space数组中
        for (j=0;j<n;j++){
            if (!a[i][j]){
                space[i]++;
            }
        }
    }
    i=0;
    while (s>0){
        if (s > space[i]){
            s-=space[i];
            i++;
            continue;
        }
        else if (s == space[i]){
            i++;
            break;
        }
        else{
            m=s;
            n=space[i];
            f(&m,&n);
        }
    }
    if (m*n > 0){
        printf("%d+%d/%d",i,m,n);
    }
    else{
        printf("%d",i);
    }
    return 0;
}

void f(int *m, int *n)
{
    int r=(*m)%(*n);
    while (r != 0){
        *m=*n;
        *n=r;
        r=(*m)%(*n);
    }
}