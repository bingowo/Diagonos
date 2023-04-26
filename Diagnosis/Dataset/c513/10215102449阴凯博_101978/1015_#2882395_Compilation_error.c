#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int isprime(int a)
{
    int cnt=0;
    if (a==2) return 1;
    else if (a==1 || a%2==0) return 0;
    else
    {
        for (int i=1;i<=sqrt(a);i+=2)
        {
            if (a%i==0) cnt++;
        }
    }
    if (cnt>1) return 0;
    else return 1;
}


void reverse(int *a,int m)
{
    int i,j,tmp;
    for (i=0,j=m-1;i<j;i++,j--)
    {
        tmp=a[i];
        a[i]=a[j];
        a[j]=tmp;
    }
}



int cnt(char* s)
{
    int i=0,j=0;
    int n=strlen(s);
    while (i<n)
    {
        if (s[i]==',') j++;
        i++;
    }
    return j+1;
}

int* trans(char* s)
{
    int i=0,j=0,m=0,k;
    int n=cnt(s);
    int* a=(int*)malloc(n*sizeof(int));
    char s1[36]={0};
    while (i<n && j<strlen(s))
    {
        s1[m++]=s[j++];
        if (s[j]==',')
        {
            a[i++]=atoi(s1);
            for (k=0;k<m;k++)
                s1[k]='\0';
            m=0;
            j++;
        }
        if (j==strlen(s)-1 || i==n-1)
        {
            a[i]=atoi(s1);
        }
    }
    return a;
}



int main()
{
    int arr[26]={2,3,5,7};
    int i=7,j=4;
    while (j<26)
    {
        i+=2;
        if (isprime(i)) arr[j++]=i;
    }
    int T;
    scanf("%d",&T);
    char s1[26]={0}; char s2[26]={0};
    for(i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        scanf("%s %s",s1,s2);
        int n=cnt(s1);
        int m=cnt(s2);
        int* a1=NULL; a1=trans(s1);
        int* a2=NULL; a2=trans(s2);
        reverse(a1,n); reverse(a2,m);
        int c=0,k,x;  int s[30]={0};
        int max=m>=n?m:n; int min=m<=n?m:n;
        for (k=0;k<max;k++)
        {

            if (k>min-1)
            {
                if (min==n)
                {
                    x=a2[k]+c;
                    if (x>=arr[k])
                    {
                        s[k]=x-arr[k];
                        c=1;
                    }
                    else
                    {
                        s[k]=x;
                        c=0;
                    }

                }
                else
                {
                    x=a1[k]+c;
                    if (x>=arr[k])
                    {
                        s[k]=x-arr[k];
                        c=1;
                    }
                    else
                    {
                        s[k]=x;
                        c=0;
                    }
                }

            }
            else
            {
                x=a1[k]+a2[k]+c;
                if (x>=arr[k])
                {
                    s[k]=x-arr[k];
                    c=1;
                }
                else
                {
                    s[k]=x;
                    c=0;
                }

            }

        }
        reverse(s);
        if (c==1)
        {
            printf("1,");
            for (k=0;k<max;k++)
            {
                printf("%d%c",s[k],k==max-1?'\n':',');
            }
        }
        else
            for (k=0;k<max;k++)
            {
                printf("%d%c",s[k],k==max-1?'\n':',');
            }

        free(a1); free(a2);
    }



    return 0;
}
