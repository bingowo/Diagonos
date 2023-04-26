#include <stdio.h>
#include <string.h>
int Add1(char A[],int k)//实现第k位=1,同时返回最高位
{
    int i=k;
    while(i>=0)
    {
        A[i]+=1;
        if(A[i]<='9')
            return i;
        A[i] = '0';
        i--;
    }
    return i;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int z=0;z<t;z++)
    {
        char A[101]={'0'};
        scanf("%s",A+1);  //保留A[0]存放进位
        printf("case #%d:\n",z);
        int len=strlen(A);
        int i,j;
        Add1(A,len-1);
        for(i=1;i<len;i++)
        {
            if(A[i]==A[i-1])
                break;
        }
        if(i != len)
        {
            i=Add1(A,i);
            while(i>0)
            {
                if(A[i] != A[i-1])
                    break;
                i=Add1(A,i);
            }
            for(j=i+1;j<len;j++)
                A[j] = (j-i+1)%2+'0'; //填充0101…
        }
        if(A[0]!='0')  printf("%c",A[0]);
        printf("%s\n",A+1);
    }
    return 0;
}
