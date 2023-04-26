#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int cmp(const void *a, const void *b);
int binary_num(int a);
int main()
{
    int T, N;
    int a[10][1000],i,m;
    scanf("%d",&T);  //T表示问题个数
    for(i = 0;i<T;i++){
        scanf("%d",&N); //N表示待排序数的个数
        for(m = 0;m<N;m++){
            scanf("%d",a[i][m]);
            qsort(a[i][0],N,sizeof(a[0][0]),cmp);
        }
    }
    for(i = 0;i<T;i++){
        printf("case #%d:\n",i);
        for(m = 0;m<N;m++){
            printf("%d ",a[i][m]);//手动添加数字后的空格
        }
        printf('\n');
    }
    return 0;
}
int binary_num(int a){
    int b[64],num=0; //b[]储存二进制,num计算1的个数
    int i=0,j;
    long long dec;
    if(a>0){
        while(a){
            b[i]=a%2;
            a = a/2;
            i++;
            if(i>=64) break;
        }
    }else if(a=0){
        for(i=0;i<64;i++){//0的时候，补码全为0
            b[i] = 0;
        }
    }else if(a<0){
        i = 0;
        a = -a;
        dec = (long long)pow(2,64)-a; //求补码的方法，负数n的补码==mod-|n|的原码,mod==2^(二进制位数)
        while(dec){
            b[i]=dec%2;
            dec = dec/2;
            i++;
            if(i>=64) break;
        }
    }
    for(j=0;j<64;j++){
        if(b[j]==1) num++;
    }
    return num;
}
int cmp(const void *a, const void *b){
    int num_a,num_b;
    num_a = binary_num(*(int *)a);
    num_b = binary_num(*(int *)b);
    if(num_a!=num_b){
        return num_b-num_a;
    }
    else
        return *(int *)a-*(int *)b;
}
