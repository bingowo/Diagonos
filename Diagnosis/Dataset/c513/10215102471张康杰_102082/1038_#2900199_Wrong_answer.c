#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,p;
    scanf("%d %d %d",&n,&m,&p);
    int matrix[n][m];
    int i,j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    int length;
    if(n <= m)
        length = n;
    else
        length = m;
    int sum = 0;
    int k,s;
    int count = 0;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            int num;
            int flag = 0;
            sum = matrix[i][j];
            for(k = 1;k < length;k++)
            {
                num = 0;
                if(i - k >= 0&&j + k < m)
                {
                    if(flag)
                    {
                        count++;
                        continue;
                    }
                    for(s = j;s <= j + k;s++)
                    {
                        sum +=  matrix[i - k + num++][s];
                    }
                     if(sum >= k)
                     {
                         count++;
                         flag = 1;
                     }
                }
                else
                    break;
            }
            flag = 0;
            sum = matrix[i][j];
            for(k = 1;k < length;k++)
            {
                num = 0;
                if(i + k < n&&j + k <m)
                {
                    if(flag)
                    {
                        count++;
                        continue;
                    }
                    for(s = j;s <= j+k;s++)
                    {
                        sum += matrix[i + k - num++][s];
                    }
                    if(sum >= k)
                     {
                         count++;
                         flag = 1;
                     }
                }
                else
                    break;
            }
            flag = 0;
            sum = matrix[i][j];
            for(k = 1;k < length;k++)
            {
                num = 0;
                if(i - k >=0 &&j - k >=0 )
                {
                    if(flag)
                    {
                        count++;
                        continue;
                    }
                    for(s = j;s >= j - k;s--)
                    {
                        sum += matrix[i - k + num++][s];
                    }
                    if(sum >= k)
                    {
                        num++;
                        flag = 1;
                    }
                }
                else
                    break;
            }
            flag = 0;
            sum = matrix[i][j];
            for(k = 1;k < length;k++)
            {
                num = 0;
                if(i + k < n && j - k >= 0)
                {
                    if(flag)
                    {
                        count++;
                        continue;
                    }
                    for(s = j;s >= j - k;s--)
                    {
                        sum += matrix[i + k - num++][s];
                    }
                    if(sum >= k)
                    {
                        num++;
                        flag = 1;
                    }

                }
                else
                    break;
            }
        }
    }
    printf("%d",count);
    return 0;
}
