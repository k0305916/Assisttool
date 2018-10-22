#include <iostream>
#include <variant>
#include <string>
#include <optional>
#include <string_view>

struct STOutput
{
	template <typename T>
	void operator()(const T &v)
	{
		std::cout << v << std::endl;
	}
};

std::optional<int> parse_int(const std::string &s)
{
	int result;
	//....
	auto isSuccess = true;
	if (isSuccess)
	{
		return result;
	}
	return {};
}

int main()
{
#pragma region variant
// std::variant<int, std::string> u("hello world");
// //It is avoid.
// //valid when  change to u.index()
// //std::cout << u; // output: hello world

// // std::visit(STOutput(), u);
// u = 13;
// //This is better way.
// std::visit(
// 	[](const auto &v) { std::cout << v << std::endl; },
// 	u);
#pragma endregion

#pragma region optional
	// std::cout << "result is: " << parse_int("123456").value_or("invalid paramter") << '\n';
	// std::cout << "result is: " << parse_int("dwafawf").value_or("invalid paramter") << '\n';

	// if (auto result = parse_int("5643"))
	// {
	// 	std::cout << "result is: " << *result << '\n';
	// }
#pragma endregion

	std::string str{"   trim me"};
	std::string_view v{str};
	std::cout << v;
	getchar();
	return 0;
}