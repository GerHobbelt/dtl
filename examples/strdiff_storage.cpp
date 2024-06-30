#include <dtl/dtl.hpp>
#include "common.hpp"
#include <iostream>
#include <string>

#include "storage.hpp"

using namespace std;

using dtl::Diff;

#if defined(BUILD_MONOLITHIC)
#define main    dtl_strdiff_storage_example_main
#endif

int main(int argc, const char **argv){
    
    if (isFewArgs(argc)) {
        cerr << "Too few arguments." << endl;
        return -1;
    }
    
    typedef char   elem;
    typedef string sequence;

    sequence A(argv[1]);
    sequence B(argv[2]);
    
    Diff< elem, sequence > d(A, B);
    d.compose();
    
    // Shortest Edit Script
    cout << "SES" << endl;

    string result;

    d.storeSES < string, CustomStorage > (result);

    cout << result;
    
    return 0;
}
