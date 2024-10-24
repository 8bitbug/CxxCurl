#include "../../include/CxxCurl/CxxCurl.hpp"
#include <stdexcept>
#include <vector>

curl::curl(const std::string &url) { m_config["url"] = url; }

auto findConfigKey(
  const std::map<std::string, std::any> &m_config,
  const std::string &keyname
) -> bool {
  return m_config.find(keyname) != m_config.end();
}

void curl::addHeader(const std::string &header) {
  auto emplaceHeader = [&, this] {
    try {
      auto headers =
        std::any_cast<std::vector<std::string> &>(m_config["headers"]);
      headers.emplace_back(header);
    } catch (const std::bad_any_cast &error) {
      throw std::runtime_error("Bad any cast: " + std::string(error.what()));
    }
  };

  if (findConfigKey(m_config, "headers")) {
    emplaceHeader();
  } else {
    m_config["headers"] = std::vector<std::string>();
    emplaceHeader();
  }
}
