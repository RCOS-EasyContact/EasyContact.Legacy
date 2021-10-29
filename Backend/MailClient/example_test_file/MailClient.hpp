/**
 * RCOS-EasyContact
 * EasyContact/Backend/MailClient
 * MailClient.hpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_MAILCLIENT_EXAMPLE_TEST_FILE_MAILCLIENT_HPP_
#define BACKEND_MAILCLIENT_EXAMPLE_TEST_FILE_MAILCLIENT_HPP_
// C++ Standard Library
#include <algorithm>
#include <iostream>
#include <string>
// mailio Header Files
#include <mailio/imap.hpp>
#include <mailio/message.hpp>
#include <mailio/smtp.hpp>

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
  MailClient(const string& RCSID, const string& Password,
             const string& usr_name, const string& usr_email);
  // recv email, if no error, the return should be the a message;
  int recv(message* mesg);
  int remove_first();
  int inbox_status();
  int sent_message(const string& name_to, const string& to_mail,
                   const string& subjects, const string& mesg);

 private:
  string RCSID;
  string Password;
  string usr_name;
  string usr_email;
}
#endif  // BACKEND_MAILCLIENT_EXAMPLE_TEST_FILE_MAILCLIENT_HPP_
