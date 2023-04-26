#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int cnt=1;
int fun(int n)
{
    int i = 0; 
    int k;
    while (n != 0)
    {
        n /= 10;
        i++;
    }
    if (i > cnt)
    {
        cnt = i;
    }
    return i;
}
int main()
{
    int array[1000][2];
    int idx = 0;
    do {
        scanf("%d", &array[idx][1]);
        array[idx][0] = fun(array[idx][1]);
        idx++;
    } while (getchar() != '\n');
    
    for (int i = idx; i >=0; i--)
    {
        int flag = 0;
        for (int j = 0; j <idx-1; j++)
        {

            if (abs(array[j][1]) < abs(array[j + 1][1]))
            {
                int max1 = array[j + 1][0];
                int max2 = array[j + 1][1];
                array[j + 1][0] = array[j][0];
                array[j + 1][1] = array[j][1];
                array[j][0] = max1;
                array[j][1] = max2;
                flag = 1;
            }

        }
        if (flag == 0)
        {
            break;
        }
    }
    int num = 0;
    
    while(num!=idx)
    {
        int x = num;
        for (int m = x; m < idx; m++)
        {
            if (array[m][0] == cnt)
            {
                num++;
            }
            else
            {
                cnt--;
                break;
            }
        }
        for (int j = x; j < num; j++)
        {
            for (int k = x; k < num-1; k++)
            {
                if (array[k][1] > array[k + 1][1])
                {
                    int min = array[k][1];
                    array[k][1] = array[k + 1][1];
                    array[k + 1][1] = min;
                }
            }
        }
        
    }
    
    for (int i = 0; i < idx; i++)
    {
        printf("%d", array[i][1]);
        if (i < idx - 1)
        {
           printf(" ");
        }
    }

    return 0;
}