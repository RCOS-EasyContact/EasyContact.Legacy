#include "../SQLContacts/Contacts.hpp"
namespace MCS{
  class SingleUser{
    public:
    mutable BCS::Contacts Contacts;
    explicit SingleUser(std::string RCSID):Contacts(RCSID){
    }
  };
}