#include <stdio.h>
#include <string.h>

void dfs(char *begin, char *end, char *buf, int buf_idx) {
    for(; begin != end; ++begin) {
        buf[buf_idx] = *begin;
        buf[buf_idx + 1] = 0;
        puts(buf);
        dfs(begin + 1, end, buf, buf_idx + 1);
    }
}

char *unique(char *buf) {
    static char u[256];
    int hash[256] = {0};
    memset(u, 0, sizeof(u));
    for(int i = 0, l = strlen(buf); i < l; ++i) {
        if (hash[buf[i]] == 0) {
            hash[buf[i]] = 1;
        }
    };
    int j = 0;
    for(int i = 0; i < 256; i++) {
        if(hash[i] != 0) {
            u[j++] = i;
        }
    }
    u[j] = 0;
    return u;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i) {
        char buf[256];
        scanf("%s", buf);
        char *m = unique(buf);
        printf("case #%d:\n", i);
        char dfs_buf[256];
        dfs(m, m + strlen(m), dfs_buf, 0);
    }
	return 0;
}