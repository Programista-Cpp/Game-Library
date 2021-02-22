# DOCS
## Namespace Player::
- `Player::name`, type: `std::string`-- this is player's name
- `Player::nick`, type: `std::string` -- this is player's nick
- `Player::age`, type: `unsigned short` -- this is player's age
- `Payer::gender`, type: `enum GENDER` -- this is player's gender
- `Player::GENDER`, type: `enum` -- values are:
    - `MALE`;
    - `FEMALE`;
    - `null`; (to initialise enum)

# Game::
- `Game::game_lang`, type: `enum Game::GAMELANG`-- this is player's native country
- `Game::GAMELANG`, type:`enum` -- values are:
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
checks what `native_country` is setted and couts "You lose" in given language
## Quiz::
- ```C++
    void Question(std::string q, std::string ans_A, std::string ans_B, std::string ans_C, std::string ans_D)
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
    void Answer(char correct_answer)
this is shortcut for setting correct answer and cinning it

# Example

```C++
    std::cin >> Player::name;
    std::cout << "Hello, " << Player::name;
    Question("Do you like apples?", "Yes", "No", "So-so", "I hate apples!");
    Answer('A');
    if(Game::Quiz::user_ans == 'B' || Game::Quiz::user_ans == 'C' || Game::Quiz::user_ans == 'D') Lose();
```
