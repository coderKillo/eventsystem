#pragma once

#include <functional>
#include "EventKeys.hpp"

class Dispatcher;

class ClientBase
{
    friend class Dispatcher;
private:
    ClientBase() = default;
    ~ClientBase() = default;

    // event keys for which the client has a function
    virtual std::vector<EventKey> eventKeys() const = 0;

    virtual void onEvent_Demo(){};
    auto getFunc(EventKey event) -> std::function<void(void)>
    {
        switch (event)
        {
        case DEMO:
            return [this]() { this->onEvent_Demo(); };
        default:
            return []() {};
        }
    };
};