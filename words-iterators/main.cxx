#include "../src/headers/pdf_scrapper.hpp"

using namespace std;


int main(int argc, char** argv ) {
	string filename = argv[1];

	PDF_SCRAPPER pdf_scrapper( filename );
}
