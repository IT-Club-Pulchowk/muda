#pragma once
#include "zBase.h"

typedef enum File_Attribute {
	File_Attribute_Archive = 0x1,
	File_Attribute_Compressed = 0x2,
	File_Attribute_Directory = 0x4,
	File_Attribute_Encrypted = 0x8,
	File_Attribute_Hidden = 0x10,
	File_Attribute_Normal = 0x20,
	File_Attribute_Offline = 0x40,
	File_Attribute_Read_Only = 0x80,
	File_Attribute_System = 0x100,
	File_Attribute_Temporary = 0x200,
} File_Attribute;

typedef struct File_Info {
	Uint64 CreationTime;
	Uint64 LastAccessTime;
	Uint64 LastWriteTime;
	Uint64 Size;
	Uint32 Atribute;
	String Path;
	String Name;
} File_Info;

typedef enum Directory_Iteration {
	Directory_Iteration_Continue,
	Directory_Iteration_Recurse,
	Directory_Iteration_Break
} Directory_Iteration;

typedef Directory_Iteration(*Directory_Iterator)(const File_Info *info, void *user_context);

INLINE_PROCEDURE Directory_Iteration DirectoryIteratorPrint(const File_Info *info, void *user_context) {
	LogInfo("%s - %zu bytes\n", info->Path, info->Size);
	return Directory_Iteration_Recurse;
}

bool IterateDirectroy(const char *path, Directory_Iterator iterator, void *context);

typedef enum Compiler_Kind {
	Compiler_Kind_NULL,

	Compiler_Kind_CL,
	Compiler_Kind_CLANG,
	Compiler_Kind_GCC,
} Compiler_Kind;

Compiler_Kind DetectCompiler();

enum {
	Path_Exist_Directory,
	Path_Exist_File,
	Path_Does_Not_Exist
};

bool LaunchCompilation(Compiler_Kind compiler, String cmdline);
Uint32 CheckIfPathExists(String path);
bool CreateDirectoryRecursively(String path);

String GetGlobalConfigurationFile();

String GetCommandLineArgumentString(int argc, char *argv[]);
