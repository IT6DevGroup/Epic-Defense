#ifndef LOG_H
#define LOG_H

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

#define STRING_LENGTH	1024

class LOG
{
public:
	static LOG &GetInstance ();
	void WriteStringToLog (char *fmt, ...);

protected:

private:
	FILE *log_file;

	LOG ();
	~LOG ();

	LOG (const LOG& root);
	LOG& operator = (const LOG&);
};

#endif