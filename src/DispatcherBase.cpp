#include <algorithm>

#include "Util.hpp"

#include "DispatcherBase.hpp"

DispatcherBase::Dispatcher(int id)
    : id(id)
{
    m_disp_list.push_back(this);
}
DispatcherBase::~Dispatcher()
{
    util::remove(m_disp_list, this);
}
void DispatcherBase::postEvent(EventKey event)
{
    for (const auto &disp : m_disp_list)
    {
        disp->onEvent(event);
    }
}
void DispatcherBase::onEvent(EventKey event)
{
    for (const auto &client : m_client_map[event])
    {
        client->getFunc(event)();
    }
}
void DispatcherBase::removeClient(ClientBase *ptr)
{
    std::remove_if(m_clients.begin(), m_clients.end(), [ptr](auto client) { return ptr == client.get(); });
    util::remove(m_client_map[event], ptr);
}