#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char a[123]
}BIGN;

int cmp(const void* a,const void* b)
{
    BIGN* pa=(BIGN*)a; BIGN* pb=(BIGN*)b;
    if (pa->a[0]=='-' && pb->a[0]!='-')
        return -1;
    if (pa->a[0]!='-' && pb->a[0]=='-')
        return 1;
    if (pa->a[0]!='-' && pb->a[0]!='-')
    {
        if (strlen(pa->a)>strlen(pb->a)) return 1;
        if (strlen(pa->a)<strlen(pb->a)) return -1;
        if (strlen(pa->a)==strlen(pb->a))
        {
            for (int i=0;i<strlen(pb->a);i++)
            {
                if (pa->a[i]>pb->a[i]) return 1;
                if (pa->a[i]<pb->a[i]) return -1;
            }
        }
    }
    if (pa->a[0]=='-' && pb->a[0]=='-')
    {
        if (strlen(pa->a)>strlen(pb->a)) return -1;
        if (strlen(pa->a)<strlen(pb->a)) return 1;
        if (strlen(pa->a)==strlen(pb->a))
        {
            for (int i=0;i<strlen(pb->a);i++)
            {
                if (pa->a[i]>pb->a[i]) return -1;
                if (pa->a[i]<pb->a[i]) return 1;
            }
        }
    }

}

void reverse (char* s)
{
    char tmp;
    for (int i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        tmp=s[i];
        s[i]=s[j];
        s[j]=tmp;
    }

}

int main()
{
    int n;
    scanf("%d",&n);
    BIGN* arr=(BIGN*)malloc(n*sizeof(BIGN));
    for (int i=0;i<n;i++)
        scanf("%s",arr[i].a);
    qsort(arr,n,sizeof(BIGN),cmp);
    char result[130]={0};
    for (int i=0;i<129;i++)
        result[i]='0';
    if (arr[0].a[0]!='-' && arr[n-1].a[0]!='-')
    {
        reverse(arr[n-1].a);
        reverse(arr[0].a);
        int i;
        for (i=0;i<strlen(arr[n-1].a);i++)
        {
            if (i>=strlen(arr[0].a))
                arr[0].a[i]='0';
        }
        arr[0].a[i]=0;
        for (i=0;i<strlen(arr[n-1].a);i++)
        {
            if (arr[n-1].a[i]>=arr[0].a[i])
                result[i]+=arr[n-1].a[i]-arr[0].a[i];
            else
            {
                result[i+1]--;
                result[i]+=arr[n-1].a[i]+10-arr[0].a[i];
            }
        }
        for (int j=i-1;j<123;j++)
            if (result[j]=='0')
                result[j]=0;
        reverse(result);
        printf("%s\n",result);
    }
    else if (arr[0].a[0]=='-' && arr[n-1].a[0]=='-')
    {
        reverse(arr[n-1].a);
        reverse(arr[0].a);
        arr[n-1].a[strlen(arr[n-1].a)-1]=0;
        arr[0].a[strlen(arr[0].a)-1]=0;
        int i;
        for (i=0;i<strlen(arr[0].a);i++)
        {
            if (i>=strlen(arr[n-1].a))
                arr[n-1].a[i]='0';
        }
        arr[0].a[i]=0;
        for (i=0;i<strlen(arr[n-1].a);i++)
        {
            if (arr[0].a[i]>=arr[n-1].a[i])
                result[i]+=arr[0].a[i]-arr[n-1].a[i];
            else
            {
                result[i+1]--;
                result[i]+=arr[0].a[i]+10-arr[n-1].a[i];
            }
        }
        for (int j=i-1;j<123;j++)
            if (result[j]=='0')
                result[j]=0;
        reverse(result);
        printf("%s\n",result);
    }
    else if (arr[0].a[0]=='-' && arr[n-1].a[0]!='-')
    {
        reverse(arr[n-1].a);
        reverse(arr[0].a);
        arr[0].a[strlen(arr[0].a)-1]=0;
        int i,len=(strlen(arr[0].a)>strlen(arr[n-1].a)?strlen(arr[0].a):strlen(arr[n-1].a)),flag=0;
        for (i=0;i<len;i++)
        {
            if (i>=strlen(arr[n-1].a))
                arr[n-1].a[i]='0';
            if (i>=strlen(arr[0].a))
                arr[0].a[i]='0';
        }
        arr[0].a[i]=0;
        arr[n-1].a[i]=0;
        for (i=0;i<len;i++)
        {
            result[i]+=arr[0].a[i]+arr[n-1].a[i]-2*'0';
            if (result[i]>'9' && i<len-1)
            {
                result[i+1]++;
                result[i]=result[i]-'9'-1+'0';
            }
            if (result[i]>'9' && i==len-1)
            {
                result[i+1]='1';
                result[i]=result[i]-'9'-1+'0';
                result[i+2]=0;
                flag=1;
            }
        }
        if (flag==0)
            result[i]=0;
        reverse(result);
        printf("%s\n",result);

    }
    free(arr);
    return 0;
}
