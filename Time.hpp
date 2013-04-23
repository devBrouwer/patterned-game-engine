#ifndef TIME_H
#define TIME_H

#include <SFML/System.hpp>

class Time
{
    protected:
        Time(const Time&);
        Time& operator = (const Time&);

	private: // data members
	    static Time* pinstance;
		static sf::Clock clock;
		static float currentTime;
		static float deltaTime;

	private: // disable creation of time object
		Time(){}

	public: // functons
	    ~Time();
        static Time *getTime();
		static void update();
		static float now();
		static float step();

};

#endif // TIME_H
