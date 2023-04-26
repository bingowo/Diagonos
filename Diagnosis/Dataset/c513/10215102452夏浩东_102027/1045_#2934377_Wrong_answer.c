#include <stdio.h>
#include <string.h>
#include <math.h>
char s[100000][100]={'\0'};
int L[100000][100]={0};
int cmp(char *a,char *b)
{
    char A[101]={'\0'};
    char B[101]={'\0'};
    A[0]=a[0];
    B[0]=b[0];
    for(int i=1,k=0;a[i]!='\0';i++) if(a[i]!=a[i-1]){A[k]=a[i];k++;}
    for(int i=1,k=0;b[i]!='\0';i++) if(b[i]!=b[i-1]){B[k]=b[i];k++;}
    return strcmp(A,B);
}
int main()
{
    int cnt=0;
    int diff=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++) scanf("%s",s[i]);
    for(int i=1;i<cnt;i++) if(cmp(s[i],s[0])!=0){diff=1;break;}
    if(diff==1) printf("-1");
    else
    {
        for(int i=0;i<cnt;i++)
        {
            int k=0;
            L[i][k]=1;
            for(int j=1;s[i][j]!='\0';j++)
            {
                if(s[i][j]==s[i][j-1]) L[i][k]++;
                else {k++;L[i][k]++;}
            }
        }
        long long int sum=0;
        for(int j=0;L[0][j]!=0;j++)
        {
            int midnum=L[0][j];
            for(int i=0;i<cnt;i++)
            {
                int num=0;
                for(int k=0;L[k][j]!=0;k++)
                {
                    if(L[k][j]>L[i][j]) num++;
                }
                if(num==cnt/2) {midnum=L[i][j];break;}
            }
            for(int i=0;i<cnt;i++){sum+=abs(L[i][j]-midnum);}
        }
        printf("%lld\n",sum);
    }
    return 0;
}