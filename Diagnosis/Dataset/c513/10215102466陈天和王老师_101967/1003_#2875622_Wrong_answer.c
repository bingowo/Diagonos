#include <stdio.h>
#include <stdlib.h>

struct data
{
    long long int a;    //a太大了，设为ll整数了
    int number;  //64位二进制补码表示中1的位数
};//这个结构体用的很好

int cmp(const void *a,const void *b);

int main(){
    struct data p[10000];//出现了结构体数组，意思是有许多这样的结构体
    int T,N,o,i;
    scanf("%d",&T);
    for(o=0;o<T;o++) {
        
        scanf("%d", &N);
        for (i = 0; i < N; i++) {
            scanf("%lld", &p[i].a);
            int d = 1;//d其实是一个000000000000000000..1
            p[i].number = 0;
            for (int t = 0; t < 64; t++)//64次，第64次时这个1刚好到最前面
            {
                if ((p[i].a & d) != 0) p[i].number++;//分别检测每一位是否为1
                d = d << 1;//左移就是无脑左移，右边肯定补0
            }
        }

        qsort(p, N, sizeof(p[0]), cmp);
        
        printf("case #%d:\n",o);
        for(i=0;i<N-1;i++) {
            printf("%lld ", p[i].a);
        }
        printf("%lld\n", p[i].a);
    }

}

int cmp(const void *a,const void *b)
{
    struct data d1,d2;

    d1=*((struct data *)a);
    d2=*((struct data *)b);//由于是void指针，要先转换成结构体指针，（其实p就是结构体数组，所以a，b这两个指针指向结构体）指完之后用*取出来

    if(d2.number!=d1.number)
        return d2.number-d1.number;//右大于左的话，return的就大于0，就<执行> 换
    else
    {    if(d1.a>d2.a) return 1;
        else return -1;
    }
}//如果cmp返回值小于0（< 0），那么p1所指向元素会被排在p2所指向元素的左面；
//如果cmp返回值等于0（= 0），那么p1所指向元素与p2所指向元素的顺序不确定；
//如果cmp返回值大于0（> 0），那么p1所指向元素会被排在p2所指向元素的右面
