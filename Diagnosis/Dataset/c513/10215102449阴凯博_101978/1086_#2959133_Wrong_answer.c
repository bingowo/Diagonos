#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 550

void reverse (int* a,int n)
{
    int i,j;
    int tmp;
    for (i=0,j=n-1;i<j;i++,j--)
    {
        tmp=a[i];
        a[i]=a[j];
        a[j]=tmp;
    }

}

int main()
{
    char s1[MAX]={0}; char s2[MAX]={0};
    scanf("%s %s",s1,s2);
    int N;
    scanf("%d",&N);
    if (strcmp(s1,s2)>=0)
    {
        int flag=0;
        int i,j,k,h;
        int A1[MAX]={0}; int A2[MAX]={0}; int A3[MAX]={0};
        int F1[MAX]={0}; int F2[MAX]={0}; int F3[MAX]={0};
        for (i=0;s1[i]!='.'&& i<strlen(s1);i++)
            A1[i]=s1[i]-'0';
        for (j=0;s2[j]!='.'&& j<strlen(s2);j++)
            A2[j]=s2[j]-'0';
        reverse(A1,i); reverse(A2,j);
        int m=(i>j)?i:j;
        for (i=i+1,k=0;i<strlen(s1);i++,k++)
            F1[k]=s1[i]-'0';
        for (j=j+1,h=0;j<strlen(s2);j++,h++)
            F2[h]=s2[j]-'0';
        int n=(h>k)?h:k;
        reverse (F1,n); reverse(F2,n);
        for (i=0;i<n;i++)
        {
            if (F1[i]>=F2[i])
            {
                F3[i]=F1[i]-F2[i];
            }
            else
            {
                if (i==n-1) flag=1;
                F1[i+1]--;
                F1[i]+=10;
                F3[i]=F1[i]-F2[i];
            }
        }
        if (flag==1)
            A1[0]--;
        for (i=0;i<m;i++)
        {
            if (A1[i]>=A2[i])
            {
                A3[i]=A1[i]-A2[i];
            }
            else
            {
                A1[i+1]--;
                A1[i]+=10;
                A3[i]=A1[i]-A2[i];
            }
        }
        reverse(F3,n);
        if (F3[N]>=5)
        {
            F3[N-1]++;
            for (i=N-1;i>=0;i--)
                if (F3[i]>=10)
                {
                    F3[i]-=10;
                    if (i==0)
                        A3[0]++;
                    else
                        F3[i-1]++;
                }

        }
        if (m==0)
            printf("0");
        else
        {
            for (i=m-1;A3[i]==0 && i>0;i--);
            for (i;i>=0;i--)
                printf("%d",A3[i]);
        }
        printf(".");
        for (i=0;i<N;i++)
            printf("%d",F3[i]);
         printf("\n");
    }
    else
    {
        int flag=0;
        int i,j,k,h;
        int A1[MAX]={0}; int A2[MAX]={0}; int A3[MAX]={0};
        int F1[MAX]={0}; int F2[MAX]={0}; int F3[MAX]={0};
        for (i=0;s1[i]!='.' && i<strlen(s1);i++)
            A2[i]=s1[i]-'0';
        for (j=0;s2[j]!='.' && j<strlen(s2);j++)
            A1[j]=s2[j]-'0';
        reverse(A2,i); reverse(A1,j);
        int m=(i>j)?i:j;
        for (i=i+1,k=0;i<strlen(s1);i++,k++)
            F2[k]=s1[i]-'0';
        for (j=j+1,h=0;j<strlen(s2);j++,h++)
            F1[h]=s2[j]-'0';
        int n=(h>k)?h:k;
        reverse (F1,n); reverse(F2,n);
        for (i=0;i<n;i++)
        {
            if (F1[i]>=F2[i])
            {
                F3[i]=F1[i]-F2[i];
            }
            else
            {
                if (i==n-1) flag=1;
                F1[i+1]--;
                F1[i]+=10;
                F3[i]=F1[i]-F2[i];
            }
        }
        if (flag==1)
            A1[0]--;
        for (i=0;i<m;i++)
        {
            if (A1[i]>=A2[i])
            {
                A3[i]=A1[i]-A2[i];
            }
            else
            {
                A1[i+1]--;
                A1[i]+=10;
                A3[i]=A1[i]-A2[i];
            }
        }
         reverse(F3,n);
        if (F3[N]>=5)
        {
            F3[N-1]++;
            for (i=N-1;i>=0;i--)
                if (F3[i]>=10)
                {
                    F3[i]-=10;
                    if (i==0)
                        A3[0]++;
                    else
                        F3[i-1]++;
                }

        }
        printf("-");
        if (m==0)
            printf("0");
        else
        {
            for (i=m-1;A3[i]==0 && i>0;i--);
            for (i;i>=0;i--)
                printf("%d",A3[i]);
        }
        printf(".");
        for (i=0;i<N;i++)
            printf("%d",F3[i]);
         printf("\n");
    }
    return 0;
}
