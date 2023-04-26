#include <stdio.h>
#include <string.h>
int main()
{
    int i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        char Octal[10000];
        scanf("%s",Octal);
        char decimal[1000];
        int numbers = 0;
        int len = strlen(Octal) - 1;
        for (; len != 1; --len) {
            int digit = Octal[len] - '0';
            int j = 0;
            int temp;
            do {
                if (j < numbers) {
                    temp = digit * 10 + decimal[j] - '0';
                }
                else {
                    temp = digit * 10;
                }
                decimal[j++] = temp / 8 + '0';
                digit = temp % 8;
            } while (digit!=0 || j < numbers);
            numbers = j;
        }
        decimal[numbers] = '\0';

        printf("case #%d:\n",i);
        printf("0.");
        printf("%s\n",decimal);
    }
    return 0;
}
