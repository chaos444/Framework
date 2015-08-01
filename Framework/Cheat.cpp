#include "Cheat.h"

void Test(TestClass* TestClass1 )
{
	TestClass1->TestInt = ProcessFunctions::ReadMemory<int>(0x41854B8);

}