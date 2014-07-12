#include "markdownparser.h"

RNAMESPACE_START

MarkdownParser::MarkdownParser() {
	MarkdownParser("Maruku");
}

MarkdownParser::MarkdownParser(const char* name) {
	if(setDialect(name)) {
		MarkdownParser((Dialect*)NULL);
	}
}

MarkdownParser::MarkdownParser(Dialect* dialect):
	compileResult(NULL) {
	setDialect(dialect);
}

int MarkdownParser::setDialect(const char* name) {
	Dialect* d = Dialect::getDialectByName(name);

	if(d == NULL) {
		return MD_PARSER_UNKOWN_DIALECT;
	}

	dialect = d;
	return 0;
}

void MarkdownParser::setDialect(Dialect* dialect) {
	this->dialect = dialect;
}

void MarkdownParser::update(const char* content) {
	this->content.append(content);
}

void MarkdownParser::update(const std::string& content) {
	this->content.append(content);
}

void MarkdownParser::clear() {
	this->content.clear();
}

int MarkdownParser::compile() {
	if(compileResult) {
		delete compileResult;
		compileResult = NULL;
	}

	compileResult = dialect->compile();

	if(! compileResult) {
		return dialect->getCompileError();
	}

	return 0;
}

Json::Value *MarkdownParser::asJson() {
	Json::Value *r = compileResult;
	compileResult = NULL;

	return r;
}

RNAMESPACE_END