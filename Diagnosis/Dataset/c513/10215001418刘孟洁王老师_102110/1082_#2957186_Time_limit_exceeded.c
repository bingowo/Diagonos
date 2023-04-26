#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define N 10007

int main()
{
    int i,n,j,k1,k2,kk1,kk2,l,h,c1,c2,d1,d2,len1,len2,ll,lll,num,j1,j2;
    char s1[N],s2[N];
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        int *ss1,*ss2,sss1[N] = {0},sss2[N] = {0},sum[N] = {0},zsum[N] = {0};
        scanf("%s%s%d",s1,s2,&num);
        len1 = strlen(s1);
        len2 = strlen(s2);
        for(l = 0; l < len1; l++)
            if(s1[l] == '.'){k1 = l;break;}
        if(k1 == 0)
            {
                for(j = len1; j >= 1; j--)s1[j] = s1[j-1];
                s1[0] = '0';
                s1[len1 + 1] = '\0';
                k1 = 1;
                l = 0;
            }

        if(l == len1)
           {
               s1[len1++] = '.';
               s1[len1] = '\0';
               l = len1;
               k1 = l-1;
           }
        for(h = 0; h < len2; h++)
            if(s2[h] == '.'){k2 = h;break;}
        if(k2 == 0)
            {
                for(j = len2; j >= 1; j--)s2[j] = s2[j-1];
                s2[0] = '0';
                s2[len2 + 1] = '\0';
                k2 = 1;
                h = 0;
            }
        if(h == len2)
           {
               s2[len2++] = '.';
               s2[len2] = '\0';
               h = len2;
               k2 = h-1;
           }
        if(l < len1 && h < len2)
       {
            if(k1 > k2)
            {
                ll = k1;
                kk2 = k2-1;
                ss1 = (int*)malloc(k1*sizeof(int));
                ss2 = (int*)malloc(k1*sizeof(int));
                for(j = k1-1; j >= 0; j--)ss1[j] = s1[j]-'0';
                for(j = k1-1; kk2 >= 0; j--,kk2--)ss1[j] = s1[kk2]-'0';
            }
            else if(k1 <= k2)
            {
                ll = k2;
                kk1 = k1-1;
                ss1 = (int*)malloc(k2*sizeof(int));
                ss2 = (int*)malloc(k2*sizeof(int));
                for(j = k2-1; j >= 0; j--)ss2[j] = s2[j]-'0';
                for(j = k2-1; kk1 >= 0; j--,kk1--)ss2[j] = s2[kk1]-'0';
            }
            for(l += 1,j1 = 0; l < len1; j1++, l++)sss1[j1] = s1[l]-'0';
            for(h += 1,j2 = 0; h < len2; j2++, h++)sss2[j2] = s2[h]-'0';
       }
       else if(l == len1)
       {
           j1 = 0;
           if(h < len2)
           {
              if(k1 > k2)
            {
                ll = k1;
                kk2 = k2-1;
                ss1 = (int*)malloc(k1*sizeof(int));
                ss2 = (int*)malloc(k1*sizeof(int));
                for(j = k1-1; j >= 0; j--)ss1[j] = s1[j]-'0';
                for(j = k1-1; kk2 >= 0; j--,kk2--)ss1[j] = s1[kk2]-'0';
            }
            else if(k1 <= k2)
            {
                ll = k2;
                kk1 = k1-1;
                ss1 = (int*)malloc(k2*sizeof(int));
                ss2 = (int*)malloc(k2*sizeof(int));
                for(j = k2-1; j >= 0; j--)ss2[j] = s2[j]-'0';
                for(j = k2-1; kk1 >= 0; j--,kk1--)ss2[j] = s2[kk1]-'0';
            }
            for(h += 1,j2 = 0; h < len2; j2++, h++)sss2[j2] = s2[h]-'0';
           }
       }
       else if(l == len2)
       {
           j2 = 0;
           if(k1 > k2)
            {
                ll = k1;
                kk2 = k2-1;
                ss1 = (int*)malloc(k1*sizeof(int));
                ss2 = (int*)malloc(k1*sizeof(int));
                for(j = k1-1; j >= 0; j--)ss1[j] = s1[j]-'0';
                for(j = k1-1; kk2 >= 0; j--,kk2--)ss1[j] = s1[kk2]-'0';
            }
            else if(k1 <= k2)
            {
                ll = k2;
                kk1 = k1-1;
                ss1 = (int*)malloc(k2*sizeof(int));
                ss2 = (int*)malloc(k2*sizeof(int));
                for(j = k2-1; j >= 0; j--)ss2[j] = s2[j]-'0';
                for(j = k2-1; kk1 >= 0; j--,kk1--)ss2[j] = s2[kk1]-'0';
            }
           for(l += 1,j1 = 0; l < len1; j1++, l++)sss1[j1] = s1[l]-'0';
       }
       ll--;
       for(j = 0; j <= ll/2; j++)
       {
           c1 = ss1[j];
           ss1[j] = ss1[ll-j];
           ss1[ll-j] = c1;
           c2 = ss2[j];
           ss2[j] = ss2[ll-j];
           ss2[ll-j] = c2;
       }
       lll = j1>j2?j1:j2;
       lll--;
       for(j = 0; j <= lll/2; j++)
       {
           d1 = sss1[j];
           sss1[j] = sss1[lll-j];
           sss1[lll-j] = d1;
           d2 = sss2[j];
           sss2[j] = sss2[lll-j];
           sss2[lll-j] = d2;
       }
       for(j = 0; j < lll+1; j++)
       {
           sum[j] = sss1[j] + sss2[j];
       }
       for(j = 0;j < lll+1; j++)
       {
           if(sum[j] > 10)
           {
              sum[j+1] += (sum[j]/10);
              sum[j] %= 10;
           }
       }
       if(sum[j])
        {
            zsum[0] = sum[j];
        }
        lll = j;
        for(j = 0; j <= lll/2; j++)
        {
            c1 = sum[j];
            sum[j] = sum[lll-j];
            sum[lll-1] = c1;
        }
        sum[lll+1] = 0;
        for(j = num+1;j >= 0; j--)
        {
            if(sum[j] >= 5)sum[j-1] += 1;
        }
        if(sum[0] == 10)
        {zsum[0]++;sum[0] = 0;}
        for(j = 0; j < ll+1; j++)
       {
           zsum[j] = ss1[j] + ss2[j];
       }
       for(j = 0;j < ll+1; j++)
       {
           if(zsum[j] > 10)
           {
              zsum[j+1] += (zsum[j]/10);
              zsum[j] %= 10;
           }
       }
       if(zsum[j])ll++;
        printf("case #%d:\n",i);
        for(j = ll; j >= 0; j--)printf("%d",zsum[j]);
        printf(".");
        for(j = 0;j <= lll; j++)printf("%d",sum[j]);
        printf("\n");

    }
    return 0;
}

