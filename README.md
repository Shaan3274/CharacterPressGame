# Character Press Game - README
This is a simple character press game built using OpenGL and GLUT (OpenGL Utility Toolkit). The game involves pressing the falling characters from the alphabet before they reach the ground. Each successful press will increase your score, and you start the game with 3 lives. If a character reaches the ground without being pressed, you lose one life. The game ends when you lose all your lives.
## How to Play
1. #### Compile the Code:
     Make sure you have the necessary libraries installed for OpenGL and GLUT. Then, compile the code using a C++ compiler.

2. ### Run the Game: 
     After compiling, run the executable to start the game.

3. ### Enter Your Name: 
     When you run the game, you will be prompted to enter your name. Type your name and press Enter.

4. ### Gameplay: 
     The game will start, and characters will fall from the top of the window. Use the keyboard to press the corresponding character as it falls. Each successful        press increases your score. If a character reaches the ground without being pressed, you lose one life. The game ends when you lose all your lives.

5. ### Restart: 
      If the game is over, you can press the 'r' key to restart the game.
## Screenshots
The very first thing you will see after running the game is Console screen you need to enter your name:

![image](https://github.com/Shaan3274/CharacterPressGame/assets/112044382/bcc3aa5a-0058-4851-9db9-6623291c9c3d)


When you enter your name then game will start and now the thing only you need to do is to catch the characters 

![image](https://github.com/Shaan3274/CharacterPressGame/assets/112044382/0031af66-fec5-46ce-8d6c-c8c3386c0550)


when its over do press the character R or r from the keyboard to restart the game.

![image](https://github.com/Shaan3274/CharacterPressGame/assets/112044382/8403abfc-5bf4-4f89-8b9d-602b85266e94)



## Controls
Press the corresponding key on your keyboard to "catch" the falling characters.
Press 'r' to restart the game when the game is over.
## Dependencies:
  The game uses the following libraries:
  - OpenGL
  - GLUT (OpenGL Utility Toolkit)
## Compilation
To compile the game, make sure you have OpenGL and GLUT installed on your system. Then, use a C++ compiler to build the executable.
### Example Compilation (Linux):

### Linux

```bash
g++ -o character_press_game CharacterPressGame.cpp -lGL -lGLU -lglut
```

### Windows - MinGW

```bash
g++ -o character_press_game.exe CharacterPressGame.cpp -lopengl32 -lglu32 -lglut32
```
## Author
Shan Ayub
## Acknowledgments
The game code is based on a simple falling characters game tutorial. Thanks to the tutorial creator and the open-source community for providing resources and knowledge.
