#pragma once

#include <map>
#include <vector>
#include <functional>
#include <memory>
#include <string>

#include "EventKeys.hpp"
#include "ClientBase.hpp"

class Dispatcher
{
  public:
    void postEvent(EventKey event);
    void onEvent(EventKey event);

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
    Dispatcher() = default;

    std::vector<std::unique_ptr<ClientBase>> m_clients;
    std::map<EventKey, std::vector<ClientBase *>> m_client_map;
};

static class DispatcherFactory
{
    static Dispatcher* createDispatcher(std::name)
    static std::<Dispatcher *> m_disp_list;
}