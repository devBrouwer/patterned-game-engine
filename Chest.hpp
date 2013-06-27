#ifndef CHEST_HPP
#define CHEST_HPP

#include "GameObject.hpp"
#include "Mesh.hpp"
#include "Texture.hpp"


class Chest : public GameObject
{
    public:
        /**  constructor */
        Chest(glm::vec3 position, std::string key);
        /** Default destructor */
        virtual ~Chest();
        std::string getKey();
        bool getOpened();
        void open();
    protected:
    private:
        std::string key;
        bool opened;
};

#endif // CHEST_HPP
