#include <stdio.h>

int main() {
    char s[101];
    scanf("%s",s);
    int sum =0,count =1;
    for(int i=0;s[i] != '\0';i++)
    {
        if(s[i]>='0' && s[i] <= '9' && s[i+1]>='0' && s[i +1] <= '9')
            count ++;
        else
        {
            if(count >sum)
                sum = count;
            count = 1;
        }
    }
    printf("%d\n",sum);
    return 0;
}
