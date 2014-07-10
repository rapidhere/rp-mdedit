#ifndef DIALECT_H
#define DIALECT_H

#include "parserdefs.h"
#include <map>
#include <string>

RNAMESPACE_START

class Dialect {
};

#define REGISTER_DIALECT(dname, pdialect) \
	_DialectRegister* d = _DialectRegister(dname, pdialect); \
	delete d;

#define GET_DIALECT_BY_NAME(dname) \
	_DialectRegister::getDialectByName(dname);

class _DialectRegister {
private:
	static std::map<std::string, Dialect*> rec;

public:
	static Dialect* getDialectByName(const char* dname);

public:
	_DialectRegister(const char* dname, Dialect* dialect);
};

RNAMESPACE_END

#endif