#ifndef DTL_COMPARATORS
#define DTL_COMPARATORS

#if !defined(_MSC_VER)
#include <strings.h>
#else
#include <string.h>
#ifndef strncasecmp
#define strncasecmp			_strnicmp
#endif
#endif

class CaseInsensitive: public dtl::Compare<char> {
public:
    virtual bool impl(const char& a, const char& b) const {
        return tolower(a) == tolower(b);
    }
};

class StringCaseInsensitive: public dtl::Compare<string> {
public:
    virtual bool impl(const string& a, const string& b) const {
        if (a.length() == b.length()) {
            bool equal = (strncasecmp(a.c_str(), b.c_str(), a.length()) == 0);
            return equal;
        }
        else {
            return false;
        }
    }
};

#endif // DTL_COMPARATORS
