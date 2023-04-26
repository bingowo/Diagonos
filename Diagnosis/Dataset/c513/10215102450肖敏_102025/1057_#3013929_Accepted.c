#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct Node {
    char c;
    struct Node *next;
} Node, *Tree;

int main() {
    Tree tree = malloc(sizeof(Node));
    Tree end = malloc(sizeof(Node));
    end->c = toupper(getchar());
    end->next = NULL;
    tree->next = end;
    char c;
    while ((c = getchar()) != '\n') {
        c = toupper(c);
        Tree tmp = malloc(sizeof(Node));
        tmp->c = c;
        if (tmp->c >= tree->next->c) {
            tmp->next = tree->next;
            tree->next = tmp;
        }
        else {
            end->next = tmp;
            tmp->next = NULL;
            end = tmp;
        }
    }
    Tree p = tree->next;
    while (p) {
        printf("%c", p->c);
        p = p->next;
    }
    printf("\n");
    return 0;
}
