#include <iostream>
#include "../../libs/PDFNetC64/Headers/PDF/PDFNet.h"
#include "../../libs/PDFNetC64/Headers/PDF/PDFDoc.h"
#include "../../libs/PDFNetC64/Headers/PDF/TextExtractor.h"

using namespace std;
using namespace pdftron;
using namespace PDF;

class PDF_SCRAPPER {
	string pdf_filename;
	public:
		PDF_SCRAPPER( string pdf_filename );
		vector<UString> str_get_content();
};


PDF_SCRAPPER::PDF_SCRAPPER( string pdf_filename ) {
	this->pdf_filename = pdf_filename;
}

vector<UString> PDF_SCRAPPER::str_get_content() {
	vector<UString> collectionContent;

	PDFNet::Initialize();
	PDFDoc doc(pdf_filename);
	doc.InitSecurityHandler();
	try {

		PageIterator itr;
		for( itr=doc.GetPageIterator(); itr.HasNext(); itr.Next()) {
			Page page = itr.Current();

			TextExtractor txt;
			txt.Begin( page );

			UString doc_content = txt.GetAsText();
			collectionContent.push_back( doc_content );
		}

	}
	catch( pdftron::Common::Exception& ex) {
		cout << ex.GetMessage() << endl;
	}

	return collectionContent;
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
