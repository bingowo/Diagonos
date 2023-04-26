#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>


typedef long long int lli;
int input (int* a)
{
    int i;
    char s[101];
    scanf("%s",s);
    int len = strlen(s);
    for(i=1;i<=len;i++)
    {
        a[i]=s[i-1]-'0';
    }
    a[len+1]=-1;

//    printf("%d",len+1);
    return len;
}

int handle(int *a,int *b,int i)
{

    if (*a==*b)
    {
        if(*a==9)
        {
//            if(i==1)
//            {
//                a[0]+=1;
//                return 1;
//            }
            if(*(a-2)==*(a-1)+1)
            {
                *(a-1)+=1;
                return handle((a-2),(a-1),i-2);
            }
            else
            {
                *(a-1)+=1;
                return i;
            }

        }
        else
        {
            (*b)+=1;
            return i+2;
        }
    }
    else return -1;
}

void tozeroone(int *a,int i )
{
    int flag=0;
    for(int j=i;a[j]!=-1;j++)
    {

        a[j]=flag==0?flag++:flag--;
    }
}

void output(int *a)
{
    int i;
    while (a[i]==0) i++;
    for (int j=i;a[j]!=-1;j++)
        printf("%d",a[j]);
    printf("\n");
}

void ADD(int*a ,int t,int len)
{
    int carry =t;
    while (carry!=0)
    {
        a[len--]+=carry;
        carry=a[len+1]/10;
        a[len+1]%=10;
    }
}

int main(void)
{
    int t;
    int a[102];

    scanf("%d",&t);


    for (int j=0;j<t;j++)
    {
        memset(a,0,sizeof(a));
        lli l=input(a);//记录整数的长度
        ADD(a,1,l);
//        output(a);
        for (int i=1;i<l;i++)
        {
            int p=handle(&a[i],&a[i+1],i);
            if(p==-1)
            {
               continue;
            }
            else
            {
                tozeroone (a,p);
                break;
            }

        }
        printf("case #%d:\n",j);
//        printf("%d\n",a[5]);
        output(a);
    }

    return 0;

}
