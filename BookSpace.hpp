//
// Created by Steve Owens on 12/4/19.
//

#ifndef BOOKSPACE_HPP
#define BOOKSPACE_HPP


#include "Space.hpp"

class BookSpace : public Space {
//    friend std::ostream& operator << (std::ostream& os, const Color& color);
private:
    int numBooks;
    Color colorBooks;
public:
    explicit BookSpace(int, Color);
    void search() override;
//    void do_print(std::ostream&) override;

};


#endif //BOOKSPACE_HPP
