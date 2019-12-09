/**********************************************************************************
 * Program name: Lab 9 - STL: Queues and Stacks
 * Author: Steven Owens
 * Date: 11/23/2019
 * Description: This program is demonstrates the use of standard template library
 *              queue and stack data structures.  The STL queue is used to demo
 *              a buffer by simulated a user specified number of rounds with a
 *              random chance of adding an integer between 1 and 1000 to the
 *              queue aka \"buffer\".  The user also specifies the percent
 *              chance of adding and removing a value form the queue. The STL
 *              stack structure is used to demo reversing a given input string
 *              through creation of a palindrome (same word forward or backward).
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
