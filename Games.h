#pragma once
namespace Player
{
	std::string imie = "";
	//std::string nick = "";
	//unsigned short wiek = 0;
	//enum NATIVECOUNTRY {PL, USA, GB, RU, HU, JP, FR, GER, CZ, ES, CN, MX, BR, NOR, SWE, null} kraj_pochodzenia = null;
}
namespace Game
{
	namespace Events
	{
		void Lose()
		{
			if (Player::imie[Player::imie.size() - 1] == 'a') std::cout << "Niestety przegralas...\n";
			else std::cout << "Niestety przegrales...\n";
		}
	}
	namespace Quiz
	{
		char corr_ans = '\0';
		char user_ans = '\0';
		void Question(std::string q, std::string ans_A, std::string ans_B, std::string ans_C, std::string ans_D)
		{
			std::cout << q << "\nOdpowiedzi:\n\nA--" << ans_A << "\tB--" << ans_B << "\nC--" << ans_C << "\tD--" << ans_D << "\n\n";
		}
		void Answer(char correct_answer)
		{
			corr_ans = correct_answer;
			std::cin >> user_ans;
		}
	}
}