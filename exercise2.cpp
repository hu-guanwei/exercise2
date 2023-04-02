#include <LuaCpp.hpp>
#include <iostream>
#include <memory>

using std::shared_ptr;
using LuaCpp::LuaContext;
using LuaCpp::Engine::LuaTString;
using LuaCpp::Engine::LuaTNumber;

int main() {

	auto my_name = std::make_shared<LuaTString>("Guanwei"); 
	int just_a_value = 42;
	auto value_ptr_to_lua = std::make_shared<LuaTNumber>(just_a_value);

	LuaContext lua;
	lua.AddGlobalVariable("my_name", my_name);
	lua.AddGlobalVariable("just_a_value", value_ptr_to_lua);

	try {
		// Print “[your name] says hello” from within Lua.
		lua.CompileStringAndRun(
			"print(string.format('[output from LuaContext] %s says hello', my_name))"
		);

		// Pass an int variable to Lua and print out the value in Lua
		lua.CompileStringAndRun(
			"print(string.format('[output from LuaContext] The integer value is: %i', just_a_value))"
		);

		// Change value of an int variable in Lua
		lua.CompileStringAndRun(
			"just_a_value = 3301; print(string.format('[output from LuaContext] The integer value is changed to: %i', just_a_value))"				
		);

		// Make the value changed in C++ 
		just_a_value = value_ptr_to_lua->getValue();
		// Print the changed value in C++
		std::cout << "[output from C++] The integer value is: "<< just_a_value << '\n';
	} catch (std::runtime_error& e) {
		std::cout << e.what() << '\n';
	}
}

