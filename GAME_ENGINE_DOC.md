# DOCS
## Namespace Player::
- `name`, type: `std::string`-- this is player's name
- `nick`, type: `std::string` -- this is player's nick
- `age`, type: `unsigned short` -- this is player's age
- `gender`, type: `enum GENDER` -- this is player's gender
- `GENDER`, type: `enum` -- values are:
    - `MALE`;
    - `FEMALE`;
    - `null`; (to initialise enum)

# Game::
- `gamelang`, type: `enum GAMELANG`-- this is player's native country
- `GAMELANG`, type:`enum` -- values are:
    - `PL` -- Poland;
    - `USA` -- The United States of America;
    - `GB` -- Great Britain;
    - `RU` -- Russia;
    - `HU` -- Hungary;
    - `JP` -- Japan;
    - `FR` -- France;
    - `GER` -- Germany;
    - `CZ` -- Czechia;
    - `ES` -- Spain;
    - `CN` -- Canada; 
    - `MX` -- Mexic;
    - `BR` -- Brazil;
    - `POR` -- Portugaly;
    - `NOR` -- Norway;
    - `SWE` -- Sweden;
    - `GR` -- Greek;
    - `null` -- To initialise enum;
## Events::
- ```C++
    void Lose()
  ```
checks what `gamelang` is setted and couts "You lose" in given language
## Quiz::
- ```C++
    void Question(const std::string& q, const std::string& ans_A, const std::string& ans_B, const std::string& ans_C, const std::string& ans_D)
  ```
couts question and answers

```C++
    Word1 word2 word3 word4 word5 ... wordN?
    Answers:

    A--ans_A    B--ans_B
    C--ans_C    D--ans_D
                                                   
    There will be couted text after Game::Quiz::Question() call
```

- ``` C++
    void Answer(const char& correct_answer)
  ```
this is shortcut for setting correct answer and cinning it
### Quiz usage example

```C++
    std::cin >> Player::name;
    std::cout << "Hello, " << Player::name;
    Question("Do you like apples?", "Yes", "No", "So-so", "I hate apples!");
    Answer('A');
    if(Game::Quiz::user_ans == 'B' || Game::Quiz::user_ans == 'C' || Game::Quiz::user_ans == 'D') Lose();
```
## RPG::
- `Person`, type: `struct` -- person structure
  - predefined:
    - `player`
    - `tutor`
- `Persons`, type: `struct` -- persons structure
  - predefined:
    - `characters`, initial value: {player, tutor}
### Items::
- `Item`, type: `struct` -- base struct for items
  - `price`, type: `static const double` -- price of an item
  - `quantity`, type: `size_t` -- quantity of items character has
  - operators:
  - `+=`
  - `+`
  - `-=`
  - `-`
  - `*=`
  - `*`
  - `/=`
  - `/`

# Modularity
To use Player namespace, define `DEFINE_PLAYER`
To use Game::Quiz namespace, define `DEFINE_QUIZ`
To use Game::RPG namespace, define `DEFINE_RPG`
To use Game::RPG::Items, define `DEFINE_ITEMS` and `DEFINE_RPG`
To use Game::RPG::Person and Game::RPG::Persons structures, define `DEFINE_CHARACTERS` and `DEFINE_RPG`
