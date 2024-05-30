# Team Members:

<table>
<tr>
  <th>Name</th>
  <th>Roll Number</th>
</tr>
<tr>
  <td>Amna</td>
  <td>23K-0066</td>
</tr>
<tr>
  <td>Laiba</td>
  <td>23K-0006</td>
</tr>
</table>


# Project Demo:


https://github.com/laibaa1209/OOP-Project-Space-Invaders-/assets/142903458/252c3366-4061-4383-b215-7260f82857ce





# Project Presentation:

[Link For Project Presentation](https://github.com/laibaa1209/OOP-Project-Space-Invaders-/blob/08e6ea423da7cd1941816529d740101fcb138c13/OOP%20PROJECT%20ppt.pdf)

# Project Proposal: Space Invaders
![image](https://github.com/laibaa1209/OOP-Project-Space-Invaders-/assets/142867994/20b058fd-667c-4f04-b262-f7c2bde478d0)

[Link For Project Proposal](https://github.com/laibaa1209/OOP-Project-Space-Invaders-/blob/d013bf38d715047d95db8a78f59714249f9ce573/OOP%20Project%20Proposal.docx)

# Introduction:
Space Invaders is a classic arcade game where the player controls a spaceship at the bottom of the screen and must shoot down waves of approaching aliens before they reach the bottom. The player has limited lives and must navigate through the advancing enemy ranks, using the walls as defense and strategically timing their shots.

# Game Mechanics
The gameplay revolves around the following mechanics:

* <strong>Player Control: </strong> Players control a spaceship at the bottom of the screen using arrow keys.
* <strong>Shooting: </strong> Players can shoot bullets upwards to destroy alien invaders by pressing the spacebar.
* <strong>Enemy Movement: </strong> Alien invaders move horizontally and slowly descend towards the player's spaceship.
* <strong>Wall Defense: </strong> Walls act as defensive barriers, protecting the player from enemy bullets. However, walls degrade over time when hit by bullets.
  

## Classes Overview:
### 1. Wall
The Wall class represents a defensive barrier that protects the player's spaceship from enemy bullets. However, the wall can sustain damage when hit by either enemy bullets or the player's bullets.
```C
class Wall : public Drawable
{
private:
    vector<Sprite> sprites;
    vector<pair<int, int>> state;

public:
    Wall(int x, int y, Texture& wallTexture);
    void getPosition(vector<pair<int, Vector2f>> &pos);
    void update();
    void collision(int indice, bool up);
    virtual void draw(RenderTarget &rt, RenderStates rs) const;
};
```
* The <strong>Wall</strong> class represents the defensive barrier in the game.
* It contains a vector of <strong>Sprite</strong> objects to represent different parts of the wall and a vector of pairs to maintain the state (damage) of each part.
* <strong>Wall(int x, int y, Texture& wallTexture):</strong> Constructor that initializes the wall's sprites and their positions.
* <strong>getPosition(vector<pair<int, Vector2f>>& pos):</strong> Method to get the positions of undamaged parts of the wall.
* <strong>update():</strong> Method to update the wall's appearance based on its state.
* <strong>collision(int indice, bool up):</strong> Method to handle collision with bullets and update the state of the wall.
* <strong>draw(RenderTarget &rt, RenderStates rs) const:</strong> Method to draw the wall on the screen.

### 2. Player
The Player class handles the movement of the player's spaceship, shooting, and tracking the number of lives remaining. The player has three lives, and the game ends if all lives are lost.
```C
class Player : public Drawable
{
private:
    Sprite playerSprite;
    int numberOfLives;
    int playerSpeed;
    bool shooting = false;

public:
    Player(int x, int y, Texture &playerTexture);
    void update();
    bool shoot();
    Vector2f getPosition();
    void reduceLives();
    bool isDead();
    virtual void draw(RenderTarget &rt, RenderStates rs) const;
};
```
* The <strong>Player</strong> class represents the player-controlled spaceship.
* It contains a <strong>Sprite</strong> object for the player's sprite, along with variables for lives, speed, and shooting state.
* <strong>Player(int x, int y, Texture &playerTexture):</strong> Constructor to initialize the player's sprite and attributes.
* <strong>update():</strong> Method to update the player's movement based on keyboard input.
* <strong>shoot():</strong> Method to handle shooting bullets.
* <strong>getPosition():</strong> Method to get the player's position.
* <strong>reduceLives():</strong> Method to decrease the player's lives.
* <strong>isDead():</strong> Method to check if the player is out of lives.
* <strong>draw(RenderTarget &rt, RenderStates rs) const:</strong> Method to draw the player on the screen.

### 3. Enemy
The Enemy class manages the behavior of the alien invaders, including shooting, movement across the screen, and disappearance when killed by the player. If an enemy reaches too close to the player's spaceship, the game ends.
``` C
class Enemy : public Drawable
{
private:
    Sprite enemySprite;
    int state;
    int timer;
    int resetTimer;
    Vector2f point;
    int enemySpeed;

public:
    Enemy(int x, int y, Texture& enemyTexture, Vector2f point);
    void update();
    void changeDirection();
    Vector2f getPosition();
    void decreaseResetTimer();
    virtual void draw(RenderTarget &rt, RenderStates rs) const;
};
```
* The <strong>Enemy</strong> class represents the alien invaders.
* It contains a <strong>Sprite</strong> object for the enemy's sprite and variables for state, movement, and timers.
* <strong>Enemy(int x, int y, Texture& enemyTexture, Vector2f point):</strong> Constructor to initialize the enemy's sprite and attributes.
* <strong>update():</strong> Method to update the enemy's movement and appearance.
* <strong>changeDirection():</strong> Method to change the direction of enemy movement.
* <strong>getPosition():</strong> Method to get the enemy's position.
* <strong>decreaseResetTimer():</strong> Method to decrease the timer for enemy shooting.
* <strong>draw(RenderTarget &rt, RenderStates rs) const:</strong> Method to draw the enemy on the screen.

### 4. Bullet
The Bullet class is responsible for the behavior of both enemy and player bullets. The player can only shoot another bullet once the current bullet has crossed the screen or hit/killed an enemy from the rows of enemies.
``` C
class Bullet : public Drawable
{
private:
    Sprite bulletSprite;
    int bulletSpeed;

public:
    Bullet();
    Bullet(int x, int y, Texture& bulletTexture, IntRect intRect, int bulletSpeed);
    void update();
    Vector2f getPosition();
    virtual void draw(RenderTarget &rt, RenderStates rs) const;
};
```
* The <strong>Bullet</strong> class represents bullets fired by both the player and enemies.
* It contains a <strong>Sprite</strong> object for the bullet's sprite and variables for speed.
* <strong>Bullet(int x, int y, Texture& bulletTexture, IntRect intRect, int bulletSpeed):</strong> Constructor to initialize the bullet's sprite and attributes.
* <strong>update():</strong> Method to update the bullet's movement.
* <strong>getPosition():</strong> Method to get the bullet's position.
* <strong>draw(RenderTarget &rt, RenderStates rs) const:</strong> Method to draw the bullet on the screen.





## Main Function and Global Functions:
The main function and global functions in the Space Invaders project are crucial for managing the game's logic, handling user input, updating the game state, and rendering graphics. Let's delve into how these functions work and their roles in the game.

### Main Function
The main function initializes game objects, sets up the game window, and enters the game loop. Within the loop, it handles events, updates the game state, renders graphics, and checks for game over conditions.
``` C
int main()
{
    // Initialization code...
    
    while (window.isOpen() && music.getStatus() == sf::SoundSource::Playing) {
        // Event handling...
        
        updatePlayer(player, bulletPlayer);
        updateBulletPlayer(bulletPlayer, enemies);
        updateEnemies(enemies);
        updateBulletsEnemies(player);
        updateWall(wall, bulletPlayer);
        
        // Game over conditions...
        
        window.clear();
        
        // Rendering...
        
        window.display();
    }
    
    return 0;
}
```
### How It Works:
 <strong>1. Initialization: </strong>
The main function initializes essential game objects such as the player, enemies, walls, and the game window. It also sets up any necessary audio resources.

<strong> 2. Game Loop: </strong>
The game loop continues as long as the game window is open and the background music is playing. This loop ensures that the game continues running and responding to user input.

<strong> 3. Event Handling: </strong>
Within the loop, the main function handles events such as window closure. It checks for user input and updates the game state accordingly.

 <strong>4. Update Functions: </strong>
The main function calls various update functions to handle player movement, bullet movement, enemy behavior, bullet collisions, and wall interactions. These functions update the positions, states, and behaviors of game objects based on the current game state.

<strong> 5. Rendering: </strong>
After updating the game state, the main function clears the window and renders the updated game objects onto the screen.

<strong> 4. Display: </strong>
Finally, the main function displays the rendered graphics on the game window.



### Global Functions
Global functions in the Space Invaders project handle specific tasks such as updating player movement, handling bullet collisions, managing enemy behavior, and updating wall interactions.

* <strong>updatePlayer(Player &player, Bullet &bulletPlayer):</strong> Updates player movement and shooting mechanics based on user input.
* <strong>updateBulletPlayer(Bullet &bulletPlayer, vector<vector<Enemy>> &enemies):</strong> Updates bullet movement and checks for collisions between player bullets and enemies.
* <strong>updateEnemies(vector<vector<Enemy>> &enemies):</strong> Updates enemy movement and shooting behavior, as well as handles changes in enemy direction and reset timers.
* <strong>updateBulletsEnemies(Player &player):</strong> Updates enemy bullets' movement, checks for collisions with the player, and removes bullets that have passed the screen.
* <strong>updateWall(vector<Wall> &wall, Bullet &bulletPlayer):</strong> Updates the state of walls based on collisions with bullets from both the player and enemies.


## Installation
To run Space Invaders on your local machine, follow these steps:

* Clone the repository or download the project files.
* Ensure you have SFML installed on your system.
* Compile the source code using a C++ compiler with SFML linked.
* Run the compiled executable to start the game.

## How to Play

### Controls:

Use arrow keys or WASD keys to move the player's spaceship.
Press the spacebar to shoot bullets at the enemy invaders.

### Objective:

Prevent the alien invaders from reaching the bottom of the screen.
Eliminate as many alien invaders as possible while avoiding enemy bullets.

### Game Over:

The game ends if the player loses all lives or if an enemy reaches too close to the player's spaceship.
