/**********************************************************************************
 * Program name: Final Project - Trapped! A C++ Escape Room Adventure
 * Author: Steven Owens
 * Date: 11/23/2019
 * Description: This is an escape room style game with a twist. You must solve the
 *              puzzle to find the skeleton key that unlocks the door to safety,
 *              but you must do so before the batteries in your flashlight are dead.
 *              Each time you move between rooms the charge diminishes, and once the
 *              batteries are dead, your character is plunged into darkness. Without
 *              a source of light, they will never be able to solve the puzzle to
 *              find their way out of the darkness.
 *********************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP


#include "Space.hpp"
#include "GameMap.hpp"
#include "Menu.hpp"

class Game {
private:
    GameMap* map;
    Player* player;
    Menu* menu;
public:
    explicit Game(Menu* menu);
    ~Game();
    void play();
    int hasKeyMenu();
    void noKeyMenu();
    bool moveForward();
    bool moveBackward();
    void searchRoom();
    void printStatus();
    void enterCombo();
    int endGame();
};


#endif //GAME_HPP
