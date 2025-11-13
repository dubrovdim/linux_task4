#include "stringProcessor.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int32_t get_str(const char* msg, char* str, int32_t limit)
{
    if (!str || limit <= 0) return -1;

    if (msg) { fputs(msg, stdout); fflush(stdout); }
    if (!fgets(str, limit, stdin)) return -1;

    int32_t len = 0;
    while (len < limit && str[len] != '\0' && str[len] != '\n') ++len;

    if (len < limit && str[len] == '\n') {
        str[len] = '\0';
    } else if (len >= limit) {
        str[limit - 1] = '\0';
        len = limit - 1;
    } else {
        str[len] = '\0';
    }
    return len;
}

size_t strlenn(const char* str)
{
    if (!str) return 0u;
    const char* p = str; size_t n = 0u;
    while (*p++) ++n;
    return n;
}

void strcopy(char* fStr, char* sStr, size_t until)
{
    if (!fStr || !sStr || until == 0u) return;
    size_t i = 0u;
    for (; i < until && sStr[i] != '\0'; ++i) fStr[i] = sStr[i];
    if (i < until) fStr[i] = '\0'; else fStr[until - 1u] = '\0';
}

int32_t strcmpp(const char* fStr, const char* sStr)
{
    if (!fStr && !sStr) return 0;
    if (!fStr) return -1;
    if (!sStr) return 1;
    while (*fStr && *sStr && *fStr == *sStr) { ++fStr; ++sStr; }
    return (int32_t)((unsigned char)*fStr - (unsigned char)*sStr);
}

bool is_string_valid(const char* str)
{
    if (!str) return false;
    if (*str == '\0') return false;

    size_t len = 0;
    bool has_non_space = false;
    const unsigned char* p = (const unsigned char*)str;

    while (*p != '\0') {

        if (len >= STRING_MAX) return false;

        if (!isspace(*p)) has_non_space = true;

        if (ispunct(*p)) {
            unsigned char next = *(p + 1);
            
            if (next != '\0' && ispunct(next)) {
                return false;
            }
        }

        p++;
        len++;
    }

    if (len >= STRING_MAX) return false;

    return has_non_space;
}