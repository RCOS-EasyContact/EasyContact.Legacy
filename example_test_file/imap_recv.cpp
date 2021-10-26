#include <algorithm>
#include <iostream>
#include <string>
#include <typeinfo>
#include <mailio/imap.hpp>


using namespace mailio;
using namespace std;

int main()
{
    try
    {
    	 imaps conn("mail.rpi.edu", 993);
        // modify username/password to use real credentials
        conn.authenticate("yangx18", "Aoyamamegumi811@gmail.com", imaps::auth_method_t::LOGIN);
	imaps::mailbox_stat_t ret = conn.select(list<string>({"Inbox"}));
	cout<<ret.messages_no<<endl;
	message msg;
	msg.line_policy(codec::line_len_policy_t::VERYLARGE,codec::line_len_policy_t::VERYLARGE);
	conn.fetch(ret.messages_no, msg);
	cout<<msg.subject()<<endl;
	cout<<msg.content()<<endl;
    }
    catch (imap_error& exc)
    {
    	cout<<"imap"<<endl;
        cout << exc.what() << endl;
    }
    catch (dialog_error& exc)
    {
        cout << exc.what() << endl;
    }

    return EXIT_SUCCESS;
}
