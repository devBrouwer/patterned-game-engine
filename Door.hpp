#ifndef DOOR_HPP
#define DOOR_HPP

#include "GameObject.hpp"


class Door : public GameObject
{
    public:
        /** constructor */
        Door(glm::vec3 position, std::string texture, std::string key);
        /** Default destructor */
        virtual ~Door();
        std::string getKey();
    protected:
    private:
        std::string key;
};

#endif // DOOR_HPP
