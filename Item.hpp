//
// Created by Steve Owens on 12/7/19.
//

#ifndef ITEM_HPP
#define ITEM_HPP


#include <string>

class Item {
private:
    std::string name;
public:
    explicit Item(std::string& name);
    const std::string &getName() const;
};


#endif //ITEM_HPP
