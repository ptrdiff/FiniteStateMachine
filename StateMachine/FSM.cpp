#include "FSM.h"
#include <iostream>

timur::StateMachine::StateMachine()
{
	_fsmTable = { {
		{&StateMachine::toState2,			&StateMachine::toUndefinedState,	&StateMachine::toUndefinedState},
		{&StateMachine::toUndefinedState,	&StateMachine::toUndefinedState,	&StateMachine::toState3},
		{&StateMachine::toUndefinedState,	&StateMachine::toState4,			&StateMachine::toUndefinedState},
		{&StateMachine::toUndefinedState,	&StateMachine::toState4,			&StateMachine::toState5},
		{&StateMachine::toUndefinedState,	&StateMachine::toUndefinedState,	&StateMachine::toState6},
		{&StateMachine::toState7,			&StateMachine::toUndefinedState,	&StateMachine::toState6}
	} };
	_currentState = 0;
}

timur::StateMachine::~StateMachine()
{
}

unsigned int timur::StateMachine::interpreter(const char preSignal)
{
	switch (preSignal)
	{
		case '+': return 0;
		case 'a': return 1;
		case 'b': return 2;
		default: throw preSignal;
	}
}

std::vector<std::string> timur::StateMachine::findSubString(std::string inputString)
{
	for (int i = 0; i < inputString.size(); ++i)
	{
		for (int j = i; j < inputString.size(); ++j)
		{
			try
			{
				(this ->* _fsmTable[_currentState][interpreter(inputString[j])])(inputString[j]);
			}
			catch (const char error)
			{
				std::cout << "Error: " << error << " - unknown symbol." <<std::endl;
				_substring.clear();
				_currentState = 0;
			}
			if (_currentState == -1 || _currentState == 6)
			{
				_currentState = 0;
				break;
			}
		}
	}
	return _allSubstring;
}


void timur::StateMachine::toState1(const char signal)
{
	_currentState = 0;
}

void timur::StateMachine::toState2(const char signal)
{
	_currentState = 1;
	_substring.push_back(signal);
}

void timur::StateMachine::toState3(const char signal)
{
	_currentState = 2;
	_substring.push_back(signal);
}

void timur::StateMachine::toState4(const char signal)
{
	_currentState = 3;
	_substring.push_back(signal);
}

void timur::StateMachine::toState5(const char signal)
{
	_currentState = 4;
	_substring.push_back(signal);
}

void timur::StateMachine::toState6(const char signal)
{
	_currentState = 5;
	_substring.push_back(signal);
}

void timur::StateMachine::toState7(const char signal)
{
	_currentState = 6;
	_substring.push_back(signal);
	_allSubstring.push_back(_substring);
	_substring.clear();
}

void timur::StateMachine::toUndefinedState(const char signal)
{
	_currentState = -1;
	_substring.clear();
}
