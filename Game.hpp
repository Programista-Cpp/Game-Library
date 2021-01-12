/**
* @file Game.hpp
* Made by Antoni Kiedos (GitHub alias: ankiedos)
* This game engine was made accidentally because I want to do electronical version of polish quiz show "Milionerzy" and it was too much lines of code, so I bring it to the another file -- Game.hpp
* Version: 0.1.0-alpha
* Version name: "You lose this quiz!"
* You can contribute to this game engine: https://github.com/ankiedos/Game-Library/pulls
*/

/**
* TO DO: Check if there are female verbs for "lose" in other languages
* TO DO: Extend Question() to other languages
*/

#pragma once
namespace Player
{
	std::string name			= "";
	std::string nick			= "";
	unsigned short age			= 0;
	enum GENDER {MALE, FEMALE, null} gender = GENDER::null; // null is to initialise the enum. Without initialisation the std::cin >> doesn't work properly
} // namespace Player

namespace Game
{
	// Language packages
	enum GAMELANG { PL, USA, GB, RU, HU, JP, FR, GER, CZ, ES, CN, MX, BR, POR, NOR, SWE, GR, null } game_lang = GAMELANG::null;
	
	namespace Events // This use language packages
	{
		// Call this if player lost
		void Lose()
		{
			if((game_lang == GAMELANG::GB) || (game_lang == GAMELANG::USA) || (game_lang == GAMELANG::CN))
			{
				std::cout << "You lose...\n";
			}
			else if(game_lang == GAMELANG::PL)
			{
				if (Player::gender == Player::GENDER::FEMALE) std::cout << "Przegralas...\n";
				else std::cout << "Przegrales...\n";
			}
			else if((game_lang == GAMELANG::MX) || (game_lang == GAMELANG::ES))
			{
				std::cout << "Perdiste...\n";
			}
			else if(game_lang == GAMELANG::RU)
			{
				std::cout << "Ty proigrala...\n";
			}
			else if(game_lang == GAMELANG::GER)
			{
				std::cout << "Du hast verloren...\n";
			}
			else if(game_lang == GAMELANG::CZ)
			{
				std::cout << "Prohral jsi...\n";
			}
			else if(game_lang == GAMELANG::HU)
			{
				std::cout << "Vesztettel...\n";
			}
			else if(game_lang == GAMELANG::JP)
			{
				std::cout << "Anata ga maketa...\n";
			}
			else if(game_lang == GAMELANG::FR)
			{
				std::cout << "Tu as perdu...\n";
			}
			else if((game_lang == GAMELANG::POR) || (game_lang == GAMELANG::BR))
			{
				std::cout << "Voce perdeu...\n";
			}
			else if(game_lang == GAMELANG::NOR)
			{
				std::cout << "Du tapte...\n";
			}
			else if(game_lang == GAMELANG::SWE)
			{
				std::cout << "Du forlorade...\n";
			}
			else if(game_lang == GAMELANG::GR)
			{
				std::cout << "Echeis chasei...\n";
			}
		}
	} // namespace Events
	
	namespace Quiz
	{
		/// Correct answer
		char corr_ans = '\0';
		/// User's answer (it do not have to be the same with corr_ans, of course)
		char user_ans = '\0';

		/// Call this when you want to ask (there must be <=4 answers)
		void Question(std::string q, std::string ans_A, std::string ans_B, std::string ans_C, std::string ans_D)
		{
			std::cout << q << "\nAnswers:\n\nA--" << ans_A << "\tB--" << ans_B << "\nC--" << ans_C << "\tD--" << ans_D << "\n\n";
		}
		/// This is a shortcut for setting the correct answer and cinning it from user
		void Answer(char correct_answer)
		{
			corr_ans = correct_answer;
			std::cin >> user_ans;
		}
	} // namespace Quiz
} // namespace Game
