#pragma once
#include "CppUnitTest.h"
#include "../StateMachine/FSM.h"
// ReSharper disable CppUnusedIncludeDirective
#include "../StateMachine/FSM.cpp"
// ReSharper restore CppUnusedIncludeDirective


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace stateMachineTest
{
	TEST_CLASS(UnitTest1)
	{
	private:
		timur::StateMachine _machine;
	public:

		TEST_METHOD(baseTest1);
		TEST_METHOD(baseTest2);
		TEST_METHOD(baseTest3);
		TEST_METHOD(baseTest4);
		TEST_METHOD(baseTest5);
		TEST_METHOD(baseTest6);
		TEST_METHOD(baseTest7);
		TEST_METHOD(baseTest8);
		TEST_METHOD(baseTest9);
		TEST_METHOD(baseTest10);
	};
}