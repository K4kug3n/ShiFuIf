#include <iostream>

#include <map>
#include <string>
#include <random>
#include <array>

std::string str_input()
{
	std::string input;
	std::cin >> input;

	return input;
}


Symbol get_corresponding_int(std::string const& symbol_str, std::map<std::string, int> const& corrsponding_map)
{
	return corrsponding_map[symbol_str];

}

std::string get_random_str_symbol()
{
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 2);

	std::array<std::string, 3> str_symbols{ "Shi", "Fu", "Mi" };

	return str_symbols[dist(rng)];
}


std::map<std::string, int> get_symbol_corresponding_map()
{
	std::map<std::string, int> corresponding_map;
	corresponding_map.insert( { "Shi", 0 } );
	corresponding_map.insert( { "Fu", 1 } );
	corresponding_map.insert( { "Mi", 2 } );

	return corresponding_map;
}

std::array<std::array<int, 3>, 3> create_game_graph()
{
	return std::array<std::array<int, 3>, 3>{ //0:Draw, 1:Win, 2:Loose 
		std::array<int, 3>{ 0, 2, 1 }, //Shi 
		std::array<int, 3>{ 1, 0, 2 }, //Fu
		std::array<int, 3>{ 2, 1, 0 }  //Mi	
	};
}

std::map<int, std::string> get_corresponding_int_map()
{
	std::map<int, std::string> corresponding_map;
	corresponding_map.insert( { 0, "Draw" } );
	corresponding_map.insert( { 1, "Win" } );
	corresponding_map.insert( { 2, "Loose" } );

	return corresponding_map;



int main()
{
	std::cout << "Wecome to the ShiFuMi club" << std::endl;
	std::cout << "Be ready to play !" << std::endl;
	std::cout << "Enter your symbols : ";

	std::string user_str_symbol{ str_input() };
	std::string ia_str_symbol{ get_random_str_symbol() };

	std::cout << "Shi - Fu - Mi !" << std::endl;
	std::cout << "You : " + user_str_symbol + " \tVS\t " + ia_str_symbol + " : IA" << std::endl;

	std::array<std::array<int, 3>, 3> game_graph{ create_game_graph() };

	std::map<std::string, int> corresponding_symbol_map{ get_symbol_corresponding_map() };

	int user_int{ get_corresponding_int(user_str_symbol) };
	int ia_int{ get_corresponding_int(ia_str_symbol) };

	std::cout << get_corresponding_int_map[ game_graph[user_int][ia_int] ] << std::endl;

	return 0;

}
