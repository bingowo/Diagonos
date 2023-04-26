#include<stdio.h>

void d2b(int *a, int n);
int find_max(int *a, int n);
int main()
{
    int i,j;
    int T,n,num,l,r,m;
    /*
    T ——问题数,n ——当前输入的整数,num ——重复二进制串组数,m ——长度最大值
    */
    int prev=-1;
    int a[32];
    int left[16];
    int right[16];
    int length[16];
    for (i=0;i<32;i++){
        a[i]=0;
    }
    scanf("%d",&T);
    for (i=0;i<T;i++){
        scanf("%d",&n);
        //创建数组，把n的32位二进制表示存入数组中;
        d2b(a,n);
        //a中按顺序存放n的32位二进制表示
        j=0;
        num=0;
        while (j<31){//查找重复二进制串,并将其左端和右端下标分别存放入left,right数组中
            if (a[j]==a[j+1]){
                prev=a[j];
                left[num]=j;
                while (a[j+1]==prev){
                    j++;
                }
                right[num]=j;
                num++;
            }
            j++;
        }
        for (j=0;j<num;j++){
            printf("left[%d]=%d\n",j,left[j]);
            printf("right[%d]=%d\n",j,right[j]);
        }
        num--;
        j=0;
        l=0;
        r=left[0];
        while (j!=num){//计算各组不重复二进制串的长度并将其存放入length数组中
            length[j]=r-l;
            j++;
            l=right[j-1];
            r=left[j];
        }
        length[j]=32-right[j];
        m=find_max(length,j);
        printf("case #%d:\n",i);
        printf("%d\n",m);
    }
    return 0;
}

void d2b(int *a, int n)
{
    int i=31;
    while (n>0){
        *(a+i)=n%2;
        n=n/2;
        i--;
    }
    return;
}

int find_max(int *a, int n)//n为a数组中最大下标
{
    int m=a[0];
    int i=1;
    while (i<=n){
        if (m<*(a+i))
            m=*(a+i);
        i++;
    }
    return m;
}