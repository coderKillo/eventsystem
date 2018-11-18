#pragma once

#include <map>
#include <vector>
#include <functional>

#include "EventKeys.hpp"
#include "ClientBase.hpp"

class Dispatcher
{
typedef std::function<void(void)> eFunc;
typedef std::vector<eFunc> eFuncLst;

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
    std::map<EventKeys, eFuncLst>  m_funcLst_map;
};