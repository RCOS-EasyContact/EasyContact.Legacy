/**
 * RCOS-EasyContact
 * EasyContact/Backend/include/EasyContact
 * MailClient.hpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_INCLUDE_EASYCONTACT_MAILCLIENT_HPP_
#define BACKEND_INCLUDE_EASYCONTACT_MAILCLIENT_HPP_
// C++ Standard Library
#include <string>
namespace BMC {
bool AuthenticateLogin(const std::string& RCSID, const std::string& Password) noexcept;
class MailClient {
 private:
  const std::string __RCSID;
  const std::string __Password;
  const std::string __EmailAddress;
  std::string __Nickname;

 public:
  explicit MailClient(const std::string& RCSID, const std::string& Password);
  void ChangeNickname(const std::string& Nickname) noexcept;
  bool FetchEmails(const size_t& NumEmails) const noexcept;
  bool SendMessage(const std::string& Recipient_Name,
                   const std::string& Recipient_Email,
                   const std::string& Subject,
                   const std::string& MessageBody) const noexcept;
};
}  // namespace BMC
#endif  // BACKEND_INCLUDE_EASYCONTACT_MAILCLIENT_HPP_
