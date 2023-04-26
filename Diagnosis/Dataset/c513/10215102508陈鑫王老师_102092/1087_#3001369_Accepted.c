#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int ADD1(char s[],int k)
{
    int i=k;
    while(i>=0)
    {
        s[i]+=1;
        if(s[i]<='9') return i;
        s[i]='0';
        i--;
    }
    return i;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int k=0;k<t;k++)
    {
        char A[103]={'0'};
        scanf("%s",A+1);
        int len=strlen(A);
        int i,j;
        ADD1(A,len-1);
        for(i=1;i<len;i++)
        {
        if(A[i]==A[i-1])break;
        }
        if(i!=len)
        {
            i=ADD1(A,i);
            while(i>0)
            {
                if(A[i]!=A[i-1])break;
                i=ADD1(A,i);
            }
            for(j=i+1;j<len;j++)
            {
                A[j]=(j-i+1)%2+'0';//填充0101010......
            }

        }
        printf("case #%d:\n",k);
        if(A[0]!='0')printf("%c",A[0]);
        printf("%s\n",A+1);
    }
    return 0;
}