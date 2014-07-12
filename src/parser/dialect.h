#ifndef DIALECT_H
#define DIALECT_H

#include "parserdefs.h"
#include <map>
#include <string>
#include <json/json.h>

RNAMESPACE_START

class Dialect;
class _DialectRegister;

/**
 * The base class of all dialects
 */
class Dialect {
protected:
	std::string text;
	int compileErrorCode;

public:
	/**
	 * Update(Append) texts to current text buffer
	 * @param text The text to append
	 */
	void update(const std::string& text);

	/**
	 * Clean the text buffer
	 */
	void clean();

	/**
	 * Compile the text buffer into json structer
	 * Note: please remove the Json Object by yourself
	 *
	 * If compile failed, return NULL, and you can get the
	 * Error code with getCompileError
	 * 
	 * @return the json object
	 */
	Json::Value *compile();

	/**
	 * get the compile error code
	 * @return the compile error code
	 */
	int getCompileError();

public:
	/**
	 * Get a dialect by its name
	 * @param  dialect_name the name of dialect to get
	 * @return              NULL if not found, or the dialect
	 */
	static Dialect *getDialectByName(const char* dialect_name);
};

/**
 * Register a dialect into dialect list
 * If a dialect has the same name has registered, will cover it
 * 
 * @param  dname    The name of this dialect
 * @param  pdialect A pointer to the dialect
 * @return          VOID
 */
#define REGISTER_DIALECT(dname, pdialect) \
	_DialectRegister* d = _DialectRegister(dname, pdialect); \
	delete d;

/**
 * This Pirvate class used to register the dialect
 * DON'T USE IT DIRECTLY
 */
class _DialectRegister {
private:
	/**
	 * The map used to store the dialect
	 */
	static std::map<std::string, Dialect*> rec;

public:
	/**
	 * Get a registerd dialect by it's name
	 * @param  dname dialect's name
	 * @return       NULL if not found, or the dialect
	 */
	static Dialect* getDialectByName(const char* dname);

public:
	/**
	 * Constructor
	 * DON'T USE IT DIRECTLY
	 */
	_DialectRegister(const char* dname, Dialect* dialect);
};

RNAMESPACE_END

#endif