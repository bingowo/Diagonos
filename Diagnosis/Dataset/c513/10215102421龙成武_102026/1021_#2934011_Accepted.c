#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char alpha[27];
int alphadigit(char p);
int compar(const void *p1,const void *p2);
int main()
{
    char *a[101],temp[3000];
    int i,j,len;

    while(scanf("%s",alpha)!=EOF)
    {
        i=0;j=0;
        getchar();              //读回车
        temp[0]=' ';            //这种重要条件既然特意做了，那么就每次循环时应该不变，也就是说，不能放在循环体外面
        gets(temp+1);
        len=strlen(temp);       //长度是会变的，如果对中间的元素赋值为0
        for(i=0;i<len;i++)
        {
            if(temp[i]==' ')
            {
                a[j++]=temp+i+1;
                temp[i]=0;
            }

        }
        qsort(a,j,sizeof(char*),compar);
        for(i=0;i<j;i++)
        {
            printf("%s ",a[i]);             //puts会自动输出换行
        }
        printf("\n");
    }
    return 0;
}
int alphadigit(char p)
{
    int i;
    for(i=0;i<26;i++)
    {
        if(p==alpha[i]||p==alpha[i]+32)
        {
            //num=i;
            break;
        }
    }
    return i;
    //return num;
}
int compar(const void *p1,const void *p2)   //这里仍然是void *，因为qsort这么要求，但是要知道，这个指针是指向待排序的元素的
//因为待排序的元素是指针，所以p1,p2的本质上是一个**指针，在函数体内部会体现出差异
{
    char *a,*b,**A,**B;
    A=(char**)p1;B=(char**)p2;
    a=*A;b=*B;
    int i=0,numa,numb,flag=0;
    while(a[i]!=0&&b[i]!=0)
    {
        if(a[i]==b[i]);
        else
        {
            numa=alphadigit(a[i]);
            numb=alphadigit(b[i]);
            if(numa<numb)
                flag=-1;
            else
                flag=1;
            break;
        }
        i++;
    }
    if(flag==0)
    {
        if(a[i]==0)
            flag=-1;
        else
            flag=1;
    }
    return flag;
}
