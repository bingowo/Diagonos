#include<stdio.h>
#include<string.h>
int main()
{
    int t,i=0;
    char arr[10][60];
    char memry[60][2];
    long long rslt[10];
    scanf("%d",&t);
    while(i<t)
    {
        scanf("%s",*(arr+i));
        char *q=*(arr+i);
        //查找相同字符的个数
        int cnt=0;
        int j=0;
        while(*q)
        {
            char *p=*(arr+i);
            do
            {
                if(*p!=*q)continue;
                else
                {
                    if(p==q)
                    {
                        cnt++;
                        memry[j][1]=cnt==1?1:cnt==2?0:cnt-1;
                        break;
                    }
                    else
                    {
                        memry[j][0]=*p;
                        char *p2=*(arr+i);
                        int k=p-p2;
                        memry[j][1]=memry[k][1];
                        break;
                    }
                }
            }while(q>p++);
            q++;j++;
        }
        if(cnt==1)cnt++;
        memry[j][1]=-1;
        j=0;
        long long temp=memry[0][1];
        while(memry[++j][1]>=0)
        {
            temp=temp*cnt+memry[j][1];
        }
        rslt[i]=temp;
        i++;
    }
    for(i=0;i<t;i++)printf("case #%d:\n%lld\n",i,rslt[i]);
    return 0;
}
