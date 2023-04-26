#include<stdio.h>
#include<string.h>

int prime[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};

int main()
{
    int t;
    scanf("%d",&t);
    int a[30],b[30],sum[30];
    char aa[1000],bb[1000];
    for(int z = 0; z < t; z++)
    {
        scanf("%s %s",aa,bb);
        if(strlen(aa) == 1 && strlen(bb) == 1 && aa[0] == '0' && bb[0] == '0')
            break;
        for(int i=0;i<30;i++)
            a[i]=b[i]=sum[i]=0;
        int lena = 0,temp = 0;
        for(int i = 0; i < strlen(aa); i++)
        {
            if(aa[i] != ',')
            {
                temp *= 10;
                temp += aa[i] - '0';
            }
            if(aa[i] == ',')
            {
                a[lena++] = temp;
                temp = 0;
            }
        }
        a[lena] = temp;
        int lenb = 0;
        temp = 0;
        for(int i = 0; i < strlen(bb); i++)
        {
            if(bb[i] != ',')
            {
                temp *= 10;
                temp += bb[i]-'0';

            }
            if(bb[i] == ',')
            {
                b[lenb++] = temp;
                temp = 0;
            }
        }
        b[lenb] = temp;
        int len = 0;
        int cnt = 0;
        int i,j,k;
        for(i = lena, j = lenb, k = 0; i >= 0 || j >= 0; k++,i--,j--)
        {
            if(i < 0)
                sum[k] += b[j];
            else if(j < 0)
                sum[k] += a[i];
            else
                sum[k] += a[i] + b[j];
            if(sum[k] >= prime[k])
            {
                sum[k] -= prime[k];
                sum[k+1]++;
            }
        }
        printf("case #%d:\n",z);
        printf("%d",sum[k] > 0 ? sum[k] : sum[--k]);
        for(int i = k - 1; i >= 0; i--)
        {
            printf(",%d",sum[i]);
        }
        printf("\n");
    }
    return 0;
}
