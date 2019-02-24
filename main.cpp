#include <iostream>
#include <map>
#include <string>
#include <random>
#include <array>

enum class Symbol { Shi, Fu, Mi };

struct Node
{
	Symbol symbol;

	std::map<Symbol, std::string> results;
};

std::string str_input()
{
	std::string input;
	std::cin >> input;

	return input;
}

Symbol get_corresponding_symbol(std::string const& symbol_str)
{
	std::map<std::string, Symbol> symbols_map;
	symbols_map.insert(std::pair<std::string, Symbol>{ "Shi", Symbol::Shi });
	symbols_map.insert(std::pair<std::string, Symbol>{ "Fu", Symbol::Fu });
	symbols_map.insert(std::pair<std::string, Symbol>{ "Mi", Symbol::Mi });

	return symbols_map[symbol_str];
}

std::string get_random_str_symbol()
{
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 2);

	std::array<std::string, 3> str_symbols{ "Shi", "Fu", "Mi" };

	return str_symbols[dist(rng)];
}

std::map<Symbol, Node> create_game_map()
{
	Node shi_node{ Symbol::Shi, std::map<Symbol, std::string>{
			std::pair<Symbol, std::string>{ Symbol::Shi, "No winner" },
			std::pair<Symbol, std::string>{ Symbol::Fu, "You loose" },
			std::pair<Symbol, std::string>{ Symbol::Mi, "You win" }
	} };

	Node fu_node{ Symbol::Shi, std::map<Symbol, std::string>{
			std::pair<Symbol, std::string>{ Symbol::Shi, "You win" },
			std::pair<Symbol, std::string>{ Symbol::Fu, "No winner" },
			std::pair<Symbol, std::string>{ Symbol::Mi, "You loose" }
	} };

	Node mi_node{ Symbol::Shi, std::map<Symbol, std::string>{
			std::pair<Symbol, std::string>{ Symbol::Shi, "You loose" },
			std::pair<Symbol, std::string>{ Symbol::Fu, "You win" },
			std::pair<Symbol, std::string>{ Symbol::Mi, "No winner" }
	} };

	return std::map<Symbol, Node>{
		std::pair<Symbol, Node>{Symbol::Shi, shi_node},
		std::pair<Symbol, Node>{Symbol::Fu, fu_node},
		std::pair<Symbol, Node>{Symbol::Mi, mi_node} };
}

int main()
{
	std::cout << "Wecome to the ShiFuMi club" << std::endl;
	std::cout << "Be ready to play !" << std::endl;
	std::cout << "Enter your symbols : ";

	std::string user_str_symbol{ str_input() };
	std::string ia_str_symbol{ get_random_str_symbol() };

	std::cout << "Shi - Fu - Mi !" << std::endl;
	std::cout << "You : " + user_str_symbol + " \tVS\t " + ia_str_symbol + " : IA" << std::endl;

	std::map<Symbol, Node> game_map{ create_game_map() };

	Symbol user_symbol{ get_corresponding_symbol(user_str_symbol) };
	Symbol ia_symbol{ get_corresponding_symbol(ia_str_symbol) };

	std::cout << game_map[user_symbol].results[ia_symbol] << std::endl;
}