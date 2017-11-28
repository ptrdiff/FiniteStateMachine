#include "StateMachineTest.h"

void stateMachineTest::UnitTest1::baseTest1()
{
	const std::string string = "+bb+";
	auto tmp = _machine.findSubString(string);
	Assert::IsTrue(tmp.empty(),L"There are not substrings!");
}

void stateMachineTest::UnitTest1::baseTest2()
{
	const std::string string = "+babb+";
	auto tmp = _machine.findSubString(string);
	const std::string expectAnswers = "+babb+";
	Assert::AreEqual(expectAnswers, tmp[0], L"Wrong Answer!");
}

void stateMachineTest::UnitTest1::baseTest3()
{
	const std::string string = "+babb++baabbb+";
	auto tmp = _machine.findSubString(string);
	std::vector<std::string> expectAnswers = { "+babb+","+baabbb+" };
	Assert::AreEqual(expectAnswers[0], tmp[0], L"Wrong Answer!");
	Assert::AreEqual(expectAnswers[1], tmp[1], L"Wrong Answer!");
}

void stateMachineTest::UnitTest1::baseTest4()
{
	const std::string string = "+bbbaab+";
	auto tmp = _machine.findSubString(string);
	Assert::IsTrue(tmp.empty(), L"There are not substrings!");
}

void stateMachineTest::UnitTest1::baseTest5()
{
	const std::string string = "+babb+baabbb+";
	auto tmp = _machine.findSubString(string);
	std::vector<std::string> expectAnswers = { "+babb+","+baabbb+" };
	Assert::AreEqual(expectAnswers[0], tmp[0], L"Wrong Answer!");
	Assert::AreEqual(expectAnswers[1], tmp[1], L"Wrong Answer!");
}

void stateMachineTest::UnitTest1::baseTest6()
{
	const std::string string = "+baabbaab+";
	auto tmp = _machine.findSubString(string);
	Assert::IsTrue(tmp.empty(), L"There are not substrings!");
}

void stateMachineTest::UnitTest1::baseTest7()
{
	const std::string string = "+bbab+";
	auto tmp = _machine.findSubString(string);
	Assert::IsTrue(tmp.empty(), L"There are not substrings!");
}

void stateMachineTest::UnitTest1::baseTest8()
{
	const std::string string = "+bbgh+babb+";
	auto tmp = _machine.findSubString(string);
	const std::string expectAnswers = "+babb+";
	Assert::AreEqual(expectAnswers, tmp[0], L"Wrong Answer!");
}

void stateMachineTest::UnitTest1::baseTest9()
{
	const std::string string = "";
	auto tmp = _machine.findSubString(string);
	Assert::IsTrue(tmp.empty(), L"There are not substrings!");
}

void stateMachineTest::UnitTest1::baseTest10()
{
	const std::string string = "+baabb";
	auto tmp = _machine.findSubString(string);
	Assert::IsTrue(tmp.empty(), L"There are not substrings!");
}
