#include <algorithm>
#include <iostream>
#include <mailio/imap.hpp>
#include <mailio/message.hpp>
#include <mailio/smtp.hpp>
#include <string>
#define RCSID = "yangx18"
#define password = "Aoyamamegumi811@gmail.com"
#define name = "Xiaoyu Yang"
#define usr_email = "yangx18"
#define name_to = "ZHenyuan Gong"
#define to_mail = "gongz3@rpi.edu"
#define subjects = "Testing"
#define content = "Testing"
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

message recv(string& RCSID, string& password) {
  message msg;
  try {
    imaps conn("mail.rpi.edu", 993);
    conn.authenticate(RCSID, password, imaps::auth_method_t::LOGIN);
    imaps::mailbox_stat_t ret = conn.select(list<string>({"Inbox"}));
    msg.line_policy(codec::line_len_policy_t::VERYLARGE,
                    codec::line_len_policy_t::VERYLARGE);
    conn.fetch(ret.messages_no, msg);
    /*
            cout<<msg.subject()<<endl;
            cout<<msg.content()<<endl;
            cout<<msg.from_to_string()<<endl;from who
    */
  } catch (imap_error& exc) {
    cerr << exc.what() << endl;
    return EXIT_FAILURE;
  } catch (dialog_error& exc) {
    cerr << exc.what() << endl;
    return EXIT_FAILURE;
  }
  return msg;
}

int remove_first(string& RCSID, string& password) {
  try {
    imap conn("mail.rpi.edu", 143);
    conn.authenticate(RCSID, password, imap::auth_method_t::LOGIN);
    conn.remove("inbox", 1);
  } catch (imap_error& exc) {
    cerr << exc.what() << endl;
    return EXIT_FAILURE;
  } catch (dialog_error& exc) {
    cerr << exc.what() << endl;
    return EXIT_FAILURE
  }
  return ExIT_SUCCESS;
}

int inbox_status(string& RCSID, string& password) {
  int ret = 0;
  try {
    // connect to server
    imaps conn("mail.rpi.edu", 993);
    // modify to use an existing zoho account
    conn.authenticate(RCSID, password, imaps::auth_method_t::LOGIN);
    // query inbox statistics
    imaps::mailbox_stat_t stat = conn.statistics("inbox");
    ret = stat.messages_no;
  } catch (imap_error& exc) {
    cerr << exc.what() << endl;
    return EXIT_FAILURE;
  } catch (dialog_error& exc) {
    cerr << exc.what() << endl;
    return EXIT_FAILURE;
  }
  return ret;
}

int sent_message(string& RCSID, string& password, string& name,
                 string& usr_email, string& name_to, string& to_mail,
                 string& subjects, string& mesg) {
  try {
    message msg;
    msg.from(
        mail_address(name, usr_email));  // mail_adddress(name,xxx@xxx.edu(com))
    msg.add_recipient(mail_address(name_to, to_mail));
    msg.subject(subjects);
    msg.content(mesg);

    smtps conn("mail.rpi.edu", 587);
    conn.authenticate(RCSID, password, smtps::auth_method_t::START_TLS);
    conn.submit(msg);
  } catch (smtp_error& exc) {
    cerr << exc.what() << endl;
    return EXIT_FAILURE;
  } catch (dialog_error& exc) {
    cerr << exc.what() << endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

int main() {
  message mesg = recv(RCSID, password);
  cout << mesg.subject() << endl;
  cout << mesg.content() << endl;
  cout << mesg.from_to_string() << endl;
  int rem = remove_first(RCSID, password);
  cout << "remove: " << rem << endl;
  int sta = inbox_status(RCSID, password);
  cout << "stat: " << sta << endl;
  int smg = sent_message(RCSID, password, name, usr_email, name_to, to_mail,
                         subjects, mesg);
  cout << "sent_message: " << smg << endl;
}