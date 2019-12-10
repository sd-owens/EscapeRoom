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
 *
 * Secret:      365 is the combination to the chest, based on 3 Blue Books, 6 Green
 *              Books, and 5 Red books.  Alphabetizing the book colors and reading
 *              their quantity in sequence solves the riddle to unlock the chest.
 *********************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include "Player.hpp"

enum Color {Blue , Green, Red};

class Space {
    friend class GameMap;
protected:
    Player* player;
    std::string name;
    bool locked;
    int roomNum;
    int row;                            // used during addSpace to generate coordinator for printMap
    int col;                              // used during addSpace to generate coordinator for printMap
    Space* north;
    Space* east;
    Space* south;
    Space* west;
public:
    explicit Space(std::string& name);
    virtual ~Space();
    virtual void search() = 0;   // pure virtual function that makes Space an abstract class
    virtual bool isLocked();
    virtual void unlock();
    void setRow(int row);
    void setCol(int col);
    int getRow() const;
    int getCol() const;
    void setPlayer(Player *player);
    Player *getPlayer() const;
    const std::string &getName() const;

};


#endif //SPACE_HPP
