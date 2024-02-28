#ifndef HTTP_METHODS_H
#define HTTP_METHODS_H

#include <string>

class HttpMethods {
public:
    static std::string httpGet(const std::string& url);
    static std::string httpPost(const std::string& url, const std::string& data);
};

#endif
