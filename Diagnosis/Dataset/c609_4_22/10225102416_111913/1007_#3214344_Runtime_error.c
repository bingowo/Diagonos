#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int cmp(const void *a, const void *b);
int binary_num(int a);
int main()
{
    int T, N[10];
    int **a;//二维数组a
    int i,m;
    scanf("%d",&T);  //T表示问题个数,也表示行数
    a = (int**)malloc(sizeof(int*) * T); // 分配行
    for (i = 0; i < T; i++)
		a[i] = (int*)malloc(sizeof(int) * 10000); // 分配列,直接假设列为10000
    for(i = 0;i<T;i++){
        scanf("%d",&N[i]); //N表示待排序数的个数
    }
    for(i = 0;i<T;i++){
        for(m = 0;m<N[i];m++){
            scanf("%d",&a[i][m]);
        }
        qsort(a[i][0],N,sizeof(a[0][0]),cmp);
    }
    for(i = 0;i<T;i++){
        printf("case #%d:\n",i);
        for(m = 0;m<N;m++){
            printf("%d ",a[i][m]);//手动添加数字后的空格
        }
        printf('\n');
    }
    for (i = 0; i < T; i++) // 先释放分配的列
		free(a[i]);
	free(a);				  // 再释放分配的行
    return 0;
}
int binary_num(int a){  //debug后，该函数已解决问题，可正常运行
    int b[64]={0},num=0; //b[]储存二进制,num计算1的个数
    int i=0,j=0;
    if(a>0){
        while(a){
            b[i]=a%2;
            a = a/2;
            i++;
            if(i>=64) break;
        }
    }else if(a==0){
        for(i=0;i<64;i++){//0的时候，补码全为0
            b[i] = 0;
        }
    }else if(a<0){ //负数求补码，先求出绝对值的原码，随后从右往左数，遇到第一个1停下，1后面的所有数求反
        a = -a;
        i = 63;
        while(a){
            b[i]=a%2;
            a = a/2;
            i--;
            if(i>=64) break;
        }
        for(i=63;i>=0;i--){
            if(b[i]==1){
                for(j=0;j<i;j++)    //从右往左数，第一个1左边的数取反
                    if(b[j]==1)
                        b[j]=0;
                    else
                        b[j]=1;
                break;
            }
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
        return num_b-num_a; //按补码中1的数目降序
    }
    else
        return *(int *)a-*(int *)b; //1的数目相同，按本身的值升序
}
