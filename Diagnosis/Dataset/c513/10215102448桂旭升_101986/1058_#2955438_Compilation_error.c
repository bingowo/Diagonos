 1 #include <stdio.h>
 2 #define OUT 0 /* outside a word */
 3 #define IN 1  /* inside a word  */
 4 
 5 int main(void)
 6 {
 7     int c, state;
 8 
 9     state = OUT;
10     while ( ( c = getchar() ) != EOF ) {
11         if (state == OUT) {
12             if (c == ' ' || c == '\t' || c == '\n')
13                 state = OUT;
14             else {
15                 state = IN;
16                 putchar(c); //action
17             }
18         } else {
19             if (c != ' ' && c != '\t' && c != '\n') {
20                 state = IN;
21                 putchar(c); //action
22             } else {
23                 putchar('\n');//action
24                 state = OUT;
25             }
26         }
27     }
28     return 0;
29 }