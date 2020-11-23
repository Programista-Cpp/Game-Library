/**
* @file Game.hpp
* Made by Antoni Kiedos (GitHub alias: Programista-Cpp)
* This game engine was made accidentally because I want to do electronical version of polish quiz show "Milionerzy" and it was too much lines of code, so I bring it to the another file -- Game.hpp
* Version: 0.1.0-alpha
* Version name: "You lose this quiz!"
* You can contribute to this game engine: https://github.com/Programista-Cpp/Game-Library/pulls
*/

/**
* TO DO: Check if there are the female verbs for "lose" in other languages
* TO DO: Extend Question() to other languages
*/

#pragma once
namespace Player
{
	std::string name			= "";
	std::string nick			= "";
	unsigned short age			= 0;
	enum GENDER {MALE, FEMALE, null} gender = GENDER::null; // null is to initialise the enum. Without initialisation the std::cin >> doesn't work properly
	// NATIVECOUNTRY is for language packages
	enum NATIVECOUNTRY { PL, USA, GB, RU, HU, JP, FR, GER, CZ, ES, CN, MX, BR, POR, NOR, SWE, null } native_country = NATIVECOUNTRY::null;
} // namespace Player

namespace Game
{
	namespace Events // This use language packages
	{
		// Call this if player lost
		void Lose()
		{
			if ((Player::native_country == Player::NATIVECOUNTRY::GB) || (Player::native_country == Player::NATIVECOUNTRY::USA) || (Player::native_country == Player::NATIVECOUNTRY::CN))
			{
				std::cout << "You lose...\n";
			}
			else if (Player::native_country == Player::NATIVECOUNTRY::PL)
			{
				if (Player::gender == Player::FEMALE) std::cout << "Niestety przegralas...\n";
				else std::cout << "Niestety przegrales...\n";
			}
			else if ((Player::native_country == Player::NATIVECOUNTRY::MX) || (Player::native_country == Player::NATIVECOUNTRY::ES))
			{
				std::cout << "Perdiste...\n";
			}
			else if (Player::native_country == Player::NATIVECOUNTRY::RU)
			{
				std::cout << "Ty proigrala...\n";
			}
			else if (Player::native_country == Player::NATIVECOUNTRY::GER)
			{
				std::cout << "Du hast verloren...\n";
			}
			else if (Player::native_country == Player::NATIVECOUNTRY::CZ)
			{
				std::cout << "Prohral jsi...\n";
			}
			else if (Player::native_country == Player::NATIVECOUNTRY::HU)
			{
				std::cout << "Vesztettel...\n";
			}
			else if (Player::native_country == Player::NATIVECOUNTRY::JP)
			{
				std::cout << "Anata ga maketa...\n";
			}
			else if (Player::native_country == Player::NATIVECOUNTRY::FR)
			{
				std::cout << "Tu as perdu...\n";
			}
			else if ((Player::native_country == Player::NATIVECOUNTRY::POR) || (Player::native_country == Player::NATIVECOUNTRY::BR))
			{
				std::cout << "Voce perdeu...\n";
			}
			else if (Player::native_country == Player::NATIVECOUNTRY::NOR)
			{
				std::cout << "Du tapte...\n";
			}
			else if (Player::native_country == Player::NATIVECOUNTRY::SWE)
			{
				std::cout << "Du forlorade...\n";
			}
		}
	}
	} // namespace Events
	namespace Quiz
	{
		/// Correct answer
		char corr_ans = '\0';
		
		/// User's answer (it do not have to be the same with corr_ans, of course)
		char user_ans = '\0';
		/// Cout this when you want to ask (there must be 4 answers)
		void Question(std::string q, std::string ans_A, std::string ans_B, std::string ans_C, std::string ans_D)
		{
			std::cout << q << "\nAnswers:\n\nA--" << ans_A << "\tB--" << ans_B << "\nC--" << ans_C << "\tD--" << ans_D << "\n\n";
		}
		/// This is a shortcut for setting the correct answer and cinning this from user
		void Answer(char correct_answer)
		{
			corr_ans = correct_answer;
			std::cin >> user_ans;
		}
	} // namespace Quiz
} // namespace Game
