#ifndef ROOM_H
#define ROOM_H

#include "GameObject.hpp"


class Room : public GameObject
{
    public:
        Room(std::string aName);
        virtual ~Room();
        bool checkCollisions();
    protected:
    private:
};

#endif // ROOM_H
