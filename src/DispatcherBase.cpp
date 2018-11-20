#include <algorithm>

#include "Util.hpp"

#include "DispatcherBase.hpp"

DispatcherBase::Dispatcher(int id)
:id(id)
{
    m_disp_list.push_back(this);
}
DispatcherBase::~Dispatcher()
{
    util::remove(m_disp_list,this);
}
void DispatcherBase::postEvent(EventKeys event)
{
    for(const auto &disp : m_disp_list)
    {
        disp->onEvent(event);
    }
}
void DispatcherBase::onEvent(EventKeys event)
{
    for(const auto &client : m_client_map[event])
    {
        auto func = client->getFunc(event);
        func();
    }
}
void DispatcherBase::subscribe(ClientBase* ptr, EventKeys event)
{
    m_client_map[event].push_back(ptr);
}
void DispatcherBase::unsubscrube(ClientBase* ptr, EventKeys event)
{
    util::remove(m_client_map[event],ptr);
}