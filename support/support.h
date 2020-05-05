#ifndef HEAD_H
#define HEAD_H

// Headers.
#include <cstdlib>
#include <iostream>
#include <fstream>
 
// This is For OSX Support. That is because this
// project is on GitHub.
// This was a project that needs to be supported in 
// OSX. Now, This will give it Support.

struct macho_compiler_loader // Every struct in this file with a _support suffix.
{
	fstream mach_compiler_load_zip_file; // There Are Load Files To help The compiler Load The Files. They Are Stored in Zip Files.
	
	fstream mach_compiler_load_session_zip_file; // There Are Also Session Log Files So that you can get 
	// your history of compiler sessions. (In Zip Files, Too.
	
	mach_compiler_load_zip_file.open("mach_compiler_load.zip"); // Finally, The Zip File.
	
	mach_compiler_load_session_zip_file.open("mach_compiler_session_load.zip"); // Now, Finally, The Second Zip File.
	
	if(!mach_compiler_load_zip_file)
		mach_compiler_load_zip_file.open("mach_compiler_load.zip"); // We retry To Make The Load Zip File.
	else if(!mach_compiler_load_session_zip_file)
		mach_compiler_load_session_zip_file.open("mach_compiler_session_load.zip"); // We retry To Make The Session History Zip file.
	
	mach_compiler_load_zip_file << "PK"
		""
		""
		""; // we Leave It Empty Because, When You first use it, There Is No Loading, Yet.
	
	mach_compiler_load_session_zip_file << "PK"
		""
		""
		""; // We Also Leave it Empty, Because There Is No History, Yet.
	
	// (Both Files Are Read, And Whatever Contents They have By Reading It, They Get Sent To The Compiler.)
	// We Never Close the Files. They Are essential, And if You Delete Them, The Compiler Does Not Compile (What it Is Supposed to.)
	// Why We Need Session Log Files, Is So That When We Reopen a Compiler saved project, The Compiler Has To remember Everything.
	
	
};

struct portableexec_compiler_loader // If You Read The Comment At (Ln 16, Col 30), You Know What This Is.
{
	fstream portableexec_compiler_load_zip_file; 
	
	fstream portableexec_compiler_load_session_zip_file; 
	
	portableexec_compiler_load_zip_file.open("mach_compiler_load.zip"); // Finally, The Zip File.
	
	portableexec_compiler_load_session_zip_file.open("mach_compiler_session_load.zip"); 
	
	if(!portableexec_compiler_load_zip_file)
		mach_compiler_load_zip_file.open("mach_compiler_load.zip"); 
	else if(!portableexec_compiler_load_session_zip_file)
		mach_compiler_load_session_zip_file.open("mach_compiler_session_load.zip"); 
	
	portableexec_compiler_load_zip_file << "PK"
		""
		""
		""; 
	
	portableexec_compiler_load_session_zip_file << "PK"
		""
		""
		""; // We Also Leave it Empty, Because There Is No History, Yet.
}

struct macho_support
{
	std::uint32_t mach_header; // The header part 
	// of the Mach-O File to Tell the kernel it is a valid
	// Mach-O File.

	std::uint32_t mach_load_commands;  // The load commands.
	std::uint32_t mach_code; // Actual code in the Mach-O File.
	
	macho_compiler_loader machocomploader; // We Now Implemented The Mach-O Compiler Loader In.
};

struct portableexec_support
{
	std::uint32_t attribute_certificate; // attribute certificate reference:
	// A certificate that is used to associate
	// verifiable statements with an image. 
	// A number of different verifiable statements
	// can be associated with a file; one 
	// of the most useful ones is a statement by
	// a software manufacturer that indicates 
	// what the message digest of the image is 
	// expected to be. A message digest is
	// similar to a checksum except that it 
	// is extremely difficult to forge. Therefore, 
	// it is very difficult to modify a file to have
	// the same message digest as the original file. 
	// The statement can be verified as being made by 
	// the manufacturer by using public or private key 
	// cryptography schemes. This document describes 
	// details about attribute certificates other than to
	// allow for their insertion into image files. 

	std::uint32_t date_timestamp; // date/timestamp reference:
	// A stamp that is used for different purposes in 
	// several places in a PE or COFF file. In most 
	// cases, the format of each stamp is the same as 
	// that used by the time functions in the C run-time 
	//library. For exceptions, see the descripton of 
	// IMAGE_DEBUG_TYPE_REPRO in Debug Type. If the stamp 
	// value is 0 or 0xFFFFFFFF, it does not represent a 
	// real or meaningful date/time stamp. 

	std::uint32_t file_pointer; // file pointer reference:
	// The location of an item within the file itself, before
	// being processed by the linker (in the case of object files)
	// or the loader (in the case of image files). In other words,
	// this is a position within the file as stored on disk. 

	std::uint32_t linker; // linker reference:
	// A reference to the linker that is provided with
	// Microsoft Visual Studio. 

	std::uint32_t object_file; // object file reference:
	// A file that is given as input to the linker. The linker
	// produces an image file, which in turn is used as input
	// by the loader. The term "object file" does not necessarily
	// imply any connection to object-oriented programming. 

	std::uint32_t reserved_must_be_0; // reserved, must be 0 reference:
	// A description of a field that indicates that the value of the field
	// must be zero for generators and consumers must ignore the field. 

	std::uint32_t rva; // RVA reference: 
	// Relative virtual address. In an
	// image file, the address of an item
	// after it is loaded into memory, with
	// the base address of the image file
	// subtracted from it. The RVA of an
	// item almost always differs from its
	// position within the file on disk
	// (file pointer). In an object file,
	// an RVA is less meaningful because
	// memory locations are not assigned. 
	// In this case, an RVA would be an
	// address within a section (described
	// later in this table), to which a
	// relocation is later applied during
	// linking. For simplicity, a compiler
	// should just set the first RVA in
	// each section to zero. 

	std::uint32_t section = 0x0; // section  reference:
	// The basic unit of code or data within a PE or
	// COFF file. For example, all code in an object
	// file can be combined within a single section
	// or (depending on compiler behavior) each
	// function can occupy its own section. With
	// more sections, there is more file overhead,
	// but the linker is able to link in code more
	// selectively. A section is similar to a segment
	// in Intel 8086 architecture. All the raw data in
	// a section must be loaded contiguously. In
	// addition, an image file can contain a number of
	// sections, such as .tls or .reloc , which have special purposes. 
	
	portableexec_compiler_loader portableexec_compiler_loader; // Finally, The Compiler Loader (For PE-Formatted, In Which, Is for Windows.)
	
	// (all references come from https://docs.microsoft.com/en-us/windows/win32/debug/pe-format.)
};

#endif
