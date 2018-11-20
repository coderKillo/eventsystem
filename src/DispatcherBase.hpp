#pragma once

#include <map>
#include <vector>
#include <functional>

#include "EventKeys.hpp"
#include "ClientBase.hpp"

class Dispatcher
{
typedef std::vector<ClientBase*> client_l;

public:
    Dispatcher(int id);
    ~Dispatcher();
    void postEvent(EventKeys event);
    void onEvent(EventKeys event);
    void subscribe(ClientBase* ptr, EventKeys event);
    void unsubscrube(ClientBase* ptr, EventKeys event);
private:
    int id;
    static vector<Dispatcher*> m_disp_list; 
    std::map<EventKeys, client_l>  m_client_map;
};