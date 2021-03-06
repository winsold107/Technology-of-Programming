//
// Created by darin on 18.03.18.
//

#ifndef INC_1_TASK_PATTERN_GAME_H
#define INC_1_TASK_PATTERN_GAME_H


#include "User.h"

class Game {
public:
    Game() {}

    void start();
    void initGame();
    int run();
    void showWelcome() const;

private:

    void _showUserArmies(UserPtr usr);
    void _requireSide();
    void _createArmiesForUsers();
    void _turnResult(int wh, int dk, int& wink, int& dinc);

    bool _finished = false;
    UserPtr _user1, _user2;
};



#endif //INC_1_TASK_PATTERN_GAME_H
