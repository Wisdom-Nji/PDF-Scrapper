#include "../src/headers/pdf_scrapper.hpp"
#include <ncurses.h>
#include <thread>
#include <chrono>

using namespace std;

WINDOW *create_newwin( int height, int width, int start_y, int start_x) {
	WINDOW *local_win;

	local_win = newwin( height, width, start_y, start_x);
	box(local_win, 0, 0);


	wrefresh( local_win );
	return local_win;
}

void show_at_wpm( string input, short int wpm, WINDOW* window ) {
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
		// cout << i << endl;
		mvwprintw(window, 0, 0, i.c_str());
		// wprintw("%s\n", i.c_str());
		wrefresh( window );
		std::this_thread::sleep_for( std::chrono::milliseconds( 1000 / wps ));
		// cout << "\033[2J\033[1;1H";
		// wprintw("\033[2J\033[1;1H");

	}
}

int main(int argc, char** argv ) {
	string filename = argv[1];

	PDF_SCRAPPER pdf_scrapper( filename );

	auto pdf_content_collection = pdf_scrapper.str_get_content();

	initscr();
	
	int height = LINES / 2, width = COLS / 2, start_y = 0, start_x = 0;
	refresh();
	WINDOW *w_wpm = create_newwin( height, width, start_y, start_x);
	for( auto i : pdf_content_collection ) {
		// cout << i << endl;

		show_at_wpm( i.ConvertToUtf8(), 240, w_wpm );
	}
	endwin();

	return 0;
}

