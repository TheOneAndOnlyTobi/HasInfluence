#include <algorithm>
#include <fstream>
#include <string>
#include <stdexcept>
#include <chrono>
#include <iostream>
#include <thread>
using namespace std;

#define USE_BUSY_SLEEPING

inline bool isFeatureEnabled(int argc, char *argv[], std::string FeatureName) {
    for (int CurrentArg = 1; CurrentArg < argc; ++CurrentArg) {
        if (argv[CurrentArg] == FeatureName) {
            return true;
        }
    }

    return false;
}

inline void busy_sleep_for_millisecs(unsigned Millisecs) {
    std::this_thread::sleep_for(std::chrono::milliseconds(Millisecs));
}

inline void sleep_for_millisecs(unsigned Millisecs) {
    std::cout << "Sleeping for " << Millisecs << " milliseconds" << std::endl;
#ifdef USE_BUSY_SLEEPING
    busy_sleep_for_millisecs(Millisecs);
#else
    std::this_thread::sleep_for(std::chrono::milliseconds(Millisecs));
#endif
}

int main(int argc, char *argv[])
{
    bool F1 = isFeatureEnabled(argc, argv, "--f1");
    bool F2 = isFeatureEnabled(argc, argv, "--f2");
    bool F3 = isFeatureEnabled(argc, argv, "--f3");

    if (argc < 1) {
        throw invalid_argument("Please specify a file");
    }
    string filename;
    for (int CurrentArg = 1; CurrentArg < argc; ++CurrentArg) {
        string argument;
        argument = argv[CurrentArg];
        if (argument.find(".txt") != std::string::npos) {
            filename = argument;
        }
    }

    ifstream inFile(filename);
    if (!inFile.good()) {
        throw invalid_argument("File " + filename + " could not be found");
    }
    const int lines = count(istreambuf_iterator<char>(inFile),
               istreambuf_iterator<char>(), '\n');

    if (lines % 3 == 0) {
        if (F1) {
            sleep_for_millisecs(375);
        }
        if (F2) {
            sleep_for_millisecs(275);
        }
        if (F3) {
            sleep_for_millisecs(185);
        }
        if (F1 && F2) {
            sleep_for_millisecs(421);
        }
        if (F1 && F2 || F3) {
            sleep_for_millisecs(267);
        }
        if (F1 || F2 || F3) {
            sleep_for_millisecs(180);
        }
        if (F1 || F2 && F3) {
            sleep_for_millisecs(264);
        }
    }
    if (lines % 2 == 0) {
        if (F1) {
            sleep_for_millisecs(250);
        }
        if (F2) {
            sleep_for_millisecs(123);
        }
        if (F3) {
            sleep_for_millisecs(321);
        }
        if (F1 && F2) {
            sleep_for_millisecs(140);
        }
        if (F1 && F2 || F3) {
            sleep_for_millisecs(247);
        }
        if (F1 || F2 || F3) {
            sleep_for_millisecs(362);
        }
        if (F1 || F2 && F3) {
            sleep_for_millisecs(126);
        }
    }

    if (lines % 2 != 0 && lines % 3 != 0) {
        if (F1) {
            sleep_for_millisecs(321);
        }
        if (F2) {
            sleep_for_millisecs(378);
        }
        if (F3) {
            sleep_for_millisecs(295);
        }
        if (F1 && F2) {
            sleep_for_millisecs(185);
        }
        if (F1 && F2 || F3) {
            sleep_for_millisecs(289);
        }
        if (F1 || F2 || F3) {
            sleep_for_millisecs(164);
        }
        if (F1 || F2 && F3) {
            sleep_for_millisecs(290);
        }
    }


    if (F1) {
        sleep_for_millisecs(200);
    }

    sleep_for_millisecs(111);

    if (F2) {
        sleep_for_millisecs(300);
    }

    sleep_for_millisecs(111);

    if (F3) {
        sleep_for_millisecs(400);
    }

    sleep_for_millisecs(111);

    if (F1 && F2) {
        sleep_for_millisecs(120);
    }

    sleep_for_millisecs(111);

    if (F1 || F2) {
        sleep_for_millisecs(210);
    }

    sleep_for_millisecs(111);

    if (F1 && F2 || F3) {
        sleep_for_millisecs(132);
    }

    sleep_for_millisecs(111);

    if (F1 || F2 && F3) {
        sleep_for_millisecs(213);
    }

    sleep_for_millisecs(111);

    if (F1 && F2 && F3) {
        sleep_for_millisecs(123);
    }

    sleep_for_millisecs(111);

    if (F1 || F2 || F3) {
        sleep_for_millisecs(321);
    }

    return 0;
}


