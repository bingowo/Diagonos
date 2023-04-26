  
#define OUT 0 /* outside a word */
#define IN 1  /* inside a word  */
#include <stdio.h>
int main(void)
{
	int c, state;

    state = OUT;
    while ( ( c = getchar() ) != EOF ) {
        if (state == OUT) {
            if (c == ' ' || c == '\t' || c == '\n')
               state = OUT;
            else {
              state = IN;
              putchar(c); //action
            }
        } 
		else {
            if (c != ' ' && c != '\t' && c != '\n') {
                state = IN;
                putchar(c); //action
            } 
			else {
                putchar('\n');//action
                state = OUT;
            }
        }
    }
    return 0;
}