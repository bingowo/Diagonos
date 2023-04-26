#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* domain;
} Mail;

int cmp(const void* p1, const void* p2) {
    Mail mail_a = *(Mail*)p1, mail_b = *(Mail*)p2;
    int diff_dm = strcmp(mail_a.domain, mail_b.domain);
    if (diff_dm == 0)
        return strcmp(mail_b.name, mail_a.name);
    return diff_dm;
}

int main() {
    int n;
    scanf("%d", &n);
    Mail* arr_mails = (Mail*)malloc(sizeof(Mail) * n);
    for (int i = 0; i != n; ++i) {
        char nm[1000001 / n], dm[1000001 / n];
        scanf("%[^@]@%s", nm, dm);
        arr_mails[i].name = (char*)malloc(sizeof(char) * strlen(nm));
        arr_mails[i].domain = (char*)malloc(sizeof(char) * strlen(dm));
        strcpy(arr_mails[i].name, nm);
        strcpy(arr_mails[i].domain, dm);
    }
    qsort(arr_mails, n, sizeof(arr_mails[0]), cmp);
    for (int i = 0; i != n; ++i) {
        printf("%s@%s\n", arr_mails[i].name, arr_mails[i].domain);
        free(arr_mails[i].name);
        free(arr_mails[i].domain);
    }
    free(arr_mails);
    return 0;
}