#include <stdio.h>
#include <string.h>

int main()
{
    char A[505],B[505];
    memset(A,0,sizeof(char));
    memset(B,0,sizeof(char));
    int a1[505],a2[505],b1[505],b2[505],n,i,temp;
    int a1_len,a2_len,b1_len,b2_len;
    scanf("%s %s %d",A,B,&n);
    A[strlen(A)]='\0';
    B[strlen(B)]='\0';
    for(i=0;i<505;i++)
    {
        a1[i]=0;
        a2[i]=0;
        b1[i]=0;
        b2[i]=0;
    }
    for(a1_len=0;a1_len<strlen(A);a1_len++)
    {
        if(A[a1_len]=='.'){break;}
        else{a1[a1_len]=(int)A[a1_len]-(int)'0';}
    }
    if(A[a1_len]=='.')
    {
        for(a2_len=0;a2_len<strlen(A)-a1_len-1;a2_len++)
        {
            a2[a2_len]=(int)A[a1_len+a2_len+1]-(int)'0';
        }
    }
    for(b1_len=0;b1_len<strlen(B);b1_len++)
    {
        if(B[b1_len]=='.'){break;}
        else{b1[b1_len]=(int)B[b1_len]-(int)'0';}
    }
    if(B[b1_len]=='.')
    {
        for(b2_len=0;b2_len<strlen(B)-b1_len-1;b2_len++)
        {
            b2[b2_len]=(int)B[b1_len+b2_len+1]-(int)'0';
        }
    }
    int len_1=(a1_len>b1_len)?a1_len:b1_len;
    int len_2=(a2_len>b2_len)?a2_len:b2_len;
    if(len_1>a1_len)
    {
        for(i=a1_len-1;i>=0;i--)
        {
            a1[i+len_1-a1_len]=a1[i];
        }
        for(i=0;i<len_1-a1_len;i++)
        {
            a1[i]=0;
        }
    }
    if(len_1>b1_len)
    {
        for(i=b1_len-1;i>=0;i--)
        {
            b1[i+len_1-b1_len]=b1[i];
        }
        for(i=0;i<len_1-b1_len;i++)
        {
            b1[i]=0;
        }
    }
    int p[len_1+5],q[n+5];
    for(i=0;i<len_1+5;i++)
    {
        p[i]=0;
    }
    for(i=0;i<len_2+5;i++)
    {
        q[i]=0;
    }
    int ad=0,kad=0;
    for(i=len_2-1;i>=0;i--)
    {
        temp=a2[i]+b2[i]+ad;
        q[i]=temp>=10?temp-10:temp;
        ad=temp>=10?1:0;
    }
    if(n<=len_2)
    {
        len_2=n;
        if(q[n]==9)
        {
            kad=1;
            for(i=len_2-1;i>=0;i--)
            {
                temp=q[i]+kad;
                q[i]=temp>=10?temp-10:temp;
                kad=temp>=10?1:0;
            }
        }
        else if(q[n]>4)
        {
            kad=1;
            for(i=len_2-1;i>=0;i--)
            {
                temp=q[i]+kad;
                q[i]=temp>=10?temp-10:temp;
                kad=temp>=10?1:0;
            }
        }
    }
    if(n>len_2)
    {
        for(i=0;i<n-len_2;i++)
        {
            q[i+len_2]=0;
        }
    }
    len_2=n;
    for(i=len_1-1;i>=0;i--)
    {
        temp=a1[i]+b1[i]+ad;
        p[i]=temp>=10?temp-10:temp;
        ad=temp>=10?1:0;
    }
    p[len_1-1]+=kad;
    if(ad==1){printf("1");}
    if(len_1==0){printf("0");}
    for(i=0;i<len_1;i++)
    {
        printf("%d",p[i]);
    }
    printf(".");
    for(i=0;i<len_2;i++)
    {
        printf("%d",q[i]);
    }
    return 0;
}
