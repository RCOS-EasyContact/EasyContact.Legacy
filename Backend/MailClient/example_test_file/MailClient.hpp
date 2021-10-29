#include <algorithm>
#include <iostream>
#include <mailio/imap.hpp>
#include <mailio/message.hpp>
#include <mailio/smtp.hpp>
#include <string>

using mailio::codec;
using mailio::dialog_error;
using mailio::imap_error;
using mailio::imaps;
using mailio::message;
using mailio::smtp_error;
using mailio::smtps;
using std::cout;
using std::endl;
using std::for_each;
using std::ifstream;
using std::list;
using std::make_tuple;
using std::string;
class MailClient {
 public:
  // constructor
  MailClient(string& RCSID, string& Password, string& usr_name,
             string& usr_email);
  // recv email, if no error, the return should be the a message;
  int recv(string& RCSID, string& password, message& mesg);
  int remove_first(string& RCSID, string& password);
  int inbox_status(string& RCSID, string& password);
  int sent_message(string& RCSID, string& password, string& name,
                   string& usr_email, string& name_to, string& to_mail,
                   string& subjects, string& mesg);

 private:
  string RCSID;
  string Password;
  string usr_name;
  string usr_email;
}
