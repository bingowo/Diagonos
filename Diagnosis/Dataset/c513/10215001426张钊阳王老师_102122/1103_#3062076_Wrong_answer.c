#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()//因为全程是二元运算那么可以把 AB储存在一个二元数组中 并根据命令不断迭代计算
{
    int ordercheck(char *s);
    int transf(char c);
    char order[30];
    memset(order,'\0',30);
    int num[10]={0};
    char dic[7][4]={"IN","MOV","ADD","SUB","MUL","DIV","OUT"};

    while(gets(order))
    {
        char check[4];
        int i=0,j=0;
        char x[3],y[3];
        while(order[i]!=' ')
        {
            check[j]=order[i];
            i++;
            j++;
        }//先看是什么操作
        //printf("%d",i);
        //printf("%s\n",check);
        int flag=ordercheck(check);
        char temp[3];
        memset(temp,'\0',3);
        i++;
        for(int k=0;k<2;k++)
        {
            temp[k]=order[i];
            i++;
        }
        i++;
        //printf("%d",i);
        //if(order[7]=='\0') printf("1");
        //printf("%s\n",temp);
        //Ax Bx Cx Dx 分别存在1 2 3 4
        if(flag==0)
        {
            int a[30]={0};
            int x=0;
            int t=0;
            while(order[i]!='\0')
            {
                a[t]=order[i]-'0';
                i++;
                t++;
            }//还要考虑负数
            if(a[0]=='-'-'0')
            {
                for(int k=1;k<t;k++)
                {
                    x=x*10+a[k];
                }
                x=-x;
            }
            else
            {
                for(int k=0;k<t;k++)
                {
                    x=x*10+a[k];
                }
            }

            switch(temp[0]){
            case 'A':
                num[0]=x;break;
            case 'B':
                num[1]=x;break;
            case 'C':
                num[2]=x;break;
            case 'D':
                num[3]=x;break;
            }

            printf("%d\n",num[0]);
        }//第一种情况,就是输入的情况
        else{
            char c,cc;
            c=temp[0];
            cc=order[i];
            int a,b;
            a=transf(c);
            b=transf(cc);
            if(flag==1)
            {
                num[a]=num[b];
            }
            else if(flag==2)
            {
                num[a]+=num[b];
            }
            else if(flag==3)
            {
                num[a]-=num[b];
            }
            else if(flag==4)
            {
                num[a]*=num[b];
            }
            else if(flag==5)
            {
                num[a]/=num[b];
            }
            else if(flag==6)
            {
                printf("%d\n",num[a]);
            }
            printf("%d\n",num[0]);
        }


    }

    return 0;
}

int ordercheck(char *s)//规定不同返回值代表不同的操作 0是输入 1是移动 2是相加 3是相减 4是乘法 5是除法 6是输出
                                     //可以知道过程中皆为二元运算 所以可以直接进行 不需要考虑括号等等
{
    char dic[7][4]={"IN","MOV","ADD","SUB","MUL","DIV","OUT"};
    int flag;
    for(int i=0;i<7;i++)
    {
        if(strcmp(s,dic[i])==0) {flag=i;break;}
    }
    return flag;
}

int transf(char c)
{
    int flag;
    switch(c){
            case 'A':
                flag=0;break;
            case 'B':
                flag=1;break;
            case 'C':
                flag=2;break;
            case 'D':
                flag=3;break;
    }
    return flag;
}



