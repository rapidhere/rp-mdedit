#include "dialect.h"

RNAMESPACE_START

_DialectRegister::_DialectRegister(const char* dname, Dialect* dialect) {
	rec[std::string(dname)] = dialect;
}

Dialect* _DialectRegister::getDialectByName(const char* name) {
	return rec[std::string(name)];
}

RNAMESPACE_END