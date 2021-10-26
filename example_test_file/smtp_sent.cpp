#include <algorithm>
#include <iostream>
#include <string>
#include <mailio/message.hpp>
#include <mailio/smtp.hpp>

using mailio::message;
using mailio::mail_address;
using mailio::smtps;
using mailio::smtp_error;
using mailio::dialog_error;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::tuple;
using std::make_tuple;
using std::list;

int main(){
	try{
		message msg;
		msg.from(mail_address("First last","yangx18@rpi.edu"));
		msg.add_recipient(mail_address("Xiaoyu  yang","Aoyamamegumi811@gmail.com"));
		msg.subject("Testinng");
		msg.content("Testinng message");

		smtps conn("mail.rpi.edu",587);
		conn.authenticate("yangx18@rpi.edu","password",smtps::auth_method_t::START_TLS);
		conn.submit(msg);
	}
	catch(smtp_error& exc ){
		cout << exc.what() << endl;
	}
	 catch (dialog_error& exc)
    {
        cout << exc.what() << endl;
    }
    return EXIT_SUCCESS;

}
