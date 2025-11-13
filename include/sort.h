#ifndef SORT
#define SORT

#include <stddef.h>

// Тільки оголошення (жодних include stringProcessor.h тут, щоб уникати циклу)
void   swap(char** a, char** b);
void   quick_sort(char** arr, size_t length);

#endif // SORT
