/**
* \file
* \brief Header file with class description for finite-state machine.
*/
#ifndef FINITE_STATE_MACHINE_2017_TIMUR
#define FINITE_STATE_MACHINE_2017_TIMUR

#include <array>
#include <string>
#include <functional>
#include <vector>

namespace timur
{
	/**
	 * \brief Class for working with finite-state machine. 
	 * 
	 *	alphabet(+,a,b), 
	 *	\f[regex(+ba^+b^+b+)\f].
	 */
	class StateMachine
	{
	private:
		/**
		 * \brief Initializing a pointer to class methods(states).
		 */
		using States = void(timur::StateMachine::*)(const char signal);

		/**
		 * \brief A table containing pointers to class methods.
		 * 
		 * The current state number and signal are used as table indexes.
		 */
		std::array<std::array<States,3>,6> _fsmTable;

		/**
		 * \brief Current state number.
		 */
		ptrdiff_t _currentState;

		/**
		 * \brief The resulting array containing all the found substrings.
		 */
		std::vector<std::string> _allSubstring;

		/**
		 * \brief Variable for storing the current constituted substring.
		 */
		std::string _substring;

		/**
		 * \brief Actions to the transition to the first state.
		 * \param signal 
		 */
		void toState1(const char signal);

		/**
		 * \brief Actions to the transition to the second state.
		 * \param signal 
		 */
		void toState2(const char signal);

		/**
		 * \brief Actions to the transition to the third state.
		 * \param signal 
		 */
		void toState3(const char signal);

		/**
		 * \brief Actions to the transition to the fourth state.
		 * \param signal 
		 */
		void toState4(const char signal);

		/**
		 * \brief Actions to the transition to the fifth state.
		 * \param signal 
		 */
		void toState5(const char signal);

		/**
		 * \brief Actions to the transition to the sixth state.
		 * \param signal 
		 */
		void toState6(const char signal);

		/**
		 * \brief Actions to the transition to the seventh state.
		 * \param signal 
		 */
		void toState7(const char signal);

		/**
		 * \brief Actions to the transition to the undefined state.
		 * \param signal 
		 */
		void toUndefinedState(const char signal);

		/**
		 * \brief Translating received symbols in indexes
		 * \param[in] preSignal Character derived from string.
		 * \return An integer corresponding to this character.
		 */
		static size_t interpreter(const char preSignal);
	public:

		StateMachine();
		/**
		 * \brief Search in the input string of all substrings that satisfy the state machine.
		 * \param inputString The string in which you want to find substrings.
		 * \return Array containing all found substrings.
		 */
		std::vector<std::string>  findSubString(std::string inputString);

		~StateMachine();
	};
}

#endif