
#include <dtl/dtl.hpp>
#include "common.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;
using namespace dtl;

#if defined(BUILD_MONOLITHIC)
#define main    dtl_st2ses_example_main
#endif

int main(int argc, const char **argv){
    
    if (isFewArgs(argc, 2)) {
        cerr << "Too few arguments." << endl;
        return -1;
    }

    typedef string elem;
    typedef vector< string > sequence;

    string s(argv[1]);

    if (!isFileExist(s)) {
        cerr << s << " is invalid." << endl;
        return -1;
    }

    ifstream fs(s.c_str());
    const Ses< elem > ses = Diff< elem, sequence >::composeSesFromStream< ifstream >(fs);
    dtl::Diff< elem, sequence >::printSES(ses);
    
    return 0;
}
