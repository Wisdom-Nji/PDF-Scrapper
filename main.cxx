#include <iostream>
#include <fstream>


using namespace std;


int main(int argc, char** argv) {
	// int num_bytes = atoi(argv[1]);

	// At 8, header is being read
	int num_bytes = 8;
	char* file_content = new char[1024];

	ifstream read_pdf_file;
	// read_pdf_file.open("text_classification_algorithms.pdf", ios::binary | ios::in );
	read_pdf_file.open("text_classification_algorithms.pdf", ios::in );
	read_pdf_file.read(file_content, num_bytes);
	read_pdf_file.close();

	cout << file_content << endl;
	return 0;
}
