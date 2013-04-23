#include "Time.hpp"

#include <iostream>

sf::Clock Time::clock;
float Time::currentTime = 0.0f;
float Time::deltaTime = 0.0f;

Time* Time::pinstance = 0;

Time* Time::getTime(){
	if(pinstance == 0){
		pinstance = new Time;
	}
	return pinstance;
}

Time::Time(const Time&)
{

}

Time& Time::operator = (const Time& time)
{
    return const_cast<Time&>(time);
}

Time::~Time(){
	pinstance = 0;
}

void Time::update()
{

	float newTime = clock.getElapsedTime().asSeconds();
	deltaTime = newTime - currentTime;
	currentTime = newTime;
}

float Time::now()
{
	return currentTime;
}

float Time::step()
{
	return deltaTime;
}
