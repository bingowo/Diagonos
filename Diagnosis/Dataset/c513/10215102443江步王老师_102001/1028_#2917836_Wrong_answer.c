#include<stdio.h>
#include<stdlib.h>

int cmp(const void *_a, const void *_b);
int f(int *n, int num);

char ch;

int main()
{
    int n[101];
    int i=0;
    int j=0;
    int cnt=0;
    scanf("%c",&ch);
    while (scanf("%d",n+i) != EOF){
        i++;
    }
    cnt=f(n,i);
    qsort(n,i-cnt,sizeof(int),cmp);
    for (j=0;j<i-cnt;j++){
        printf("%d ",n[j]);
    }
    return 0;
}


int f(int *n,int num)//去重函数,返回去掉的个数
{
    int i=0;
    int cnt=0;//计数
    int p[1001]={0};
    while (i<num){
        if (!p[n[i]]){
            p[n[i]]=1;
            i++;
        }
        else{
            n[i]=n[num-1];
            num--;
            cnt++;
        }
    }
    return cnt;
}

int cmp(const void *_a, const void *_b)
{
    int *a = (int *)_a;
    int *b = (int *)_b;
    return (*a-*b);
}