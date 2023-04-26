#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define max(a, b) (a > b? a: b)
typedef struct HashItem{
    char buf[20][20];
    int n;
} HashItem;

HashItem hash_table[5000];
int n;

int hash_func(const char *key, int len) {
   int hash = 0;
   for(int i = 0; i < len; ++i)
      hash = (31 * hash + key[i]) % 5000;
   return hash;
}

bool in(char *w, int wn) {
    int hv = hash_func(w, wn);
    for(int i = 0, l = hash_table[hv].n; i < l; i++) {
        if(strncmp(hash_table[hv].buf[i], w, wn) == 0) {
            return true;
        }
    }
    return false;
}
int main() {
    int max_word_len = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        char line[256];
        scanf("%s", line);
        int word_len = strlen(line);
        max_word_len = max(word_len, max_word_len);
        int hv = hash_func(line, word_len);
        HashItem *item = hash_table + hv;
        strcpy(item->buf[item->n], line);
        item->n++;
    }
    char line[5000];
    scanf("%s", line);
    char *begin = line, *end = begin + strlen(line);
    bool first = true;
    while(begin != end) {
        char *e;
        for(e = begin + max_word_len; e > begin + 1; e--) {
            if(in(begin, e - begin)) {
                break;    
            }
        }
        if(first) {
            first = false;
        } else {
            printf(" ");
        }
        printf("%.*s", e - begin, begin);
        begin = e;
    }
    printf("\n");
    return 0;

}