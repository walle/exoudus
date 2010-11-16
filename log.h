#ifndef LOG_H
#define LOG_H

#include <string>
#include <iostream>
#include <fstream>
#include <stdarg.h>

using namespace std;

class cLog
{
	public:
        cLog();
        cLog(string file);
        ~cLog();
        
        bool init(string file);
        void write(const char *msg, ...);
    private:
    ofstream fout;
};

#endif
