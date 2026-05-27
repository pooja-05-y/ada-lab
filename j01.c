#include <stdio.h>

#define LEFT -1
#define RIGHT 1

int getMobile(int a[], int dir[], int n) {
    int mobile = 0, pos = -1;

    for (int i = 0; i < n; i++) {
        int next = i + dir[i];

        if (next >= 0 && next < n && a[i] > a[next]) {
            if (a[i] > mobile) {
                mobile = a[i];
                pos = i;
            }
        }
    }
    return pos;
}

void printPerm(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int a[n], dir[n];

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i] = LEFT;
    }

    printPerm(a, n);

    while (1) {
        int pos = getMobile(a, dir, n);

        if (pos == -1)
            break;

        int swapPos = pos + dir[pos];

        int temp = a[pos];
        a[pos] = a[swapPos];
        a[swapPos] = temp;

        temp = dir[pos];
        dir[pos] = dir[swapPos];
        dir[swapPos] = temp;

        pos = swapPos;

        for (int i = 0; i < n; i++) {
            if (a[i] > a[pos])
                dir[i] *= -1;
        }

        printPerm(a, n);
    }

    return 0;
}
