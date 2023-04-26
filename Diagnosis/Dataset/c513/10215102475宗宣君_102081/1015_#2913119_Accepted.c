#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int T,i,num[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
    scanf("%d",&T);
    char a[100],b[100];
    for(i = 0;i<T;i++)
    {
        scanf("%s %s",a,b);
        int ans[30],A[26],N,j = 0,n = 0,m = 0,k,B[26];
        char *a1 = strtok(a,",");
        while(a1!=NULL)
        {
            A[j] = atoi(a1);
            a1 = strtok(NULL,",");
            j++;
        }
        for(k = 0;k<26;k++)
        {
            if(k<j/2)
            {N = A[k];
            A[k] = A[j-1-k];
            A[j-1-k] = N;}
            if(k>=j) A[k] = 0;
        }
        char *b1 = strtok(b,",");
       while(b1!=NULL)
        {
            B[m] = atoi(b1);
            b1 = strtok(NULL,",");
            m++;
        }
        for(k = 0;k<26;k++)
        {
            if(k<m/2)
            {N = B[k];
            B[k] = B[m-1-k];
            B[m-1-k] = N;}
            if(k>=m) B[k] = 0;
        }
        for(k = 0;k<((j>m)?j:m);k++)
        {
            if(A[k]+B[k]>=num[k]) {ans[n] = A[k]+B[k]-num[k];B[k+1]++;}
            else ans[n] = A[k] + B[k];
            n++;
        }
        if(B[k]) {ans[n] = B[k];n++;}
        printf("case #%d:\n",i);
        for(k = n-1;k>0;k--)
            printf("%d,",ans[k]);
        printf("%d\n",ans[0]);
    }
    return 0;
}
