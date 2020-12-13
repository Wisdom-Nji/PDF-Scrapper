#include "../src/headers/pdf_scrapper.hpp"

using namespace std;


int main(int argc, char** argv ) {
	string filename = argv[1];

	PDF_SCRAPPER pdf_scrapper( filename );

	auto pdf_content_collection = pdf_scrapper.str_get_content();

	for( auto i : pdf_content_collection ) {
		cout << i << endl;
	}

	return 0;
}
