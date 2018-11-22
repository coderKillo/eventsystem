#pragma once

#include <map>
#include <vector>
#include <functional>

#include "EventKeys.hpp"
#include "ClientBase.hpp"

class Dispatcher
{
    typedef std::vector<ClientBase *> client_l;

  public:
    Dispatcher(int id);
    ~Dispatcher();
    void postEvent(EventKeys event);
    void onEvent(EventKeys event);
    void subscribe(ClientBase *ptr, EventKeys event);
    void unsubscrube(ClientBase *ptr, EventKeys event);

    template <typename T>
    T *createClient()
    {
        m_clients.emplace_back(std::make_unique<T>());
        ClientBase *newClient = m_clients.back().get();

        for (const auto &key : newClient->eventKeys())
        {
            m_client_map[key].push_back(newClient);
        }
        return newClient;
    }

    void removeClient(ClientBase *client);

  private:
    int id;
    static vector<Dispatcher *> m_disp_list;
    std::vector<std::unique_ptr<ClientBase>> m_clients;
    std::map<EventKey, std::vector<ClientBase *>> m_client_map;
};