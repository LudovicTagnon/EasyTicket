#include "StateManager.h"

StateManager::StateManager()
{

}

void StateManager::push(QWidget* state)
{
    stateManager.push(state);
}

void StateManager::pop()
{
    stateManager.pop();
}

QWidget* StateManager::top()
{
    return stateManager.top();
}

bool StateManager::empty()
{
    return stateManager.empty();
}

StateManager::~StateManager()
{
    while(!stateManager.empty())
    {
        delete stateManager.top();
        stateManager.pop();
    }
}
