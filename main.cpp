#include <algorithm>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

#define USE_BUSY_SLEEPING
#include "include/fp_util/feature_cmd.h"
#include "include/fp_util/sleep.h"

int main(int argc, char *argv[])
{
    bool __attribute__((feature_variable("feature_1"))) F1 =
    fp_util::isFeatureEnabled(argc, argv, "--f1");
    bool __attribute__((feature_variable("feature_2"))) F2 =
        fp_util::isFeatureEnabled(argc, argv, "--f2");
    bool __attribute__((feature_variable("feature_3"))) F3 =
        fp_util::isFeatureEnabled(argc, argv, "--f3");

    if (argc < 1) {
        throw invalid_argument("Please specify a file");
    }
    string filename = argv[argc-1];

    ifstream inFile(filename);
    if (!inFile.good()) {
        throw invalid_argument("File " + filename + " could not be found");
    }
    const int lines = count(istreambuf_iterator<char>(inFile),
               istreambuf_iterator<char>(), '\n');

    if (lines % 3 == 0) {
        if (F1) {
            fp_util::sleep_for_millisecs(375);
        }
        if (F2) {
            fp_util::sleep_for_millisecs(275);
        }
        if (F3) {
            fp_util::sleep_for_millisecs(185);
        }
        if (F1 && F2) {
            fp_util::sleep_for_millisecs(421);
        }
        if (F1 && F2 || F3) {
            fp_util::sleep_for_millisecs(267);
        }
        if (F1 || F2 || F3) {
            fp_util::sleep_for_millisecs(180);
        }
        if (F1 || F2 && F3) {
            fp_util::sleep_for_millisecs(264);
        }
    }
    if (lines % 2 == 0) {
        if (F1) {
            fp_util::sleep_for_millisecs(250);
        }
        if (F2) {
            fp_util::sleep_for_millisecs(123);
        }
        if (F3) {
            fp_util::sleep_for_millisecs(321);
        }
        if (F1 && F2) {
            fp_util::sleep_for_millisecs(140);
        }
        if (F1 && F2 || F3) {
            fp_util::sleep_for_millisecs(247);
        }
        if (F1 || F2 || F3) {
            fp_util::sleep_for_millisecs(362);
        }
        if (F1 || F2 && F3) {
            fp_util::sleep_for_millisecs(126);
        }
    }

    if (lines % 2 != 0 && lines % 3 != 0) {
        if (F1) {
            fp_util::sleep_for_millisecs(321);
        }
        if (F2) {
            fp_util::sleep_for_millisecs(378);
        }
        if (F3) {
            fp_util::sleep_for_millisecs(295);
        }
        if (F1 && F2) {
            fp_util::sleep_for_millisecs(185);
        }
        if (F1 && F2 || F3) {
            fp_util::sleep_for_millisecs(289);
        }
        if (F1 || F2 || F3) {
            fp_util::sleep_for_millisecs(164);
        }
        if (F1 || F2 && F3) {
            fp_util::sleep_for_millisecs(290);
        }
    }


    if (F1) {
        fp_util::sleep_for_millisecs(200);
    }

    fp_util::sleep_for_millisecs(111);

    if (F2) {
        fp_util::sleep_for_millisecs(300);
    }

    fp_util::sleep_for_millisecs(111);

    if (F3) {
        fp_util::sleep_for_millisecs(400);
    }

    fp_util::sleep_for_millisecs(111);

    if (F1 && F2) {
        fp_util::sleep_for_millisecs(120);
    }

    fp_util::sleep_for_millisecs(111);

    if (F1 || F2) {
        fp_util::sleep_for_millisecs(210);
    }

    fp_util::sleep_for_millisecs(111);

    if (F1 && F2 || F3) {
        fp_util::sleep_for_millisecs(132);
    }

    fp_util::sleep_for_millisecs(111);

    if (F1 || F2 && F3) {
        fp_util::sleep_for_millisecs(213);
    }

    fp_util::sleep_for_millisecs(111);

    if (F1 && F2 && F3) {
        fp_util::sleep_for_millisecs(123);
    }

    fp_util::sleep_for_millisecs(111);

    if (F1 || F2 || F3) {
        fp_util::sleep_for_millisecs(321);
    }

    return 0;
}


