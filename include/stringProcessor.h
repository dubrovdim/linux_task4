#ifndef STRING_PROCESSOR
#define STRING_PROCESSOR

#include <stdint.h>
#include <stddef.h>

#define STRING_MAX 512ull

int32_t get_str(const char* msg, char* str, int32_t limit);
size_t  strlenn(const char* str);
void    strcopy(char* fStr, char* sStr, size_t until);
int32_t strcmpp(const char* fStr, const char* sStr);

bool    is_string_valid(const char* str);

#endif
