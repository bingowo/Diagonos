#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char s[100] = {0};
    char tmp[100] = {0};
    char c = 0;
    char arr[123] = {0};
    int i =0;
    int num = 0;
    int max = 0;
    int flag = 0;
    while((c = getchar())!='\n')
    {
        if(arr[c] == 0 && flag == 0)
        {
            arr[c] = 1;
            tmp[num++] = c;
            flag = 1;
        }
        else if(arr[c] == 0)
        {
            arr[c] = 1;
            tmp[num++] = c;
        }
        else
        {
            if(num>max)
            {
                strcpy(s, tmp);
                max = num;
            }
            char* a = 0;
            for(int i = 0; i<num; i++)
            {
                if(tmp[i] == c)
                {
                    a = &tmp[i];
                    break;
                }
            }
            int j = 0;
            while(a[j+1]!=0)
            {
                tmp[j] = a[j+1];
                j++;
            }
            tmp[j] = c;
            num = j+1;
            j++;
            for(; j<100; j++) tmp[j] = 0;
            for(int i = 0; i<123; i++) arr[i] = 0;
            for(int i = 0; i<num; i++)
            {
                arr[tmp[i]] = 1;
            }
        }

    }
    if(num>max)
    {
        strcpy(s, tmp);
    }
    printf("%s", s);
    return 0;
}
