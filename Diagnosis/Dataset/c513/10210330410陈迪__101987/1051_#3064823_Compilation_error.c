#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

static char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static int mod_table[] = {0, 2, 1};

char *base64_encode=(const unsigned char *data, char *encoded_data) {
    int input_length = strlen(data);

    int output_length = 4 * ((input_length + 2) / 3);

    if (encoded_data == NULL) return NULL;

    for (int i = 0, j = 0; i < input_length;) {

        uint32_t octet_a = i < input_length ? (unsigned char)data[i++] : 0;
        uint32_t octet_b = i < input_length ? (unsigned char)data[i++] : 0;
        uint32_t octet_b = i < input_length ? (unsigned char)data[i++] : 0;

        uint32_t triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;

        encoded_data[j++] = encoding_table[(triple >> 3 * 6) & 0x3F];
        encoded_data[j++] = encoding_table[(triple >> 2 * 6) & 0x3F];
        encoded_data[j++] = encoding_table[(triple >> 1 * 6) & 0x3F];
        encoded_data[j++] = encoding_table[(triple >> 0 * 6) & 0x3F];
    }

    for (int i = 0; i < mod_table[input_length % 3]; i++)
        encoded_data[output_length - 1 - i] = '=';
    encoded_data[output_length] = 0;
    return encoded_data;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i) {
        char s[256];
        scanf("%s", s);
        char *o = malloc(256 * sizeof(char));
        base64_encode(s,o);
        printf("case #%d:\n%s\n", i, o);
        free(o);
    }
    return 0;
}
