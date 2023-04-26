#include<stdio.h>
int main()
{
    int T=0;
    scanf("%d",&T);
    for(int Tnow=0;Tnow<T;Tnow++)   
    {
        printf("case #%d:\n",Tnow);

        int N;
        scanf("%d",&N);

        long long int array[10000];
        int bin[64];
        int a_count_1[10000];
        for(int i=0;i<N;i++)    a_count_1[i]=0;

        for(int Nnow=0;Nnow<N;Nnow++)
        {
            scanf("%lld",&array[Nnow]); 
            long long int temp=array[Nnow];
            if(temp==0) a_count_1[Nnow]=0;
            else if(temp>0)  
            {
                for(int i=0;temp!=0;i++)
                {
                    if(temp%2==1) a_count_1[Nnow]++;                
                    temp=temp/2;
                }
            }
            else
            {                
                for(int i=0;i<64;i++)    bin[i]=1;
                temp=-temp;
                for(int i=0;temp!=0;i++)
                {
                    bin[i]=temp%2;
                    if(bin[i]==0) bin[i]=1;
                    else bin[i]=0;
                    temp=temp/2;                
                }
                int i=0;
                if(bin[i]==0)   
                {
                    a_count_1[Nnow]++;
                    i++;
                }
                else
                {
                    for(i;bin[i]==1;i++);
                    a_count_1[Nnow]++;
                    i++;
                }
                for(i;i<64;i++) 
                    if(bin[i]==1)   
                        a_count_1[Nnow]++;
            }
            //printf("%d ",a_count_1[Nnow]);
        }
        
        int flag=0;
        while(flag==0)
        {
            flag=1;
            for(int i=0;i<N-1;i++)
                if(a_count_1[i]<a_count_1[i+1])   
                {
                    int temp;
                    temp=array[i];
                    array[i]=array[i+1];
                    array[i+1]=temp;

                    temp=a_count_1[i];
                    a_count_1[i]=a_count_1[i+1];
                    a_count_1[i+1]=temp;

                    flag=0;
                }           
        }
        
        flag=0;
        while(flag==0)
        {
            flag=1;
            for(int i=0;i<N-1;i++)
                if(a_count_1[i]==a_count_1[i+1])   
                    if(array[i]>array[i+1])
                    {
                        int temp;
                        temp=array[i];
                        array[i]=array[i+1];
                        array[i+1]=temp;

                        temp=a_count_1[i];
                        a_count_1[i]=a_count_1[i+1];
                        a_count_1[i+1]=temp;

                        flag=0;    
                    }
        }
        for(int i=0;i<N-1;i++) printf("%lld ",array[i]);
        printf("%lld\n",array[N-1]);
    }
    return 0;
}