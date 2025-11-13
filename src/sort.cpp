#include "sort.h"
#include "stringProcessor.h" // тут потрібен strcmpp
#include <utility>

// Обмін двох елементів масиву вказівників на char
void swap(char** a, char** b)
{
    if (!a || !b) return;
    char* tmp = *a;
    *a = *b;
    *b = tmp;
}

// Ітеративний quicksort для масиву C-рядків (char*), порядок: зростання (лексикографічно)
void quick_sort(char** arr, size_t length)
{
    if (!arr || length < 2ull) return;

    // Невеликий стек для меж сегментів [l, r]
    size_t stack[64];
    size_t top = 0;

    auto push = [&](size_t l, size_t r) { stack[top++] = l; stack[top++] = r; };
    auto pop  = [&]() -> std::pair<size_t,size_t> {
        size_t r = stack[--top];
        size_t l = stack[--top];
        return {l, r};
    };

    push(0ull, length - 1ull);

    while (top) {
        auto [l0, r0] = pop();
        size_t l = l0, r = r0;

        while (l < r) {
            char* pivot = arr[l + (r - l)/2ull];
            size_t i = l, j = r;

            while (i <= j) {
                while (strcmpp(arr[i], pivot) < 0) ++i;
                while (strcmpp(arr[j], pivot) > 0) { if (j == 0ull) break; --j; }
                if (i <= j) {
                    swap(&arr[i], &arr[j]);
                    ++i;
                    if (j == 0ull) break;
                    --j;
                }
            }

            // Розкладаємо «хвости» так, щоб менший сегмент ішов у стек (tail-recursion elimination)
            if (j - l < r - i) {
                if (l < j) push(l, j);
                l = i;
            } else {
                if (i < r) push(i, r);
                if (j == (size_t)-1) break; // захист від підтікання беззнакового
                r = j;
            }
        }
    }
}
