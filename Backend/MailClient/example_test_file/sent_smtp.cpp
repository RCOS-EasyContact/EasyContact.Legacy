#include <algorithm>
#include <iostream>
#include <mailio/message.hpp>
#include <mailio/smtp.hpp>
#include <string>

using mailio::dialog_error;
using mailio::mail_address;
using mailio::message;
using mailio::smtp_error;
using mailio::smtps;
using std::cout;
using std::endl;
using std::ifstream;
using std::list;
using std::make_tuple;
using std::string;
using std::tuple;

int main() {
  try {
    message msg;
    msg.from(mail_address("First last", "yangx18@rpi.edu"));
    msg.add_recipient(
        mail_address("Xiaoyu  yang", "Aoyamamegumi811@gmail.com"));
    msg.subject("Testinng");
    msg.content("Testinng message")

        smtp conn("mail.rpi.edu", 587);
    conn.authenticate("yangx18@rpi.edu", "password",
                      smtps::auth_method::START_TLS);
    conn.submit(msg);
  } catch (smtp_error& exc) {
    cout << exc.what() << endl;
  } catch (dialog_error& exc) {
    cout << exc.what() << endl;
  }
  return EXIT_SUCCESS;
}