#include <stdio.h>

int *eng_kop(int *a, int n, int *takror) {
    if (n <= 0 || a == NULL) {
        *takror = 0;
        return NULL;
    }

    int max_freq = 0;
    int *best_ptr = &a[0];

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (*(a + j) == *(a + i)) {
                count++;
            }
        }
        if (count > max_freq) {
            max_freq = count;
            best_ptr = (a + i);
        }
    }

    *takror = max_freq;
    return best_ptr;
}

void chop_et_takrorlanuvchilar(const int *a, int n) {
    printf("\n--- Takrorlanuvchi elementlar va ularning soni ---\n");
    int topildi = 0;
    for (int i = 0; i < n; i++) {
        int already_printed = 0;
        for (int k = 0; k < i; k++) {
            if (a[k] == a[i]) {
                already_printed = 1;
                break;
            }
        }
        if (already_printed) continue;

        int count = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] == a[i]) {
                count++;
            }
        }

        if (count > 1) {
            printf("Element: %d | Uchradi: %d marta\n", a[i], count);
            topildi = 1;
        }
    }
    if (!topildi) {
        printf("Takrorlanuvchi elementlar mavjud emas.\n");
    }
}

int main() {
    int n;
    printf("Massiv o'lchamini kiriting (1 dan 100 gacha): ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 100) {
        printf("Xato: Noto'g'ri massiv o'lchami kiritildi!\n");
        return 1;
    }

    int arr[100];
    printf("%d ta butun sonni kiriting:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Xato: Son o'rniga noto'g'ri belgi kiritildi!\n");
            return 1;
        }
    }

    chop_et_takrorlanuvchilar(arr, n);

    int takror_soni = 0;
    int *ptr = eng_kop(arr, n, &takror_soni);

    if (ptr != NULL) {
        printf("\n--- Eng ko'p uchragan element ---\n");
        printf("Qiymati: %d\n", *ptr);
        printf("Uchrashlar soni: %d marta\n", takror_soni);
        printf("Xotiradagi manzili (pointer %%p): %p\n", (void *)ptr);
    }

    return 0;
}
