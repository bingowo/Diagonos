#include <stdio.h>

int main() {

    char s[51];
    scanf("%s",s);

    int i = 1;
    int flag = 1;
    int count = 1;
    int arr[100] = {0};
    int j = 0;

    if(s[0] == '|')flag = 2;

    while(s[i])
    {
        if(flag == 1)
        {
            if(s[i] == '|')
            {
                count++;
                flag = 2;
            }else if(s[i] == '-')
            {
                arr[j++] = count;
                count = 1;
            }
        }else if(flag == 2)
        {
            if(s[i] == '-')
            {
                count++;
                flag = 1;
            }else if(s[i] == '|')
            {
                arr[j++] = count;
                count = 1;
            }
        }i++;
    }
    arr[j] = count;
    if(arr[1] == 0)
        printf("%d",arr[0]);
    else
    {
        int max;
        max = arr[0];
        for (int k = 1;arr[k]; ++k){
            if(arr[k] > max)
                max = arr[k];
        }printf("%d",max);
    }

}