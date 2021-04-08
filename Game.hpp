/**
* @file Game.hpp
* Made by Antoni Kiedos 
* This game engine was made accidentally because I wanted to do electronical version of polish quiz show "Milionerzy" and it was too much lines of code, so I bring it to the another file -- Game.hpp
* Version: 0.1.0-alpha+1
* Version name: "You lose this quiz!"
* I'd be happy, if you contribute to this game engine: https://github.com/ankiedos/Console-Game-Engine/pulls
*/

/**
* TO DO: Check if there are female verbs for "lose" in other languages
* TO DO: Extend Question() to other languages
*/

#pragma once
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<initializer_list>

#ifdef DEFINE_PLAYER
namespace Player
{
	std::string name			= "";
	std::string nick			= "";
	unsigned short age			= 0;
	enum class GENDER {null = 0, MALE, FEMALE};
	GENDER gender = GENDER::null; // null is to initialise the enum. Without initialisation the std::cin >> doesn't work properly
} // namespace Player
#endif
namespace Game
{
	// Language packages
	enum class GAMELANG { PL, USA, GB, RU, HU, JP, FR, GER, CZ, ES, CN, MX, BR, POR, NOR, SWE, GR, null };
	GAMELANG game_lang = GAMELANG::null;
	
	#ifdef _GLIBCXX_ARRAY
		std::array<GAMELANG, 17> langs = {PL, USA, GB, RU, HU, JP, FR, GER, CZ, ES, CN, MX, BR, POR, NOR, SWE, GR};
	#else
		GAMELANG langs[17]             = {PL, USA, GB, RU, HU, JP, FR, GER, CZ, ES, CN, MX, BR, POR, NOR, SWE, GR};
	#endif
	
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
				if(Player::gender == Player::GENDER::FEMALE) std::cout << "Przegralas...\n";
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
	} // namespace Game::Events

#ifdef DEFINE_QUIZ
	namespace Quiz
	{
		/// Correct answer
		char corr_ans = '\0';
		/// User's answer (it do not have to be the same with corr_ans, of course)
		char user_ans = '\0';

		/// Call this when you want to ask (there must be <= 4 answers)
		void Question(const std::string& q, const std::string& ans_A, const std::string& ans_B, const std::string& ans_C, const std::string& ans_D)
		{
			if(Game::game_lang == Game::GAMELANG::GB || Game::game_lang == Game::GAMELANG::USA || Game::game_lang == GAMELANG::CN)
			{
				std::cout << q << "\nAnswers:\n\nA--" << ans_A << "\tB--" << ans_B << "\nC--" << ans_C << "\tD--" << ans_D << "\n\n";
			}
			else if(Game::game_lang == Game::GAMELANG::PL)
			{
				std::cout << q << "\nOdpowiedzi:\n\nA--" << ans_A << "\tB--" << ans_B << "\nC--" << ans_C << "\tD--" << ans_D << "\n\n";
			}
			else if(Game::game_lang == Game::GAMELANG::MX || Game::game_lang == Game::GAMELANG::ES)
			{
				// TODO: Remove PLACEHOLDER with apropriate word
                #define PLACEHOLDER "REMOVE THIS PLACEHOLDER"
				std::cout << q << "\n" << PLACEHOLDER << ":\n\nA--" << ans_A << "\tB--" << ans_B << "\nC--" << ans_C << "\tD--" << ans_D << "\n\n";
			}
		}
		/// This is a shortcut for setting the correct answer and cinning it from user
		void Answer(const char& correct_answer)
		{
			corr_ans = correct_answer;
			std::cin >> user_ans;
		}
	} // namespace Game::Quiz
