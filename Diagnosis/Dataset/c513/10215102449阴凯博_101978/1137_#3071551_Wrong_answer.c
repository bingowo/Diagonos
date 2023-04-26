#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
    char s1[120]={0};  char s2[120]={0};
    scanf("%s %s",s1,s2);
    int A[120]={0};  int B[120]={0};  int C[120]={0};
    int signA=0,signB=0,signC=0,m=0,n=0;
    if (s1[0]=='-') signA=1;
    if (s2[0]=='-') signB=1;
    for (int i=strlen(s1)-1;i>=0;i--)
    {
        if (isdigit(s1[i]))
            A[m++]=s1[i]-'0';
    }
    for (int i=strlen(s2)-1;i>=0;i--)
    {
        if (isdigit(s2[i]))
            B[n++]=s2[i]-'0';
    }
    if (signA==signB)
    {
        signC=signA;
        m=m>n?m:n;
        int carry=0;
        for (int i=0;i<m;i++)
        {
            C[i]=A[i]+B[i]+carry;
            if (C[i]>9)
            {
                C[i]-=10;
                carry=1;
            }
            else
                carry=0;
        }
        if (carry)
        {
            C[m]+=carry;
            m++;
        }
        if (signC) printf("-");
        for (int i=m-1;i>=0;i--)
            printf("%d",C[i]);

    }
    else
    {
        if (m>n)
        {
            int carry=0;
            for (int i=0;i<m;i++)
            {
                C[i]=A[i]-B[i]-carry;
                if (C[i]<0)
                {
                    carry=1;
                    C[i]+=10;
                }
                else
                    carry=0;
            }
            signC=signA;
        }
        if (m==n)
        {
            int flag=0,j=0;
            for (j=m-1;j>=0;j--)
            {
                if (A[j]>B[j])
                {
                    flag=1;
                    break;
                }
                if (A[j]<B[j])
                    break;
            }
            if (j==m)
                printf("0\n");
            else
            {
                if (flag==1) //A-B
                {
                    int carry=0;
                    for (int i=0;i<m;i++)
                    {
                        C[i]=A[i]-B[i]-carry;
                        if (C[i]<0)
                        {
                            carry=1;
                            C[i]+=10;
                        }
                        else
                            carry=0;
                    }
                     signC=signA;

                }
                else
                {
                    int carry=0;
                    for (int i=0;i<m;i++)
                    {
                        C[i]=B[i]-A[i]-carry;
                         if (C[i]<0)
                        {
                            carry=1;
                            C[i]+=10;
                        }
                        else
                            carry=0;
                    }
                    signC=signB;

                }
            }
        }
        if (m<n)
        {
            int carry=0;
            for (int i=0;i<n;i++)
            {
                C[i]=B[i]-A[i]-carry;
                if (C[i]<0)
                {
                    carry=1;
                    C[i]+=10;
                }
                else
                    carry=0;
            }
            signC=signB;
        }
        if (signC) printf("-");
        int k=0;
        for (k=m>n?m:n;k>=0 && C[k]==0;k--);
        for (k;k>=0;k--)
            printf("%d",C[k]);
    }


    return 0;
}
