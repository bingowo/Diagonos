#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 61


int convert(char S[])//将数组S中存放的字符串转换为对应的数码，存放在数组D中，再转换位对应的十进制数
{
    int D[N],R,i,j,n=1,num=0;//数组D存放字符串对应的数码,变量R存放字符串中字符的种类即进制
    D[0]=1;R=1;//数组S中存放的第一个字符串对应的数码是1
    for(i=1;i<strlen(S);i++)//将数组S中存放的字符串转换为对应的数码，存放在数组D中
    {
        for(j=0;j<i;j++)//如果S[i]中的字符已经在前面出现过，它已经有对应的数码，将它对应的数码赋给数组D[i]
            if(S[i]==S[j])
            {
                D[i]=D[j];
                break;
            }
        if(j==i)//如果S[i]中的字符没有在前面出现过，计算它对应的数码，赋给数组D[i]
        {
            R++;//出现了不同的字符，为字符种类加1
            if(R==2) D[i]=0;//如果字符是第二个不同的字符，它对应的数码应该为0
            else D[i]=R-1;//如果字符不是第二个不同的字符，它对应的数码应该为R-1
        }
    }
    //将R进制的数转换为十进制数
    num=D[i-1];
    for(i=strlen(S)-2;i>=0;i--)
    {
        n=n*R;
        num=num+D[i]*n;
    }
    return num;
}



int main()
{
    int T,*num,i;//指针变量num指向T个int型数据的存储空间，存放T个字符串对应的T个最小的整数
    char S[N];//数组S存放输入的字符串
    scanf("%d",&T);
    num=(int*)malloc(T*sizeof(int));
    for(i=0;i<T;i++)
    {
        scanf("%s",S);
        num[i]=convert(S);
    }
    for(i=0;i<T;i++)
        printf("case #%d:\n%d\n",i,num[i]);

}