#include<stdio.h>

int main()
{
    int n,i,j,k,d,a,num,l;
    int s[10007] = {0};
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%d%d",&a,&num);
        if(num == 0){printf("case #%d:\n",i);printf("1\n");continue;}
        s[0] = 1;
        for(j = 0,k = 0; j < num; j++)
        {
            for(l = 0; l <= k; l++)
            {s[l] *= a;}
             for(l = 0; l <= k; l++)
               {
                   if(s[l] < 10)continue;
                   else
                  {
                   if(l == k){s[l+1] += (s[l]/10); s[l] %= 10; k++; break;}
                   else if(s[l] >= 10){s[l+1] += (s[l]/10); s[l] %= 10;}
                  }
               }
        }
        if(s[k] != 0)k++;
        k--;
        for(j = 0; j <= k/2; j++)
        {
            d = s[j];
            s[j] = s[k-j];
            s[k-j] = d;
        }
        printf("case #%d:\n",i);
        for(j = 0 ; j <= k; j++)printf("%d",s[j]);
        printf("\n");
        for(j = 0; j <= k; j++)s[j] = 0;

    }
    return 0;
}