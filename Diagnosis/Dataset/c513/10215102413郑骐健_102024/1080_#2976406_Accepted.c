#include <stdio.h>
#include <stdlib.h>
#define num 400


int div2(int* big,int*n)
{
    int res[num]={0};
    int len = *n;
    int z = big[0]%2;
    big[0]-=z;
    int carry = 0;
    for(int i = len-1;i>=0;i-- )
    {
        int p = big[i]+10*carry;
        carry = p%2;
        big[i] = p/2;
    }
    if(big[len-1]==0&&len!=1)*n-=1;
    return z;
}
void mul2(int*p1,int add ,int*len)
{
       int res[num]={0};
    int carry=0;
    for(int a =0 ;a<=*len;a++)
    {
        int p=p1[a]*2+carry;
        res[a]=p%10;
        carry = p/10;
    }
     res[0]+=add;
    int n =1;

    if(res[0]>=10)
    {
        int carry1 = res[0]/10;
        while(carry1>0)
        {
            int p = res[n]+carry1;
            res[n]=p%10;
            carry1=p/10;
            n++;
        }
    }
    if(res[*len+1]>0)*len+=2;
    else if(res[*len]>0)*len+=1;
    for(int i =0;i<*len;i++)p1[i]=res[i];


}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        int big[num] ={0};
        int res2[num] = {0};
        int res[num]={0};
        int big2[num]={0};
        char s[200];
        int cnt =0;
        scanf("%s",s);
        int len = strlen(s);
        for(int i = strlen(s)-1;i>=0;i--)
        {
            big[len-i-1] = s[i]-'0';
        }

        while(len!=1||big[0]!=0)
        {
         res2[cnt++] = div2(big,&len);
        }

        for(int p=cnt-1;p>=0;p--)
        {
            res[p] = res2[cnt-1-p];
        }
        while(res[cnt-1]==0)cnt--;

        int length =1;
        for(int q=cnt-1;q>=0;q--)
        {
            mul2(big2,res[q],&length);
        }
        for(int k=length-1;k>=0;k--)
        {
            printf("%d",big2[k]);
        }
        if(i!=t-1)printf("\n");

//       printf("\n");
//        for(int i =0;i<len;i++)
//        {
//            printf("%d",big[i]);
//        }
    }
    return 0;
}
