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

#ifndef MENUDATA_HPP
#define MENUDATA_HPP


#include <string>
#include <unordered_map>

class MenuData {
private:
    std::unordered_map<std::string, std::string>* menuData;
    friend class Menu;
public:
    explicit MenuData();
    ~MenuData();
    void populateMenuDataMap();

};


#endif //MENUDATA_HPP
