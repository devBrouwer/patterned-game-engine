#ifndef DOOR_HPP
#define DOOR_HPP

#include "GameObject.hpp"
#include "Mesh.hpp"
#include "Texture.hpp"
#include "Room.hpp"


class Door : public GameObject
{
    public:
        /** constructor */
        Door(glm::vec3 position, std::string texture, std::string key, World * w);
        /** Default destructor */
        Room * getRoom1();
        Room * getRoom2();
        Room * getRoom3();
        void setRoom1(Room * aRoom1);
        void setRoom2(Room * aRoom2);
        void setRoom3(Room * aRoom3);
        World * getWorld();
        virtual ~Door();
        std::string getKey();
        void setOpened(bool aOpened);
        bool isOpened();
    protected:
    private:
        std::string key;
        Room * room1;
        Room * room2;
        Room * room3;
        World * world;
        bool opened;
};

#endif // DOOR_HPP
