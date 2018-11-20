#pragma once

#include <functional>

#include "EventKeys.hpp"

class ClientBase
{
public:
    ClientBase() = default;
    ~ClientBase() = default;
    
    virtual void onEvent_Demo() {};
    auto getFunc(EventKeys event)->std::function<decltype(&onEvent_Demo)>
    {
        switch(event)
        {
            case EVENT::DEMO:
                return [this](){this->onEvent_Demo();};
                default:
                return [](){};
        }
    };
};