#include "boost/outcome.hpp"

namespace outcome = OUTCOME_V2_NAMESPACE;

outcome::result<int> convert(const std::string& str) noexcept;

