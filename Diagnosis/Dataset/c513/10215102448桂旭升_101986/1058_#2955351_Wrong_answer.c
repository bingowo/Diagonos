#include <stdio.h>
 
int
main(void)
{
#define PROGRAM 0
#define SLASH 1
#define COMMENT 2
#define STAR 3
#define QUOTE 4
#define LITERAL 5
 
    /* State machine's current state, one of the above values. */
    int state;
 
    /* If state == QUOTE, then ' or ".  Otherwise, undefined. */
    int quote;
 
    /* Input character. */
    int c;
 
    state = PROGRAM;
    while ((c = getchar()) != EOF) {
        /* The following cases are in guesstimated order from most common
           to least common. */
        if (state == PROGRAM || state == SLASH) {
            if (state == SLASH) {
                /* Program text following a slash. */
                if (c == '*')
                    state = COMMENT;
                else {
                    putchar('/');
                    state = PROGRAM;
                }
            }
 
            if (state == PROGRAM) {
                /* Program text. */
                if (c == '\'' || c == '"') {
                    quote = c;
                    state = QUOTE;
                    putchar(c);
                }
                else if (c == "/*"[0])
                    state = SLASH;
                else
                    putchar(c);
            }
        }
        else if (state == COMMENT) {
            /* Comment. */
            if (c == "/*"[1])
                state = STAR;
        }
        else if (state == QUOTE) {
            /* Within quoted string or character constant. */
            putchar(c);
            if (c == '\\')
                state = LITERAL;
            else if (c == quote)
                state = PROGRAM;
        }
        else if (state == SLASH) {
        }
        else if (state == STAR) {
            /* Comment following a star. */
            if (c == '/')
                state = PROGRAM;
            else if (c != '*')
                state = COMMENT;
        }
        else /* state == LITERAL */ {
            /* Within quoted string or character constant, following \. */
            putchar(c);
            state = QUOTE;
        }
    }
 
    if (state == SLASH)
        putchar('/' //**/
                );
 
    return 0;
}