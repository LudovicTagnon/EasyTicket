#include "StateManager.h"

#include <QWidget>

StateManager::StateManager()
{

}

void StateManager::push(QWidget* state) {
    if(!stateManager.empty())
        stateManager.top()->hide();

    stateManager.push(state);
    stateManager.top()->show();
}

void StateManager::pop()
{
    stateManager.top()->hide();
    stateManager.pop();
    if(!stateManager.empty())
        stateManager.top()->show();
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
