#include <iostream>
#include <string>
#include <fstream>
#include <mailio/message.hpp>
#include <mailio/pop3.hpp>


using mailio::message;
using mailio::codec;
using mailio::pop3s;
using mailio::pop3_error;
using mailio::dialog_error;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;

int main(){
	try{
		pop3s conn("mail.rpi.edu",995);
		conn.authenticate("yangx18@rpi.edu","password",pop3::auth_method::LOGIN);
		message msg;
		conn.fetch(1,msg);
	}
	catch (imap_error& exc)
    {
        cout << exc.what() << endl;
    }
    catch (dialog_error& exc)
    {
        cout << exc.what() << endl;
    }

    return EXIT_SUCCESS;
	

}