#endif
#ifdef DEFINE_RPG
    namespace RPG
    {
        #ifdef DEFINE_ITEMS
        namespace Items
        {
            struct Item
            {
                static double price;
                size_t quantity = 0;

                Item& operator +=(long long quantity) { Item::quantity += quantity; return *this; }
                Item& operator -=(long long quantity) { Item::quantity -= quantity; return *this; }
                Item& operator *=(long long quantity) { Item::quantity *= quantity; return *this; }
                Item& operator /=(long long quantity) { Item::quantity /= quantity; return *this; }
                Item operator +(long long quantity) { return Item(Item::price, this->quantity + quantity); }
                Item operator -(long long quantity) { return Item(Item::price, this->quantity - quantity); }
                Item operator *(long long quantity) { return Item(Item::price, this->quantity * quantity); }
                Item operator /(long long quantity) { return Item(Item::price, this->quantity / quantity); }
                Item() = default;
                explicit Item(const double& price, const size_t& quantity) { Item::price = price; this->quantity = quantity; }
                ~Item() = default;
            }; // struct Game::RPG::Items::Item
        } // namespace Game::RPG::Items
        #endif
        #ifdef DEFINE_CHARACTERS
        struct Person
        {
            void says(const std::string& what) { std::cout << this->name << ": " << what << "\n"; }
            std::string name;
			bool alive = true;

            #ifndef DEFINE_PLAYER
                enum GENDER {null = 0, MALE, FEMALE};
                GENDER gender;
            #else
                Player::GENDER gender;
            #endif

            std::map<std::string, Items::Item> items;
            friend Persons operator &(const Person& p1, const Person& p2) { return Persons(std::initializer_list{p1, p2}); }
            friend bool operator &&(const Person& p1, const Person& p2) { return p1.alive && p2.alive; }
			friend bool operator ||(const Person& p1, const Person& p2) { return p1.alive || p2.alive; }
			friend bool operator !(const Person& p) { return !p.alive; }
            Items::Item& operator [](const std::string& key) { return this->items[key]; }

            Person() = default;

            #ifndef DEFINE_PLAYER
                explicit Person(const std::string& name, const GENDER& gender) { this->name = name; this->gender = gender; characters += this; }
                explicit Person(std::string&& name, GENDER&& gender) { this->name = std::move(name); this->gender = std::move(gender); }
            #else
                explicit Person(const std::string& name, const Player::GENDER& gender) { this->name = name; this->gender = gender; characters += *this; }
                explicit Person(std::string&& name, Player::GENDER&& gender) { this->name = std::move(name); this->gender = std::move(gender); characters += *this; }
            #endif

            explicit Person(const Person& other) { this->name = other.name; this->gender = other.gender; characters += *this; }
            explicit Person(Person&& other) { Person(std::move(other)); }

            #ifndef DEFINE_PLAYER
                Person& operator =(const std::pair<std::string, GENDER>& name_gender) { *this = Person(name_gender.first, name_gender.second); }
                Person& operator =(std::pair<std::string, GENDER>&& name_gender) { *this = Person(name_gender.first, name_gender.second); }
            #else
                Person& operator =(const std::pair<std::string, Player::GENDER>& name_gender) { *this = Person(name_gender.first, name_gender.second); return *this; }
                Person& operator =(std::pair<std::string, Player::GENDER>&& name_gender) { *this = Person(name_gender.first, name_gender.second); }
            #endif

            Person& operator =(const Person& other) { *this = Person(other); }
            Person& operator =(Person&& other) { *this = Person(other); }
            ~Person() = default;
        }; // struct Game::RPG::Person
        #ifdef DEFINE_PLAYER
            Person player = Person(Player::nick, Player::gender);
        #else
            Person player;
        #endif
        Person tutor = Person("tutor", player.gender);
        struct Persons
        {
            void say(const std::string& what)
            {
                std::vector<std::string> people = std::vector<std::string>();
                for(auto& i : this->people) people.push_back(i.name);
                for(auto i = 0; i < people.size() - 1; i++) std::cout << people[i] << " and ";
                std::cout << people[people.size() - 1] << ": " << what << "\n";
            }
            std::vector<Person> people;

            Persons& operator +=(const Person& p) { this->people.push_back(p); return *this; }
            Persons& operator +=(Person&& p) { this->people.push_back(std::move(p)); return *this; }

            Persons() = default;
            explicit Persons(const std::initializer_list<Person>& p) { for(auto& i : p) this->people.push_back(i); }
            explicit Persons(std::initializer_list<Person>&& p) { for(auto& i : p) this->people.push_back(i); }
            explicit Persons(const Persons& other) { this->people = other.people; }
            explicit Persons(Persons&& other) {this->people = std::move(other.people); }
            Persons& operator =(const std::initializer_list<Person>& p) { *this = Persons(p); }
            Persons& operator =(std::initializer_list<Person>&& p) { *this = Persons(p); }
            Persons& operator =(const Persons& other) { *this = Persons(other); }
            Persons& operator =(Persons&& other) { *this = Persons(other); }
            ~Persons() = default;
        };
        Persons characters = Persons(std::initializer_list{player, tutor});
        #endif
    } // namespace Game::RPG
#endif
} // namespace Game
