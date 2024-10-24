#ifndef CXXCURL_HPP
#define CXXCURL_HPP

#include <any>
#include <map>
#include <string>

class curl { // NOLINT(readability-*)
public:
  explicit curl(const std::string &url);

  void addHeader(const std::string &header);
  /* void setUserAgent(const std::string &userAgent);
  void setTimeout(const int &milliseconds);
  void setConnectTimeout(const int &milliseconds);
  */

private:
  std::map<std::string, std::any> m_config;
};

#endif
