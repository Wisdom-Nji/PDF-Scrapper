#include <iostream>
#include "PDFNetC64/Headers/PDF/PDFNet.h"
#include "PDFNetC64/Headers/PDF/PDFDoc.h"
#include "PDFNetC64/Headers/PDF/TextExtractor.h"

using namespace std;
using namespace pdftron;
using namespace PDF;


int main(int argc, char** argv) {
	PDFNet::Initialize();
	try {
		string pdf_filename = argv[1];
		PDFDoc doc(pdf_filename);
		doc.InitSecurityHandler();

		PageIterator itr;
		for( itr=doc.GetPageIterator(); itr.HasNext(); itr.Next()) {
			Page page = itr.Current();

			TextExtractor txt;
			txt.Begin( page );

			UString doc_content = txt.GetAsText();
			cout << doc_content << endl << endl;
		}

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
