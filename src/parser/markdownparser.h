#ifndef MARKDOWNPARSER_H
#define MARKDOWNPARSER_H

#include "parserdefs.h"
#include "dialect.h"
#include "string"
#include <json/json.h>

RNAMESPACE_START

/**
 * The parser to parse markdown
 */
class MarkdownParser {
private:
    Dialect *dialect;
    std::string content;
    Json::Value *compileResult;

public:
	/**
	 *  Default Constructor: use Maruku as dialect
	 */
    MarkdownParser();

    /**
     * Specify a dialect by name
     */
    MarkdownParser(const char *dialectName);

    /**
     * Use th specified dialect
     */
    MarkdownParser(Dialect *dialect);
    
    /**
     * set the dialect to use by name
     * @param  dialectName the dialect name
     * @return             0 for success, others for error
     */
    int setDialect(const char *dialectName);

    /**
     * Set the dialect to use
     * @param dialect the dialect to use
     */
    void setDialect(Dialect* dialect);

    /**
     * update the content to parse
     * @param content the content
     */
    void update(const char* content);

    /**
     * update the content to parse
     * @param content the content
     */
    void update(const std::string& content);

    /**
     * Clear the content
     */
    void clear();

    /**
     * Compile the content
     * @return 0 on success, other for error
     */
    int compile();

    /**
     * get the compile result as json
     * NOTE: please release the json object after use
     * 
     * @return    the json object
     */
    Json::Value* asJson();
};

RNAMESPACE_END

#endif