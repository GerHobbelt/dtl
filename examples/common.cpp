
#include "common.hpp"

bool isFileExist (const std::string& fs) {
    FILE *fp;
    if ((fp = fopen(fs.c_str(), "r")) == nullptr) {
        return false;
    }
    fclose(fp);
    return true;
}

bool isFewArgs (int argc, int limit) {
    bool ret = false;
    if (argc < limit) {
        ret = true;
    }
    return ret;
}

