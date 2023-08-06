#include <GL/glut.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include<iostream>
using namespace std;
// Global variables
int windowWidth = 800;
int windowHeight = 600;
float characterPositionX = 0.0f;
int score = 0;
int lifeScore = 3;
bool gameover = false;
bool gameStarted = false;
string playerName;
float landscapeOffsetX = -1.0;
struct Character
{
	float posX;
	float posY;
	char value;
	bool active;
};

std::vector<Character> characters;

void drawCharacter(float posX, float posY, char value)
{
	glPushMatrix();
	glTranslatef(posX, posY, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex2f(-0.05f, -0.05f);
	glVertex2f(0.05f, -0.05f);
	glVertex2f(0.05f, 0.05f);
	glVertex2f(-0.05f, 0.05f);
	glEnd();
	glPopMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	glRasterPos2f(posX - 0.015f, posY - 0.015f);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, value);
}
void displayTree() {
	glColor3f(0.0f, 0.0f, 0.0f);
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex2f(0.3f + landscapeOffsetX, -0.7f);
	glVertex2f(0.3f + landscapeOffsetX, -0.3f);
	glEnd();
	//sign board
	glColor3f(0.8f, 0.8f, 0.8f);  // Set the color for the background rectangle (light gray in this example)
	glBegin(GL_POLYGON);
	glVertex2f(0.55f + landscapeOffsetX, -0.3);  // Bottom-right corner
	glVertex2f(0.55f + landscapeOffsetX, -0.1);
	glVertex2f(0.1f + landscapeOffsetX, -0.1);
	glVertex2f(0.1f + landscapeOffsetX, -0.3);
	glEnd();
	// Draw the signboard text
	glColor3f(0.0f, 0.0f, 0.0f);  // Set the color for the text (black in this example)
	glRasterPos2f(0.11f + landscapeOffsetX, -0.2f);
	string signText = "Char Press Game";
	for (char c : signText)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

}
void display()
{
	// Clear the buffer
	glClear(GL_COLOR_BUFFER_BIT);

	// Draw the sky
	glBegin(GL_QUADS);
	glColor3f(0.53f, 0.81f, 0.92f);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(1.0f, -1.0f);
	glVertex2f(-1.0f, -1.0f);
	glEnd();

	// Draw the sun
	glPushMatrix();
	glTranslatef(0.7f + landscapeOffsetX, 0.7f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0.0f, 0.0f);
	for (int i = 0; i <= 360; i++)
	{
		float angle = 3.14159f * i / 180.0f;
		float x = 0.1f * cos(angle);
		float y = 0.1f * sin(angle);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();

	// Draw the trees
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	// Tree 1
	glVertex2f(-0.6f + landscapeOffsetX, -0.6f);
	glVertex2f(-0.8f + landscapeOffsetX, -0.6f);
	glVertex2f(-0.7f + landscapeOffsetX, -0.3f);
	// Tree 2
	glVertex2f(0.0f + landscapeOffsetX, -0.6f);
	glVertex2f(-0.2f + landscapeOffsetX, -0.6f);
	glVertex2f(-0.1f + landscapeOffsetX, -0.4f);
	glEnd();
	// Clear the buffer
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-1.0, -0.7);
	glVertex2f(1.0, -0.7);
	glVertex2f(1.0, -1.0);
	glVertex2f(-1.0, -1.0);
	glEnd();


	//display function call
	displayTree();

	// Display remaining lives
	glColor3f(1.0f, 1.0f, 1.0f);
	glRasterPos2f(-0.98f, -0.8f);
	string str = to_string(lifeScore);
	string remainingLives = "Remaining lives " + str;
	for (char c : remainingLives)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	// Display username
	glColor3f(1.0f, 1.0f, 1.0f);
	glRasterPos2f(-0.98f, -0.9f);
	string name = playerName;
	string textToDisplay = "Player: " + name;
	for (char c : textToDisplay)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	// Draw the falling characters
	for (const Character& character : characters)
	{
		if (character.active)
			drawCharacter(character.posX, character.posY, character.value);
	}

	// Draw the score
	glColor3f(1.0f, 1.0f, 1.0f);
	glRasterPos2f(0.75f, -0.8f);
	string scoreText = "Score: " + to_string(score);
	for (char c : scoreText)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	// Draw game over text if gameover is true
	if (gameover)
	{
		glColor3f(1.0f, 0.0f, 0.0f);
		glRasterPos2f(-0.25f, 0.0f);
		string gameOverText = "Game Over! Press R to restart.";
		for (char c : gameOverText)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
		}
	}

	// Swap buffers
	glutSwapBuffers();
}


void reshape(int width, int height)
{
	// Update the viewport
	glViewport(0, 0, width, height);

	// Update the projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	// Update the modelview matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void startGame();
void restartGame();
void keyboard(unsigned char key, int x, int y)
{
	if (!gameover && gameStarted)
	{
		for (Character& character : characters)
		{
			if (character.active && character.value == key)
			{
				character.active = false;
				score++;
				break;
			}
		}
	}

	if (gameover && key == 'r')
	{
		restartGame();
		startGame();
	}
}
void restartGame()
{
	characters.clear();
	characterPositionX = 0.0f;
	score = 0;
	lifeScore = 3;
	gameover = false;
	gameStarted = false;
}
void update(int value)
{
	if (landscapeOffsetX >= 1) {
		landscapeOffsetX = -1.0;
		landscapeOffsetX += 0.001f;
	}
	else {
		landscapeOffsetX += 0.001f;
	}
	if (!gameover && gameStarted)
	{
		// Update falling characters
		for (Character& character : characters)
		{
			if (character.active)
			{
				character.posY -= 0.003f;  // Adjust the decrement value for slower falling speed

				// Check collision with ground
				if (character.posY <= -0.7f && character.active)
				{
					character.active = false;
					if (--lifeScore == 0)
					{
						gameover = true;
						break;
					}
				}
			}
		}
		// Generate new falling characters if the count is less than the maximum
		int activeCharacterCount = 0;
		for (const Character& character : characters)
		{
			if (character.active)
				activeCharacterCount++;
		}

		if (activeCharacterCount < 3)
		{
			Character newCharacter;
			float array[] = { -0.9,-0.8,-0.7,-0.6,-0.5,-0.4,-0.3,-0.2,-0.1,0.0,0.9,0.8,0.7,0.6,0.5,0.4,0.3,0.2,0.1 };
			int newCharIndex = rand() % 19;
			newCharacter.posX = array[newCharIndex];
			newCharacter.posY = 1.0f;
			newCharacter.value = static_cast<char>('a' + (rand() % 26));
			newCharacter.active = true;
			characters.push_back(newCharacter);
		}

		// Remove inactive characters
		characters.erase(std::remove_if(characters.begin(), characters.end(), [](const Character& character) {
			return !character.active;
			}), characters.end());
	}
	glutPostRedisplay();
	glutTimerFunc(10, update, 0);
}


void startGame()
{
	gameStarted = true;
}
void getUserName() {
	cout << "Enter your name:";
	cin >> playerName;
}
int main(int argc, char** argv)
{
	getUserName();
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("Character Press Game");
	glClearColor(0.53f, 0.81f, 0.92f, 1.0f);
	// Set the display function
	glutDisplayFunc(display);

	// Set the reshape function
	glutReshapeFunc(reshape);

	// Set the keyboard functions
	glutKeyboardFunc(keyboard);

	// Set random seed
	srand(static_cast<unsigned int>(time(0)));

	// Start the game
	startGame();

	// Set the timer function
	glutTimerFunc(10, update, 0);

	// Start the main loop
	glutMainLoop();

	return 0;
}