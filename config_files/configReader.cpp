#include <fstream>
#include <iostream>
#include <C:\Users\Michael\Desktop\json.hpp>
#include <string>

using namespace std;

/*
This is the .cpp class. It is made to read the .json config file and retrieve values from it.
*/

class ConfigParser {
	nlohmann::json jsonstore;
	public:
		ConfigParser(char* filename);
		string get_category(char* categoryname);
};

ConfigParser::ConfigParser(char* filename) {
	ifstream configFile(filename);
	configFile >> jsonstore;
	configFile.close();
}


/*The config file should only have strings as the values. So anything that could be an
integer or a boolean should be expressed inside quotation marks "" in both the .cpp and the .json
*/

string ConfigParser::get_category(char* categoryname) {
	return (jsonstore.at(categoryname).get<std::string>());
}


/*
int main() {
	ConfigParser x = ConfigParser("example.json");

	
	ofstream log;
	log.open("log.txt");
	log << x.get_category("address");
	log.close();
}
*/