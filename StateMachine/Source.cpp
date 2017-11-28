#include "FSM.h"
#include <string>
#include <iostream>

int main()
{
	timur::StateMachine machine;

	std::cout << "Write input string: ";
	std::string string = "+babb++baaabbbb+";
	std::cin >> string; std::cout << '\n';

	auto tmp = machine.findSubString(string);
	for (int i = 0; i < tmp.size(); ++i) std::cout << tmp[i] << '\n';

	std::getchar();
	return 0;
}
