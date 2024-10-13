#ifndef CXXCURL_CXXCURL_HPP
#define CXXCURL_CXXCURL_HPP

#include <curl/curl.h>

#include <memory>

namespace curl {
using code = CURLcode;
using option = CURLoption;
auto ok(void) -> curl::code;
namespace easy {
void cleanup(std::unique_ptr<CURL> handle);
auto init(void) -> std::unique_ptr<CURL, decltype(&curl_easy_cleanup)>;
template <typename T>
void opt(
  const std::unique_ptr<CURL> request,
  const curl::option option,
  T value
);
} // namespace easy
namespace global {
auto init(long flags) -> curl::code;
}
namespace opt {
const curl::option url = CURLOPT_URL;
}
} // namespace curl

#endif
