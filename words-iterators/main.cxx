#include "../src/headers/pdf_scrapper.hpp"
#include <thread>
#include <chrono>

using namespace std;

void show_at_wpm( string input, short int wpm ) {
	vector<string> words;
	
	size_t space_loc = input.find(' ');
	while( space_loc != string::npos ) {
		string new_word = input.substr( 0, space_loc);
		input.erase(0, space_loc+1);
		
		words.push_back( new_word );
		space_loc = input.find(' ');
	}
	if( !input.empty())
		words.push_back( input );

	short int wps = wpm / 60;
	cout << "\033[2J\033[1;1H";
	for( auto i : words ) {
		cout << i << endl;
		std::this_thread::sleep_for( std::chrono::milliseconds( 1000 / wps ));
		cout << "\033[2J\033[1;1H";
	}
}

int main(int argc, char** argv ) {
	string filename = argv[1];

	PDF_SCRAPPER pdf_scrapper( filename );

	auto pdf_content_collection = pdf_scrapper.str_get_content();

	for( auto i : pdf_content_collection ) {
		// cout << i << endl;

		show_at_wpm( i.ConvertToUtf8(), 240 );
	}

	return 0;
}
