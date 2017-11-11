#include "FSM.h"
#include <string>
#include <iostream>

int main()
{
	timur::StateMachine machine;
	const std::string string = "+babb++baaabbbb+";
	auto tmp = machine.findSubString(string);
	for (int i = 0; i < tmp.size(); ++i) std::cout << tmp[i] << std::endl;
	system("pause");
	return 0;
}
