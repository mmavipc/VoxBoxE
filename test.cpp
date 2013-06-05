// VoxBoxE.cpp : Defines the entry point for the console application.
//
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>

#include "Engine\IEngine.h"

typedef void* (*CreateInterfaceFn)(const std::string &version);

#define CHECKNULL(a) if(a) \
std::cout << "OK!" << std::endl; \
else \
{ \
	std::cout << "Fail!"; \
	return -1; \
}

int main(int argc, char argv[])
{
	//Get Engine
	IEngine *engine = NULL;
	std::cout << "Retrieving engine dll...";
	HMODULE engineDll = LoadLibraryA("engine.dll");
	CHECKNULL(engineDll)
	std::cout << "Getting CreateInterfaceFn...";
	CreateInterfaceFn engInt = (CreateInterfaceFn)GetProcAddress(engineDll, "CreateInterface");
	CHECKNULL(engInt)
	std::cout << "Creating engine instance...";
	engine = (IEngine*)engInt(IENGINE_VERSION);
	CHECKNULL(engine)
	return 0;
}

