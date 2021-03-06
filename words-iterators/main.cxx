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

vector<string> split_by_char( char _char, string input ) {
	vector<string> words;
	size_t space_loc = input.find(_char);
	while( space_loc != string::npos ) {
		string new_word = input.substr( 0, space_loc);
		input.erase(0, space_loc+1);
		
		words.push_back( new_word );
		space_loc = input.find(_char);
	}
	if( !input.empty())
		words.push_back( input );
	
	return words;
}


string remove_char( char _char, string input) {
	size_t space_loc = input.find(_char);
	while( space_loc != string::npos ) {
		input.erase(space_loc, 1);
		space_loc = input.find(_char);
	}
	return input;
}

string vec_to_string( char delimeter, vector<string> input ) {
	string output_string = "";
	for( auto i : input)
		output_string += i + delimeter;
	if( !output_string.empty())
		output_string.erase( output_string.size() -1, 1);
	return output_string;
}

void show_at_wpm( string input, short int wpm, WINDOW* window ) {
	// TODO: when words are longer than the box, they turn
	// to fuck shit up, try dynamically allocating more space
	// to the dimensions of the box based on how thngs are at
	// the current
	short int wps = wpm / 60;
	vector<string> words = split_by_char( '\n', input );
	input = vec_to_string( ' ', words);
	words = split_by_char( '\r', input );
	input = vec_to_string( ' ', words);
	words = split_by_char( ' ',  input);
	string previous_entry = "";
	for( auto i : words ) {
		// cout << i << endl;
		// i = remove_char( '\n', i);
		wmove( window, 10, 10 ); // getyx(win, y, x) then do the maths
		/* 
		TODO: will need a more dynamic function to remove the strings here
		for( int j=0;j<previous_entry.size();++j ) {
			wdelch( window );
			waddch( window, ' ');
			// mvwdelch( window, 10, 10);
			//mvwaddch( window, 10, 10+j, ' ');
		}
		*/

		wclrtoeol( window ); // Clears the lines
		waddstr( window, i.c_str());
		wattron( window, A_BOLD );
		// wattron( window, A_STANDOUT );
		// wprintw("%s\n", i.c_str());
		wrefresh( window );
		std::this_thread::sleep_for( std::chrono::milliseconds( 1000 / wps ));
		wstandend(window);
		previous_entry = i;
	}
}

string clean( string input ) {
	input = remove_char( '\n', input );
	input = remove_char( '\r', input );

	return input;
}

void show( WINDOW *window, string input ) {
	wmove( window, 1, 1 );
	input = clean( input );

	int height = 0;
	int width = 0;

	waddstr( window, input.c_str());
	wrefresh( window );
}

int main(int argc, char** argv ) {
	string filename = argv[1];

	PDF_SCRAPPER pdf_scrapper( filename );

	auto pdf_content_collection = pdf_scrapper.str_get_content();

	initscr();
	
	int height = LINES / 2, width = COLS, start_y = 0, start_x = 0;
	refresh();
	WINDOW *w_wpm = create_newwin( height, width, start_y, start_x);
	WINDOW *w_allcontent = create_newwin( height, width, start_y + height, start_x);
	
	for( auto i : pdf_content_collection ) {
		// cout << i << endl;

		show( w_allcontent, i.ConvertToUtf8());
		show_at_wpm( i.ConvertToUtf8(), 240, w_wpm );
	}
	endwin();

	return 0;
}

