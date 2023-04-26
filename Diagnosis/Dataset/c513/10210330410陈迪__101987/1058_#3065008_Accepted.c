#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int main() {
    char *program = malloc(100000 * sizeof(char));
    int n = -1;
    while((program[++n] = getchar()) != EOF);
    program[n] = 0;

    int i = 0;
    while(i < n) {
        switch (program[i])
        {
        case '/':
            switch (program[i+1])
            {
            case '/':
                while(program[i++] != '\n');
                i -= 1;
                putchar('\n');
                break;
            case '*':
                i += 2;
                while(program[i] != '*' || program[i + 1] != '/') {
                    i += 1;
                }
                i +=1;
                break;
            default:
                putchar(program[i]);
                break;
            }
            break;
        case '"':
            putchar('"');
            i +=1;
            while(program[i] != '"') {
                putchar(program[i]);
                if(program[i] == '\\') {
                    i += 1;
                    putchar(program[i]);
                }
                i += 1;
            }
            putchar('"');
            break;
        case '\\':
            putchar(program[i]);
            putchar(program[i+1]);
            i += 1;
            break;
        default:
            putchar(program[i]);
            break;
        }
        i++;
    }
    return 0;
}
