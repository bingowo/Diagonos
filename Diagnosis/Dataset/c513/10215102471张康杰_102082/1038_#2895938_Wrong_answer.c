#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,p,num = 0;
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
    int k,t,s;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            for(k = 1;k < length;k++)
            {
                int count = 0;
                if(i - k >= 0&&j + k < m)
                {
                    for(t = i - k;t <= i;t++)
                    {
                        for(s = j+count;s <= j+k;s++)
                        {
                            sum += matrix[t][s];
                        }
                        count++;
                    }
                    if(sum >= k)
                        num++;
                }
                else if(i + k < n&&j + k <m)
                {
                    for(t = i;t <= i + k;t++)
                    {
                        for(s = j;s <= j+k-count;s++)
                        {
                            sum += matrix[t][s];
                        }
                        count++;
                    }
                    if(sum >= k)
                        num++;
                }
                else if(i - k >=0 &&j - k >=0 )
                {
                    for(t = i - k;s <= i;s++)
                    {
                        for(s = j-count;s <= j;s++)
                        {
                            sum += matrix[t][s];
                        }
                        count++;
                    }
                    if(sum >= k)
                        num++;

                }
                else if(i + k < n && j - k >= 0)
                {
                    for(t = i;t <= i+k;t++)
                    {
                        for(s = j - k +count;s <= j;s++)
                        {
                            sum += matrix[t][s];
                        }
                        count++;
                    }
                    if(sum >= k)
                        num++;
                }
            }
        }
    }
    printf("%d",num);
    return 0;
}
