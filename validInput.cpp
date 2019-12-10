/**********************************************************************************
 * Program name: Final Project - Trapped! A C++ Escape Room Adventure
 * Author: Steven Owens
 * Date: 12/09/2019
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

#include <iostream>
#include <string>
/*
 * Summary: Provides user input validation by iterating through string and checks if
 *          all char are digits, if not it sets the isValidInput flag to false and
 *          breaks the loop since a single since a single failed check means the input
 *          is invalid.
 * Param: std::string input
 * Returns: bool - true if valid or false if not.
 */
bool isValid(std::string input) {

    bool validInput = true;

    std::string cleanInput{};

    if(input.at(0) == '-'){
        cleanInput = input.erase(0,1);
    } else {
        cleanInput = input;
    }

    for(unsigned int i = 0; i < cleanInput.length(); i++){

        if(!std::isdigit(cleanInput.at(i))){
            validInput = false;
            break;
        }
    }

    return validInput;
}
/*
 * Summary: Validates and provides error handling for user input as a string and returns
 *          a fully qualified integer value back to the calling function. Prompts user
 *          for input following validation failure.  Modified to allow negative numbers.
 * Param: std::string input
 * Returns: integer which is validated and converted from a std::string.
 * Source:  cin methods fail, ignore, and cerr adapted from a post by user "int main" on
 *          20080715 from http://www.cplusplus.com/forum/beginner/2957/ Elected to not use
 *          cin.fail() and use string input for validation
 */

int validateIntegerInput(std::string& input){

    while(input.empty() || !isValid(input)){
        //clears potential error flag on cin from invalid input.
        std::cerr << "Invalid option! Choose again.\n";
        std::cin.clear();
        input = "";  // re-initializes input to empty string ""

        getline(std::cin, input);
    }




    return std::stoi(input);
}
/*
 * Summary: Provides user input validation by iterating through string and checks if
 *          all char are digits, if not it sets the isValidInput flag to false and
 *          breaks the loop since a single since a single failed check means the input
 *          is invalid.  Modified to add a check for number of '.', more than one
 *          decimal point is an invalid entry.
 * Param: std::string input
 * Returns: bool - true if valid or false if not.
 */
bool isValidFloat(const std::string& input) {

    bool validInput = true;
    int count{};

    for(unsigned int i = 0; i < input.length(); i++){

        if((input.at(i) != '.' && !std::isdigit(input.at(i))) || count >= 2){
            validInput = false;
            break;
        }
        if(input.at(i) == '.'){
            count++;
        }
    }
    return validInput;
}
/*
 * Summary: Validates and provides error handling for user input as a string and returns
 *          a fully qualified double value back to the calling function. Prompts user
 *          for input following validation failure.
 * Params:  std::string input
 * Returns: integer which is validated and converted from a std::string.
 * Source:  cin methods fail, ignore, and cerr adapted from a post by user "int main" on
 *          20080715 from http://www.cplusplus.com/forum/beginner/2957/ Elected to not use
 *          cin.fail() and use string input for validation
 */
double validateDoubleInput(std::string& input){

    while(input.empty() || !isValidFloat(input)){

        //clears potential error flag on cin from invalid input.
        std::cerr << "Invalid option! Choose again.\n";
        std::cin.clear();
        input = "";  // re-initializes input to empty string ""

        getline(std::cin, input);
    }
    return std::stod(input);
}
/*
 * Summary: Validates and provides error handling for user input as a string and returns
 *          true or false based on error checking. Prompts user for input following
 *          validation failure. Checks if all characters are strings and name only
 *          contains one space (' ') character.
 * Param: std::string input by reference
 * Returns: a boolean based on validation
 * Source:  cin methods fail, ignore, and cerr adapted from a post by user "int main" on
 *          20080715 from http://www.cplusplus.com/forum/beginner/2957/ Elected to not use
 *          cin.fail() and use string input for validation
 */
bool isValidString(std::string& input) {

    bool validInput = true;
    int invalidChar{};

    for(unsigned int i = 0; i < input.length(); i++){

        if((input.at(i) != ' ' && !std::isalpha(input.at(i))) || invalidChar >= 0){
            validInput = false;
            break;
        }
        if(input.at(i) == ' '){
            invalidChar++;
        }
    }

    return validInput;
}
/*
 * Summary: Validates and provides error handling for user input as a string and returns
 *          true or false based on error checking. Prompts user for input following
 *          validation failure.
 * Param: std::string input by reference
 * Returns: a boolean based on validation
 * Source:  cin methods fail, ignore, and cerr adapted from a post by user "int main" on
 *          20080715 from http://www.cplusplus.com/forum/beginner/2957/ Elected to not use
 *          cin.fail() and use string input for validation
 */
bool validateStringInput(std::string& input){

    while(input.empty() || !isValidString(input)){   // removed call to !validString(input), not required in this case

        //clears potential error flag on cin from invalid input.
        std::cerr << "Invalid entry! Enter again.\n";
        std::cin.clear();
        input = "";  // re-initializes input to empty string ""

        getline(std::cin, input);
    }
    return true;
}
