#include<stdio.h>
#include<string.h>

//char delete(char *a[])
void delete(char a[]) 
{
    int i,j,k,n;
    k=strlen(a);
    for(i=0;i<k;i++) 
    {
        for(j=i+1;j<k;)
        {
            if(a[i]==a[j])
            {
                for(n=j;n<k;n++)
                {
                    a[n]=a[n+1];
                }
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    //return a;

}

int main()
{
    int T,i,k,s;
    long long sum;
    char b[70]={'\0'},a[70]={'\0'};
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        sum=0;
        scanf("%s",b);
        //a[70]=b[70];
        strcpy(a,b);
        delete(a);
        int l1=strlen(a);
        int l2=strlen(b);
        if(l1<=1)l1=2;//add
        for(k=0;k<l2;k++)
        {
            for(s=0;s<l1;)
            {
                int q;//add
    if(s==0)q=1;//add
    else if(s==1)q=0;//add
    else q=s;//add
    if(b[k]==a[s])
                {
                    //sum += sum*l1+(s+1);
                    sum=sum*l1+(q);
                    break;
                }
                s++;
            }
        }
        printf("case #%d:\n%lld\n",i,sum);
    }
    return 0;
}