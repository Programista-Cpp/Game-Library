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

- `Player::native_country`
, type: `enum NATIVECOUNTRY`-- this is player's native country
- `Player::NATIVECOUNTRY`, type:`enum` -- values are:
    - `PL` -- Poland;
    - `USA` -- The United States of America;
    - `GB` -- Great Britain;
    - `RU` -- Russian Federation;
    - `HU` -- Hungary;
    - `JP` -- The Japanese Empire;
    - `FR` -- France;
    - `GER` -- Federal Republic of Germany;
    - `CZ` -- The Czech Republic;
    - `ES` -- Spain;
    - `CN` -- Canada; 
    - `MX` -- Mexic;
    - `BR` -- Brazil;
    - `POR` -- Portugaly;
    - `NOR` -- Norway;
    - `SWE` -- Sweden;
    - `null` -- To initialise enum;
# Game::
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
    Qestion word2 word3 word4 word5?
    Answers:

    A--ans_A    B--ans_B
    C--ans_C    D--ans_D
                                                   
    There will be couted text after Game::Quiz::Question() call
```

- `void Answer(char correct_answer)` -- this is shortcut for setting correct answer and checking it

# Example

```C++
    std::cin >> Player::name;
    std::cout << "Hello, " << Player::name;
    Question("Do you like apples?", "Yes", "No", "So-so", "I hate apples!");
    Answer('A');
    if(Game::Quiz::user_ans == 'B' || Game::Quiz::user_ans == 'C' || Game::Quiz::user_ans == 'D');
    Lose();
```
