#include <stdio.h>
#include <string.h>
int Add1(char A[],int k)
{
    int i=k;
    while (i>=0)
    {
        A[i]+=1;
        if (A[i]<='9') return i;
        A[i]=0;
        i--;
    }
    return i;
}
int main()
{
    int i,j,T;
    scanf("%d",&T);
    for (int q=0;q<T;q++){
    char A[101]={'0'};
    scanf("%s",A+1);
    int len=strlen(A);
    Add1(A,len-1);
    for (i=1;i<len;i++)
    {
        if (A[i]==A[i-1]) break;
    }
    if (i!=len)
    {
        i=Add1(A,i);
        while(i>0)
        {
            if (A[i]!=A[i-1]) break;
            i=Add1(A,i);
        }
        for (j=i+1;j<len;j++)
        {
            A[j]=(j-i+1)%2+'0';
        }
    }
    printf("case #%d:\n",q);
    if (A[0]!='0') printf("%s\n",A);
    else printf("%s\n",A+1);
    }
    return 0;
}
