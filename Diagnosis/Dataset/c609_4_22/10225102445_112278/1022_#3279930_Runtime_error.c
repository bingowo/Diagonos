#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100000
#define MAX_LEN 1000

// 表示一个电子邮件地址的结构体
typedef struct {
    char username[MAX_LEN + 1];  // 用户名
    char domain[MAX_LEN + 1];    // 主机域名
} Email;

// 比较两个电子邮件地址的大小
int compare(const void* a, const void* b) {
    Email* email1 = (Email*) a;
    Email* email2 = (Email*) b;
    
    int cmp_domain = strcmp(email1->domain, email2->domain);
    
    if (cmp_domain == 0) {
        return strcmp(email2->username, email1->username);
    } else {
        return cmp_domain;
    }
}

int main() {
    int n;  // 电子邮件地址数量
    scanf("%d", &n);
    
    Email* emails = (Email*) malloc(sizeof(Email) * n);
    
    for (int i = 0; i < n; i++) {
        char email[MAX_LEN + 1];
        scanf("%s", email);
        
        // 分离用户名和主机域名
        char* separator = strchr(email, '@');
        int pos = separator - email;
        
        strncpy(emails[i].username, email, pos);
        emails[i].username[pos] = '\0';
        strcpy(emails[i].domain, separator + 1);
    }
    
    // 排序
    qsort(emails, n, sizeof(Email), compare);
    
    // 输出结果
    for (int i = 0; i < n; i++) {
        printf("%s@%s\n", emails[i].username, emails[i].domain);
    }
    
    free(emails);
    
    return 0;
}