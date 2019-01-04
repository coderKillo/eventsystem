
# Kommunikation

## General

### Object
```puml
@startuml
object Eventsystem
object Dispatcher{
    id
} 
object Client {
    id
}

Eventsystem *-- "n" Dispatcher
Dispatcher *-- "n" Client

@enduml
```
### Class 
```puml
@startuml
enum EventKey{
    Event1
    Event2
    ...
}

enum DispatcherID{
    default,
    dispatcher1,
    ...
}

interface Publisher{
    +{abstract}virtual void notify(EventKey key, data)
}
class Eventsystem{
    +ClientBase* createClient()
    +ClientBase* createClient(dispatcherID id)
    +notify(EventKey key, data)
    ---
    -map<DispatcherID, Dispatcher> m_dispatcher
}


class Dispatcher{
    +Dispatcher(Publisher& p)
    +void onEvent(EventKey key)
    +void registerClient(unique_ptr<ClientBase>&& ptr)
    +void removeClient(ClientBase*)
    +notify(EventKey key, data)
    ---
    -map<EventKeys,vector<ClientBase*>>
    -vector<unique_ptr<Client>>
    -Publisher& m_publisher
}
class ClientBase{
    +ClientBase(Publisher& p)
    +function getFunc(EventKey)
    ..
    +{abstract}virtual void onEvent1(){}
    +{abstract}virtual vector<EventKeys> eventKeys();
    ---
    Publisher& m_publisher;
}

class Client01{
    void onEvent() override; 
}
class Client02{

}
Eventsystem -up-> DispatcherID
Publisher -up-> EventKey
ClientBase --> Publisher
Eventsystem *-right- "0..*" Dispatcher
Dispatcher *-- "0..*" ClientBase

Publisher <|-- Eventsystem
Publisher <|-- Dispatcher

ClientBase <|-- Client01
ClientBase <|-- Client02

@enduml
```

### Sequence

```puml
participant "Client" as c
participant "Dispatcher" as c
participant "Client" as c

@startuml
group create Client
end

group fire event
end
@enduml
```



```cpp
#include <eventsystem.h>

int main()
{
    Eventsystem e;

    auto c1 = e.addClient(ENUM_CLIENT1, ENUM_DISPATCHER1);
    auto c2 = e.addClient(ENUM_CLIENT2, ENUM_DISPATCHER2);
}

```
## Simple

```puml
@startuml
class Client01{
    void onEvent1() override; 
}
class Client02{

}
class ClientBase{
    virtual void onEvent1(){}
    vector<EventKeys> eventKeys();
    function getFunc(EventKey)
}
Object Dispatcher01{
}
Object Dispatcher02{

}
class DispatcherBase{
    DispatcherBase(int id)
    void ~DispatcherBase()
    void onEvent(EventKey key)
    void postEvent(EventKey key)
    ClientBase* createClient()
    void removeClient(ClientBase*)
    ---
    map<EventKeys,vector<ClientBase*>>
    vector<unique_Client>
    static vector<DispatcherBase> 
    int id
}
object EventKeys{
    enum EventKey
}

Client01 -up-|> ClientBase
Dispatcher01 -down-|> DispatcherBase
Dispatcher02 -down-|> DispatcherBase
Client02 -up-|> ClientBase
Client01 .down. Dispatcher01
Dispatcher01 .right. Dispatcher02
Dispatcher02 .up. Client02

@enduml
```

```code
int main()
{
    Dispatcher d1(1);
    Dispatcher d2(2);    

    ClientBase c1;
    ClientBase c2;
}

```

