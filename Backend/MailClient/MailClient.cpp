/**
 * RCOS-EasyContact
 * EasyContact/Backend/MailClient
 * MailClient.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_MAILCLIENT_EXAMPLE_TEST_FILE_MAILCLIENT_CPP_
#define BACKEND_MAILCLIENT_EXAMPLE_TEST_FILE_MAILCLIENT_CPP_
#include "MailClient.hpp"
bool BMC::AuthenticateLogin(const std::string& RCSID,
                            const std::string& Password) {
  try {
    imaps conn("mail.rpi.edu", 993);
    conn.authenticate(RCSID, Password, imaps::auth_method_t::LOGIN);
  } catch (imap_error& exc) {
    cerr << exc.what() << endl;
    return false;
  }
  return true;
}
MailClient::MailClient(const string& _RCSID, const string& _Password,
                       const string& _usr_name, const string& _usr_email) {
  RCSID = _RCSID;
  Password = _Password;
  usr_name = _usr_name;
  usr_email = _usr_email;
}
int MailClient::recv(message* msg) {
  // message &new_msg = *msg;
  try {
    imaps conn("mail.rpi.edu", 993);
    conn.authenticate(RCSID, Password, imaps::auth_method_t::LOGIN);
    imaps::mailbox_stat_t ret = conn.select(list<string>({"Inbox"}));
    msg.line_policy(codec::line_len_policy_t::VERYLARGE,
                    codec::line_len_policy_t::VERYLARGE);
    conn.fetch(ret.messages_no, *msg);
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
  return EXIT_SUCCESS;
}
int MailClient::remove_first() {
  try {
    imap conn("mail.rpi.edu", 143);
    conn.authenticate(RCSID, Password, imap::auth_method_t::LOGIN);
    conn.remove("inbox", 1);
  } catch (imap_error& exc) {
    cerr << exc.what() << endl;
    return EXIT_FAILURE;
  } catch (dialog_error& exc) {
    cerr << exc.what() << endl;
    return EXIT_FAILURE
  }
  return EXIT_SUCCESS;
}
int MailClient::inbox_status() {
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
int MailClient::sent_message(const string& name_to, const string& to_mail,
                             const string& subjects, const string& mesg) {
  try {
    message msg;
    msg.from(mail_address(usr_name,
                          usr_email));  // mail_adddress(name,xxx@xxx.edu(com))
    msg.add_recipient(mail_address(name_to, to_mail));
    msg.subject(subjects);
    msg.content(mesg);

    smtps conn("mail.rpi.edu", 587);
    conn.authenticate(RCSID, Password, smtps::auth_method_t::START_TLS);
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
#endif  // BACKEND_MAILCLIENT_EXAMPLE_TEST_FILE_MAILCLIENT_CPP_
