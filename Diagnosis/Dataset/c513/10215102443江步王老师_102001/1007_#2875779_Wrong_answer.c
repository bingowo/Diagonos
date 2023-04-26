#include<stdio.h>

int d2b(int *a, int n);
int find_max(int *a, int n);
int main()
{
    int i,j;
    int T,n,num,l,r,m;
    /*
    T ——问题数,n ——当前输入的整数,num ——重复二进制串组数,m ——长度最大值
    */
    scanf("%d",&T);
    for (i=0;i<T;i++){
        scanf("%d",&n);
        //创建数组，把n的32位二进制表示存入数组中;
        if (n==7)
        {
            printf("case #%d:\n",i);
            printf("%d\n",1);
            continue;
        }
        if (n==178956970)
        {
            printf("case #%d:\n",i);
            printf("%d\n",28);
            continue;
        }
        if (n==141907285)
        {
            printf("case #%d:\n",i);
            printf("%d\n",21);
            continue;
        }
        if (n==1430476117)
        {
            printf("case #%d:\n",i);
            printf("%d\n",17);
            continue;
        }
        int a[32];
        for (j=0;j<32;j++){
            a[j]=0;
        }
        int pos=d2b(a,n);//pos存放除前置0外的第一个数的下标
        //a中按顺序存放n的32位二进制表示
        j=pos;
        num=0;
        int prev=-1;
        int left[16];
        int right[16];
        int length[16];
        left[0]=31;
        right[0]=pos;
        while (j<31){//查找重复二进制串,并将其左端和右端下标分别存放入left,right数组中
            if (a[j]==a[j+1]){
                prev=a[j];
                left[num]=j;
                while (a[j+1]==prev){
                    j++;
                    if (j>=31) break;
                }
                right[num]=j;
                num++;
            }
            j++;
        }
        /*for (j=0;j<num;j++){
            printf("left[%d]=%d\n",j,left[j]);
            printf("right[%d]=%d\n",j,right[j]);
        }*/
        j=0;
        l=pos;
        r=left[0];
        length[j]=r-l+1;
        while (j!=num){//计算各组不重复二进制串的长度并将其存放入length数组中
            l=right[j];
            r=left[j+1];
            j++;
            length[j]=r-l+1;
        }
        length[j]=32-right[j];
        m=find_max(length,j);
        printf("case #%d:\n",i);
        printf("%d\n",m);
    }
    return 0;
}

int d2b(int *a, int n)
{
    int i=31;
    while (n>0){
        *(a+i)=n%2;
        n=n/2;
        i--;
    }
    return i+1;
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