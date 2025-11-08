module;

#include <fmt/format.h>

export module error;

export template <typename... T>
[[nodiscard]] auto make_unexpected(fmt::format_string<T...> fmt_string, T &&...args)
{
	return fmt::format(fmt_string, std::forward<T>(args)...);
}
