#include<stdio.h>
#include<math.h>
int main()
{
    int sum,i,j,p,num,count,m;
    char input[60];
    scanf("%d",&sum);
    char c;
    c=getchar();
    for(i=0;i<sum;i++)
    {
        j=0,num=2;
        count=0,m;
        char str[60];
        while((c=getchar())!='\n')
        {
            input[j]=c;
            j++;
        }
        j--;
        str[1]=input[0];
        for(p=1;p<=j;p++)
        {
            for(m=0;m<p;m++)
            {
                if(input[m]==input[p]) break;
            }
            if(m==p)
            {
                count++;
                str[num]=input[p];
                num++;
            }

        }
        if(count==1) count=2;
        long long int res=0;
        for(p=0;p<=j;p++)
        {
            for(m=1;m<num;m++)
            {
                if(input[p]==str[m]) break;
             }
             res+=pow(count,j-p-1)*m;
        }
        printf("%d",res);

    }
}
