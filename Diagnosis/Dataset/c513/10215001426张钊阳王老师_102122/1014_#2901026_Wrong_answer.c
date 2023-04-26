#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    void trans(int *a,int l);
    int m,n,j;
    scanf("%d %d",&m,&n);
    int temp=m/n,g=0;
    int t=temp,n1=n;
    int count=0,numbers;

        while(t!=0){count++; t=t/3;}

        while(n1!=1){g++;n1/=3;}

    int k=m%n;
    if(temp!=0)
    {
        numbers=count+g;
        int* tre=(int*)malloc(sizeof(int)*numbers);
        j=numbers-1;
        int i=count-1;
        while(k!=0)
        {
            tre[j--]=k%3;
            k/=3;
        }
        while(temp!=0)
        {
            tre[i--]=temp%3;
            temp/=3;
        }
        trans(tre,numbers);
        for(int s=0;s<numbers;s++) tre[s]-=1;
        for(int s=0;s<numbers;s++)
        {
            if(tre[s]==-1) printf("2");
            else {printf("%d",tre[s]);}
            if(s==count-1) printf(".");
        }
    }

    else
    {
        numbers=count+g+1;
        int* tre=(int*)malloc(sizeof(int)*numbers);
        j=numbers-1;
        while(k!=0)
        {
            tre[j--]=k%3;
            k/=3;
        }
        tre[0]=0;
        trans(tre,numbers);
        for(int s=0;s<numbers;s++) tre[s]--;
        for(int s=0;s<numbers;s++)
        {
            if(tre[s]==-1) printf("2");
            else {printf("%d",tre[s]);}
            if(s==0) printf(".");
        }
    }
    return 0;
}
void trans(int *a,int l)
{
        int i=l-1;
        for(int s=0;s<l;s++)
            *(a+s)+=1;
        for(;i>=0;i--)
        {
            if(*(a+i)==3) {*(a+i)=0; *(a+i-1)+=1;continue;}
            if(*(a+i)==4) {*(a+i)=1;*(a+i-1)+=1;}
        }
}
