#pragma once
namespace Player
{
	std::string name	= "";
	std::string nick	= "";
	unsigned short age	= 0;
	enum NATIVECOUNTRY {PL, USA, GB, RU, HU, JP, FR, GER, CZ, ES, CN, MX, BR, NOR, SWE, null} kraj_pochodzenia = null;
}
namespace Game
{
	namespace Events
	{
		void Lose()
		{
			std::cout << "You lose...\n";
		}
	}
	namespace Quiz
	{
		char corr_ans = '\0';
		char user_ans = '\0';
		void Question(std::string q, std::string ans_A, std::string ans_B, std::string ans_C, std::string ans_D)
		{
			std::cout << q << "\nAnswers:\n\nA--" << ans_A << "\tB--" << ans_B << "\nC--" << ans_C << "\tD--" << ans_D << "\n\n";
		}
		void Answer(char correct_answer)
		{
			corr_ans = correct_answer;
			std::cin >> user_ans;
		}
	}
}
