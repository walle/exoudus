#include "log.h"

cLog::cLog()
{
	
}

cLog::cLog(string file)
{
	fout.open(file.c_str());
	if(!fout) 
	{
		cerr << "Couldn't initialize log: " << file << endl;
    }
}

cLog::~cLog()
{
	fout.close();
}

bool cLog::init(string file)
{
	fout.open(file.c_str());
	if(!fout) 
	{
		cerr << "Couldn't initialize log: " << file << endl;
		return false;
    }
    return true;
}

void cLog::write(const char *msg, ...)
{
	va_list args; va_start(args,msg);
	
	char szBuf[1024];
	vsprintf(szBuf,msg,args);
	
	fout<<szBuf;
  
	fout.flush();

	va_end(args);
}
