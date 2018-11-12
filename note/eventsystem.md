---
tags:
  - project
---

# Eventsystem
- [Eventsystem](#eventsystem)
    - [Anforderung:](#anforderung)
    - [Aufbau:](#aufbau)
        - [Technik](#technik)
- [Graphic](#graphic)
- [Architektur](#architektur)
    - [*Client*](#client)
    - [*Dispatcher*](#dispatcher)

## Anforderung:
* Jeder Dispatcher auf einen anderen Thread
* Clienten laufen im selben Thread wie der jeweilige Dispatcher
* Client soll nur das event bekommen was ihn interessiert
* Client können sich auf mehreren Dispatchern registrieren
* Reihenfolge der Eventabarbeitung innerhalb eines Dispatcher ist willkürlich

## Aufbau:
* kommunikation zwischen Client und Dispatcher
* Dispatcher weiß wer sich für Events intressiert
* Alle Dispatcher kennen/bekommen alle Events
* Events von Dispatcher an alle anderen Dispatcher
* Events als Broadcast an Dispatcher
* Jeder Dispatcher brauch eine Funktion wo sich Clienten subscriben können
* EventKeys als Enum in Header
* Client registriert sich mit event key an dispatcher
* Events werden durch Keys unterschieden
* Dispatcher verteilt Events an alle Clienten die sich mit entsprechendem Key registriert haben.
### Technik
* Jeder Client hat generierte Handler
* Jedes Event eigene Liste in Dispatcher interface wo subscriver zum event eingetragen werden oder nicht
  * Map von EventKey nach Vector
* Event als sharepointer zwischen den dispatchern und als const ref an clienten weiter.
* Dispatcher machen make share

# Graphic

[Link](./graphen.md)

# Architektur

## *Client*
    Function:
    - as
    - as


## *Dispatcher*
Func
	* 
Supscribe(EventKey)

Member
	* 




