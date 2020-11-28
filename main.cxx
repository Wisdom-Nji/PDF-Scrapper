#include <iostream>
#include <fstream>


using namespace std;


int main() {
	char file_content;
	ifstream read_pdf_file;
	read_pdf_file.open("text_classification_algorithms.pdf", ios::binary | ios::in );
	read_pdf_file.read(&file_content, 7);

	cout << file_content << endl;

	return 0;
}
