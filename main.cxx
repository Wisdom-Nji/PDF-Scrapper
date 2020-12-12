#include <iostream>
#include "PDFNetC64/Headers/PDF/PDFNet.h"
#include "PDFNetC64/Headers/PDF/PDFDoc.h"
#include "PDFNetC64/Headers/PDF/PDFDraw.h"
#include "PDFNetC64/Headers/PDF/TextExtractor.h"

using namespace std;
using namespace pdftron;
using namespace PDF;


int main() {
	PDFNet::Initialize();
	try {
		PDFDoc doc("text_classification_algorithms.pdf");
		doc.InitSecurityHandler();

		Page page = doc.GetPage(1);

		TextExtractor txt;
		txt.Begin( page );


		UString doc_content = txt.GetAsText();
		cout << "Content: " << doc_content << endl;

		// Extract words one by one
		/*
		TextExtractor::Line line = txt.GetFirstLine();
		TextExtractor::Word word;

		UString text; 

		for(; line.IsValid(); line=line.GetNextLine()) {
			for(word=line.GetFirstWord(); word.IsValid(); word=word.GetNextWord()) {
				// cout << word.GetString() << endl;
				text.Assign(word.GetString(), word.GetStringLen());
				cout << text << endl;
			}
		}
		*/
	}
	catch( pdftron::Common::Exception& ex) {
		cout << ex.GetMessage() << endl;
	}
}
