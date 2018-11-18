#include <algorithm>

#include "DispatcherBase.hpp"

DispatcherBase::Dispatcher(int id)
:id(id)
{
    m_disp_list.push_back(this);
}
DispatcherBase::~Dispatcher()
{
   m_disp_list.erase(std::remove(m_disp_list.begin(),m_disp_list.end(),this),m_disp_list.end()); 
}
void DispatcherBase::postEvent(EventKeys event)
{

}
void DispatcherBase::onEvent(EventKeys event)
{
    
}
void DispatcherBase::subscribe(ClientBase* ptr, EventKeys event)
{
    
}
void DispatcherBase::unsubscrube(ClientBase* ptr, EventKeys event)
{
    
}