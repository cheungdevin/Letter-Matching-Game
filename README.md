# Letter-Matching-Game
C++ console game - Matching same letter to clean the game board.
* Reviewing basic C++ knowlage.
* Learning how to write my first ReadMe file.
## 
## Rules

The game board has default of 8*8 pieces. Each piece has two sizes: one side has a number refering the HP, and the other side has a letter.

The player can select two pieces each round. If the selected pieces are same letter, it will be removed. Otherwise the HP of selected pieces will be decreased by one.

If the HP of any piece dropped to 0, the player loses.

Default Setting: 
* board size: 8*8
* HP: 5, A-F random 
* Letter Range: A-F

It can be change in settings.

## Game Flow

#### Main Menu
```sh
*** Main Menu ***
[1] Start Game
[2] Settings
[3] Exit
*****************
Option (1 - 3) : 
```

#### Game Start
```sh
    1 2 3 4 
  +---------+
  |         |
1 | 5 5 5 5 | 1
  |         |
2 | 5 5 5 5 | 2
  |         |
3 | 5 5 5 5 | 3
  |         |
4 | 5 5 5 5 | 4
  |         |
  +---------+
    1 2 3 4 
```

#### First Piece Selected
```sh
    1 2 3 4 
  +---------+
  |         |
1 | C 5 5 5 | 1
  |         |
2 | 5 5 5 5 | 2
  |         |
3 | 5 5 5 5 | 3
  |         |
4 | 5 5 5 5 | 4
  |         |
  +---------+
    1 2 3 4 
```

#### Second Piece Selected
```sh
    1 2 3 4 
  +---------+
  |         |
1 | C D 5 5 | 1
  |         |
2 | 5 5 5 5 | 2
  |         |
3 | 5 5 5 5 | 3
  |         |
4 | 5 5 5 5 | 4
  |         |
  +---------+
    1 2 3 4 
```

#### They do not match, HP decreased by one
```sh
    1 2 3 4 
  +---------+
  |         |
1 | 4 4 5 5 | 1
  |         |
2 | 5 5 5 5 | 2
  |         |
3 | 5 5 5 5 | 3
  |         |
4 | 5 5 5 5 | 4
  |         |
  +---------+
    1 2 3 4 
```

#### First Piece Selected
```sh
    1 2 3 4 
  +---------+
  |         |
1 | 5 5 5 5 | 1
  |         |
2 | A 5 5 5 | 2
  |         |
3 | 5 5 5 5 | 3
  |         |
4 | 5 5 5 5 | 4
  |         |
  +---------+
    1 2 3 4 
```

#### Second Piece Selected
```sh
    1 2 3 4 
  +---------+
  |         |
1 | 5 5 5 5 | 1
  |         |
2 | A A 5 5 | 2
  |         |
3 | 5 5 5 5 | 3
  |         |
4 | 5 5 5 5 | 4
  |         |
  +---------+
    1 2 3 4 
```

#### They matched, pieces removed
```sh
    1 2 3 4 
  +---------+
  |         |
1 | 4 4 5 5 | 1
  |         |
2 |     5 5 | 2
  |         |
3 | 5 5 5 5 | 3
  |         |
4 | 5 5 5 5 | 4
  |         |
  +---------+
    1 2 3 4 
```

#### Settings Menu
```sh
*** Settings Menu ******
[1] Change Board Size
[2] Change Max HP
[3] Change Letter Range
[4] Return to Main Menu
************************
Option(1 - 4): 
```
