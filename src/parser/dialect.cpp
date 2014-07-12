#include "dialect.h"

RNAMESPACE_START

_DialectRegister::_DialectRegister(const char* dname, Dialect* dialect) {
	rec[std::string(dname)] = dialect;
}

Dialect* _DialectRegister::getDialectByName(const char* name) {
	std::string sname = std::string(name);

	// Not found , return NULL
	if(rec.count(sname) == 0) {
		return NULL;
	}

	return rec[sname];
}

Dialect* Dialect::getDialectByName(const char* name) {
	return _DialectRegister::getDialectByName(name);
}

void Dialect::update(const std::string& t) {
	text.append(t);
}

void Dialect::clean() {
	text.clear();
}

Json::Value* Dialect::compile() {
	return NULL;
}

int Dialect::getCompileError() {
	return compileErrorCode;
}

RNAMESPACE_END