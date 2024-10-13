#include "../../include/CxxCurl/CxxCurl.hpp"

#include <curl/easy.h>

auto curl::ok(void) -> curl::code { return CURLE_OK; }

void curl::easy::cleanup(std::unique_ptr<CURL> handle) {
  curl_easy_cleanup(handle.release());
}

auto curl::easy::init(void
) -> std::unique_ptr<CURL, decltype(&curl_easy_cleanup)> {
  return std::unique_ptr<CURL, decltype(&curl_easy_cleanup)>(
    curl_easy_init(),
    &curl_easy_cleanup
  );
}

template <typename T>
void curl::easy::opt(
  const std::unique_ptr<CURL> request,
  const curl::option option,
  T value
) {
  curl::code res = curl_easy_setopt(request, option, value);
  if (res != curl::ok()) {
    throw std::runtime_error(curl_easy_strerror(res));
  }
}

auto curl::global::init(long flags) -> curl::code {
  return curl_global_init(flags);
}
