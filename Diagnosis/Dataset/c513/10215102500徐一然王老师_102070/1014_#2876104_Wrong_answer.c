#include<stdio.h>

int main()
{   int zi,zi1,mu,mu1,jingzhi=1;
    int count=0,count1,count2,count3,i=0,j=0,k=0;
    int xiaoshu,zhengshu,zhengshu1=0;
    int A[100];
    int B[100];
    int C[100];
    int D=0;
    scanf("%d",&zi);
    scanf("%d",&mu);
    if(zi<mu)
    {   mu1=mu;
        while(mu-1)
        {mu=mu/3;count++;}
        count1=count-1;
        count2=count;
        count3=count;
        B[0]=0;
        zi1=zi;
            while(zi)
            {
                while(count1)
                {
                    jingzhi=jingzhi*3;
                    count1--;
                }
                xiaoshu=zi/jingzhi;
                zi=zi-xiaoshu*jingzhi;
                A[i]=xiaoshu;
                i++;
                jingzhi=jingzhi/3;

            }
    }
    else if(zi>mu)
    {
        zhengshu=zi/mu;
        zhengshu1=zhengshu;
        zi=zi%mu;
        while(zhengshu)
        {
            B[j]=zhengshu%3;
            zhengshu=zhengshu/3;
            j++;
        }
        mu1=mu;
        while(mu-1)
        {mu=mu/3;count++;}
        count2=count;
        count3=count;
        count1=count-1;
        zi1=zi;
        while(zi)
            {
                while(count1)
                {
                    jingzhi=jingzhi*3;
                    count1--;
                }
                xiaoshu=zi/jingzhi;
                zi=zi-xiaoshu*jingzhi;
                A[i]=xiaoshu;
                i++;
                jingzhi=jingzhi/3;

            }
        j=j-1;
        while(j+1)
        {
            C[k]=B[j];
            k++;
            j--;
        }

    }

    int *p=A;
    int jingwei=0,dajingwei=0,k1;
    p=p+count2-1;
    while(count2)
    {
        *p=*p+1+jingwei;
        if(*p>2)
        {
            *p=*p-3;
            jingwei=1;
        }
        *p=*p-1;
        if(*p==-1)
        {
            *p=2;
        }
        p--;

        if(count2==1&&jingwei==1)
        {
            dajingwei=1;
        }
        count2--;
    }

    int *p1=C;
    int first=1;
    p1=p1+k-1;
    k1=k;
    while(k)
    {
        if(first==1)
        {*p1=*p1+1+dajingwei;first--;}
        else
        {*p1=*p1+1+jingwei;}
        if(*p1>2)
        {
            *p1=*p1-3;
            jingwei=1;
        }
        *p1=*p1-1;
        if(*p1==-1)
        {
            *p1=2;
        }
        p1--;
        if(k==1&&jingwei==1)
        {
            D=1;
        }
        k--;

    }
    p1=C;
    p=A;
    if(D!=0)
    {
        printf("%d",D);
    }
    while(k1--)
    {
        printf("%d",*p1);
        p1++;
    }
    if(zhengshu1==0)
    {
        printf("1");
    }
    if(zi1!=0)
    {
        printf(".");
        while(count3--)
    {
        printf("%d",*p);
        p++;
    }


    }


}