#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void solve(int t) {
    printf ("case #%d:\n", t);

 char Octal[55];
 char decimal[155];
 scanf ("%s", Octal);

 int numbers = 0;
 int temp=0;
int len = strlen(Octal) - 1;

for (; len != 1; --len) {

    int digit = Octal[len] -'0';

    int j = 0;

    do {

        if (j < numbers)
         {


            temp = digit*10 + decimal[j] -'0';
            //printf ("%d\n", temp);
         }

        else

            temp = digit*10;

        decimal[j++] = temp/8 + '0';

        digit = temp%8;

    } while (digit!=0 || j < numbers);

    numbers = j;

}

decimal[numbers] ='\0';
printf ("0.%s\n", decimal);

}
int main () {
 int T;
 scanf ("%d", &T);
 for (int i=0;i<T;i++) {
    solve(i);
 }
return 0;
}

