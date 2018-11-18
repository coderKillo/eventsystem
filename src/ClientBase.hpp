#pragma once

class ClientBase
{
public:
    ClientBase() = default;
    ~ClientBase() = default;
    
    virtual void onEvent_Demo() {};
};