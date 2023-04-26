#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int ordercheck(char *s);
    int poss(char c);
    char order[50];
    int num[30]={0};
    memset(order,'\0',50);
    char dic[12][5]={"IN","OUT","MOV","XCHG","ADD","SUB","MUL","DIV","MOD","AND","OR","XOR"};


    while(gets(order))
    {
        char check[5];
        memset(check,'\0',5);
        int i=0,j=0;
        while(order[i]!=' ')
        {
            check[j]=order[i];
            i++;
            j++;
        }
        int flag=ordercheck(check);//{"IN","OUT","MOV","XCHG","ADD","SUB","MUL","DIV","MOD","AND","OR","XOR"};
        i++;
        char temp[3];
        memset(temp,'\0',3);
        for(int t=0;t<2;t++)
        {
            temp[t]=order[i];
            i++;
        }

        i++;//使得i走到XX的后面一位（跳过逗号）
        //printf("%s",temp);
        //printf("%d",flag);
        int place=i;
        int lenth=0,extra=0;
        while(order[i]!='\0'&&i<strlen(order))
        {
            i++;
            lenth++;
        }
        //printf("o%do",lenth);
        if(lenth>4) extra=1;
        i=place;
        if(flag==0)//说明是做的输入操作
        {
            int a[30]={0};//搞一个保存整数的数组 考虑负数 同时把数组转化成数
            int x=0;
            int t=0;
            while(i<strlen(order))
            {
                a[t]=order[i]-'0';
                i++;
                t++;
            }//还要考虑负数
            //printf("o%do\n",a[0]);

            if(a[0]==('-'-'0'))
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
            int pos;
            for(int k=0;k<26;k++)//判断是哪一个变量
            {
                if(temp[0]-'A'==k) {pos=k;break;}
            }
            num[pos]=x;
           // printf("%d\n",num[0]);
        }
        else
        {//注意先要讨论是否是extra
            if(extra==0)
            {
                 if(flag==1)
            {
                int pos;
                for(int k=0;k<26;k++)//判断是哪一个变量
                {
                    if(temp[0]-'A'==k) {pos=k;break;}
                }
                printf("%d",num[pos]);
            }
            else if(flag==2)
            {
                char c=order[i];
                int pos=poss(c);
                num[poss(temp[0])]=num[pos];
            }
            else if(flag==3)
            {
                char c=order[i];
                int pos=poss(c);
                int tempp;
                tempp=num[poss(temp[0])];
                num[poss(temp[0])]=num[pos];
                num[pos]=tempp;
            }
            else if(flag==4)
            {
               char c=order[i];
                int pos=poss(c);
                num[poss(temp[0])]+=num[pos];
            }
            else if(flag==5)
            {
                char c=order[i];
                int pos=poss(c);
                num[poss(temp[0])]-=num[pos];
            }
            else if(flag==6)
            {
                char c=order[i];
                int pos=poss(c);
                num[poss(temp[0])]*=num[pos];
            }
            else if(flag==7)
            {
                char c=order[i];
                int pos=poss(c);
                num[poss(temp[0])]/=num[pos];
            }
            else if(flag==8)
            {
                char c=order[i];
                int pos=poss(c);
                num[poss(temp[0])]%=num[pos];
            }
            else if(flag==9)
            {
                char c=order[i];
                int pos=poss(c);
                num[poss(temp[0])]=num[poss(temp[0])]&num[pos];
            }
            else if(flag==10)
            {
                char c=order[i];
                int pos=poss(c);
                num[poss(temp[0])]=num[poss(temp[0])]|num[pos];
            }
            else if(flag==11)
            {
                char c=order[i];
                int pos=poss(c);
                num[poss(temp[0])]=num[poss(temp[0])]^num[pos];
            }
            }
            else if(extra==1)
            {

                if(flag==4)
                {
                    char c=order[i];
                    char cc=order[i+3];
                    int posb=poss(c);
                    int posc=poss(cc);
                    num[poss(temp[0])]=num[posb]+num[posc];
                }
                else if(flag==5)
                {
                    char c=order[i];
                    char cc=order[i+3];
                    int posb=poss(c);
                    int posc=poss(cc);
                    num[poss(temp[0])]=num[posb]-num[posc];
                }
                else if(flag==6)
                {
                    char c=order[i];
                    char cc=order[i+3];
                    int posb=poss(c);
                    int posc=poss(cc);
                    num[poss(temp[0])]=num[posb]*num[posc];
                }
                else if(flag==7)
                {
                    char c=order[i];
                    char cc=order[i+3];
                    int posb=poss(c);
                    int posc=poss(cc);
                    num[poss(temp[0])]=num[posb]/num[posc];
                }
                else if(flag==8)
                {
                    char c=order[i];
                    char cc=order[i+3];
                    int posb=poss(c);
                    int posc=poss(cc);
                    num[poss(temp[0])]=num[posb]%num[posc];
                }
                else if(flag==9)
                {
                    char c=order[i];
                    char cc=order[i+3];
                    int posb=poss(c);
                    int posc=poss(cc);
                    num[poss(temp[0])]=num[posb]&num[posc];
                }
                else if(flag==10)
                {
                    char c=order[i];
                    char cc=order[i+3];
                    int posb=poss(c);
                    int posc=poss(cc);
                    num[poss(temp[0])]=num[posb]|num[posc];
                }
                else if(flag==11)
                {
                    char c=order[i];
                    char cc=order[i+3];
                    int posb=poss(c);
                    int posc=poss(cc);
                    num[poss(temp[0])]=num[posb]^num[posc];
                }
            }
        }







    }


    return 0;
}

int ordercheck(char *s)
{
    int flag;
    char dic[12][5]={"IN","OUT","MOV","XCHG","ADD","SUB","MUL","DIV","MOD","AND","OR","XOR"};
    for(int i=0;i<12;i++)
    {
        if(strcmp(dic[i],s)==0)
        {
            flag=i;
            break;
        }
    }
    return flag;
}


int poss(char c)
{
    int ans;
    for(int i=0;i<26;i++)
    {
        if(c-'A'==i) {ans=i;break;}
    }
    return ans;
}
