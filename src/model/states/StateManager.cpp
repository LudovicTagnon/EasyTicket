#include "StateManager.h"

#include <QWidget>

StateManager::StateManager()
{

}

void StateManager::push(QWidget* state) {
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
    QWidget* top;
    while(!stateManager.empty())
    {
        top = stateManager.top();
        stateManager.pop();
        delete top;
    }
}
