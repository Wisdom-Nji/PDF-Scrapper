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

		// Extract words one by one
		TextExtractor::Line line = txt.GetFirstLine();
		TextExtractor::Word word;

		for(; line.IsValid(); line=line.GetNextLine()) {
			for(word=line.GetFirstWord(); word.IsValid(); word=word.GetNextWord()) {
				cout << word.GetString() << endl;
			}
		}
	}
	catch( pdftron::Common::Exception& ex) {
		cout << ex.GetMessage() << endl;
	}
}
