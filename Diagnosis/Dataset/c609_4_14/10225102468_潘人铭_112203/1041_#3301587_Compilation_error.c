 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>
 #include <ctype.h>
 #define ll long long
 #define ull unsigned long long
 int min(int a, int b) {
    return a > b ? b : a;
 }
 int max(int a, int b) {
    return a < b ? b : a;
 }
 #define N 106
 int cnt, b[N], path[N], tot = 0;
 char st[N];
 struct str {
    char s[106];
 };
 struct str res[2000000];
 void dfs(int d, int now, int lim)
 {
    if (now >= lim)
   {
        for (int i = 0; i < now; i++)
       {
            char c;
            int x = path[i];
            if (x > 26)
                c = x - 27 + 'a';
            else
                c = x - 1 + 'A';
            res[tot].s[i] = c;
       }
        res[tot].s[now] = '\0';
        tot++;
        return;
   }
    if (d > 52)
  {
        return;
  }
    dfs(d + 1, now, lim);
    if (b[d])
   {
        path[now] = d;
        dfs(d + 1, now + 1, lim);
   }      
}
int cmp(const void* s1, const void* s2)
{
    struct str* a = (struct str*)s1;
    struct str* b = (struct str*)s2;
    return strcmp(a -> s, b -> s);
}
void solve(int t)
{
    memset(b, 0, sizeof(b));
    cnt = 0;
    tot = 0;
    printf("case #%d:\n", t);
    scanf("%s", st + 1);
    for (int i = 1; st[i]; i++)
   {
        int x;
        if (isupper(st[i]))
            x = st[i] - 'A' + 1;
        else
            x = st[i] - 'a' + 1 + 26;
        if (!b[x])
            b[x]++, cnt++;
   }
    for (int i = 1; i <= cnt; i++)
   {
        dfs(0, 0, i);
   }