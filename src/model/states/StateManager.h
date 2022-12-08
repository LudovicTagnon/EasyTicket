#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <stack>

class QWidget;

class StateManager
{
    private:
        std::stack<QWidget*> stateManager;
    
    public:
        StateManager();

        void push(QWidget* state);
        void pop();
        QWidget* top();
        bool empty();

        ~StateManager();
};

#endif