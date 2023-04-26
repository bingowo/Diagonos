 #include <assert.h>
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// I extract a struct of Dynamic string out here,
// making it a separate struct. Actually we can
// make an integrated struct `Email` and handle
// all the work inside, which will reduce the
// code length for this of our need.
// ********************************************* //

// Handle to a dynamic string;
typedef struct {
    char *raw_str;
    size_t size; // Always less than _reserve.
    size_t _reserve;
} Dynstr;

// DOES NOT guarantee against EOF.
// Reads one more space and then discard it.
Dynstr read_dynstr(FILE *read_source) {
    Dynstr ret;
    ret.size = 0;
    ret.raw_str = (char *)malloc(sizeof(char) * 16);
    ret._reserve = 16;
    int ch;
    while (isspace(ch = getc(read_source))) {
        assert(ch != EOF);
    }
    do {
        ret.raw_str[ret.size++] = ch;
        if (ret.size == ret._reserve) {
            char *temp = (char *)malloc(sizeof(char) * (ret._reserve <<= 1));
            memcpy(temp, ret.raw_str, ret.size);
            free(ret.raw_str);
            ret.raw_str = temp;
        }
        ch = getc(read_source);
    } while (!isspace(ch));
    ret.raw_str[ret.size] = '\0';
    return ret;
}

typedef struct {
    // I choose to use (ptr, size) instead of (begin, end),
    // in respect of C conventions.
    Dynstr const *_raw_address_view;
    char *user_name_bg;
    char *domain_bg;
    size_t user_name_size;
    size_t domain_size;
} hdlEmail; // handle to Email.

hdlEmail get_email_handle(Dynstr const *full_address) {
    hdlEmail ret;
    char *iter = full_address->raw_str;
    for (; *iter != '@'; ++iter) {
        assert((size_t)(iter - full_address->raw_str) < full_address->size);
    }
    ret._raw_address_view = full_address;
    ret.user_name_bg = full_address->raw_str;
    ret.user_name_size = iter - ret.user_name_bg;
    ret.domain_bg = iter + 1;
    ret.domain_size = full_address->size - ret.user_name_size - 1;
    return ret;
}

// Unsafe: Breaks the `const` and temporarily changes the key strings.
int hdlEmail_cmp(void const *_lhs, void const *_rhs) {
    *(((hdlEmail *)_lhs)->domain_bg - 1) = '\0';
    int a = strcmp(((hdlEmail *)_lhs)->domain_bg, ((hdlEmail *)_rhs)->domain_bg);
    if (a == 0)
        a = strcmp(((hdlEmail *)_rhs)->user_name_bg, ((hdlEmail *)_lhs)->user_name_bg);
    *(((hdlEmail *)_lhs)->domain_bg - 1) = '@';
    return a;
}

int main() {
    uint32_t n; scanf("%u", &n);
    Dynstr *strarr = (Dynstr *)malloc(sizeof(Dynstr) * n);
    hdlEmail *hdlarr = (hdlEmail *)malloc(sizeof(hdlEmail) * n);
    for (uint32_t i = 0; i < n; ++i) {
        strarr[i] = read_dynstr(stdin);
        hdlarr[i] = get_email_handle(strarr + i);
    }
    qsort(hdlarr, n, sizeof(hdlEmail), hdlEmail_cmp);
    for (uint32_t i = 0; i < n; ++i) {
        printf("%s\n", hdlarr[i]._raw_address_view->raw_str);
    }
    free(strarr);
}