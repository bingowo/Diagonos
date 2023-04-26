// We will use binary search to find the answer
// We will first find the minimum height in the valley
// Then we will use binary search to find the water level
// We will calculate the amount of water at that level
// If it is greater than or equal to the given rain, we will update our answer
// If it is less than the given rain, we will search for a higher water level
// We will repeat this process until we find the maximum water level that can be achieved with the given rain

#include <stdio.h>

int n, s;
int a[1005];

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    scanf("%d%d", &n, &s);
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < a[l]) l = i;
        if (a[i] > a[r]) r = i;
    }
    int ans_up = 0, ans_down = 1;
    int h = a[l];
    while (h <= a[r]) {
        int left = h, right = h;
        for (int i = l; i <= r; i++) {
            if (a[i] > h) {
                right = i;
                break;
            }
            if (a[i] == h) {
                left = i;
            }
        }
        int water = min(h, a[left]) * (left - l);
        for (int i = l + 1; i < left; i++) {
            water += min(h, a[i]);
        }
        water += min(h, a[right]) * (r - right);
        for (int i = right + 1; i < r; i++) {
            water += min(h, a[i]);
        }
        if (water >= s) {
            int up = h * s + ans_up * ans_down;
            int down = ans_down * h;
            int g = gcd(up, down);
            ans_up = up / g;
            ans_down = down / g;
            break;
        }
        h++;
    }
    if (ans_down == 1) {
        printf("%d\n", ans_up);
    } else {
        printf("%d+%d/%d\n", ans_up / ans_down, ans_up % ans_down, ans_down);
    }
    return 0;
}