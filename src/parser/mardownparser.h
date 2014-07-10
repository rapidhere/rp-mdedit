#ifndef MARKDOWNPARSER_H
#define MARKDOWNPARSER_H

#include "parserdefs.h"
#include "dialect.h"
#include "string"

RNAMESPACE_START

class MarkdownParser {
private:
    Dialect *dialect;

public:
    MarkdownParser();
    MarkdownParser(const char *dialectName);
    MarkdownParser(Dialect *dialect);
    
    void setDialect(const char *dialectName);
    void setDialect(Dialect* dialect);

    void update(const char* content);
    void update(const std::string& content);
};

RNAMESPACE_END

#endif