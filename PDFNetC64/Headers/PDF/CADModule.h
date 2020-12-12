//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
// !Warning! This file is autogenerated, modify the .codegen file, not this one
// (any changes here will be wiped out during the autogen process)

#ifndef PDFTRON_H_CPPPDFCADModule
#define PDFTRON_H_CPPPDFCADModule
#include <C/PDF/TRN_CADModule.h>

#include <Common/BasicTypes.h>
#include <Common/UString.h>
#include <PDF/PDFDoc.h>

namespace pdftron { namespace PDF { 
class PDFDoc;

/**
 * The class CADModule.
 * static interface to PDFTron SDKs CAD functionality
 */
class CADModule
{
public:
	
	//methods:
	
	/**
	 * Find out whether the CAD module is available (and licensed).
	 * 
	 * @return returns true if CAD operations can be performed.
	 */
	static bool IsModuleAvailable();

};

#include <Impl/CADModule.inl>
} //end pdftron
} //end PDF


#endif //PDFTRON_H_CPPPDFCADModule