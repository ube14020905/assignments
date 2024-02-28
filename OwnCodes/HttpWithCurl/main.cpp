#include "httpmethods.h"
#include <iostream>

int main() {
    std::string getUrl = "https://jsonplaceholder.typicode.com/posts/1";
    std::string postUrl = "https://jsonplaceholder.typicode.com/posts";
    std::string postData = R"({"title": "foo","body": "bar","userId": 1})";

    std::cout << "HTTP GET Response: " << HttpMethods::httpGet(getUrl) << std::endl;
    std::cout << "HTTP POST Response: " << HttpMethods::httpPost(postUrl, postData) << std::endl;

    return 0;
}   