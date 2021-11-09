# EasyContact/Backend/API
## Testing With CURL
### GET
```
curl -X GET \
  -H "Content-type: application/json" \
  -H "Accept: application/json" \
  -d '{"param0":"pradeep"}' \
  "localhost:3126/a/c/getName"
```
### POST
```
curl -X POST \
  -H "Content-type: application/json" \
  -d '{"param0":"pradeep"}' \
  "localhost:3126/Login"
```
## Routes
### **POST** `/Login`
- Authenticate User's RCSID and Password with RPI's Email Server
- Request Body:
  - RCSID
  - Password
- On Success:
  - Status: `200 OK`
  - Body: User Access Token
- On Failure: 
  - Status: `511 Network Authentication Required`
  - Status: `500 Internal Server Error`
### **GET** `/Contacts/AllNames`
- Retrieve All Contact Names
- Request Body:
  - Token
- On Success:
  - Status: `200 OK`
  - Body: All Existing Contact Names
- On Failure: 
  - Status: `401 Unauthorized`
  - Status: `500 Internal Server Error`
### **GET** `/Contacts/AllTags`
- Retrieve All Tags
- Request Body:
  - Token
- On Success:
  - Status: `200 OK`
  - Body: All Existing Tags
- On Failure: 
  - Status: `401 Unauthorized`
  - Status: `500 Internal Server Error`
### **GET** `/Contacts/TagContains`
- Retrieve All Contacts Within One Tag
- Request Body:
  - Token
  - Name
- On Success:
  - Status: `200 OK`
  - Body: All Contacts of This Tag
- On Failure: 
  - Status: `401 Unauthorized`
  - Status: `500 Internal Server Error`
### **GET** `/Contacts/Email`
- Retrieve Email Address For One Contact
- Request Body:
  - Token
  - Name
- On Success:
  - Status: `200 OK`
  - Body: Email Address for This Contact
- On Failure: 
  - Status: `401 Unauthorized`
  - Status: `500 Internal Server Error`
### **POST** `/Contacts/New`
- Create New Contact
- Request Body:
  - Token
  - Name
- On Success:
  - Status: `200 OK`
- On Failure: 
  - Status: `401 Unauthorized`
  - Status: `409 Conflict`
  - Status: `500 Internal Server Error`
### **POST** `/Contacts/Tag`
- Create New Tag
- Request Body:
  - Token
  - TagName
- On Success:
  - Status: `200 OK`
- On Failure: 
  - Status: `401 Unauthorized`
  - Status: `409 Conflict`
  - Status: `500 Internal Server Error`
### **PUT** `/Contacts/Assign`
- Assign Tag to One Existing Contact
- Request Body:
  - Token
  - TagName
  - Name
- On Success:
  - Status: `200 OK`
- On Failure: 
  - Status: `401 Unauthorized`
  - Status: `409 Conflict`
  - Status: `500 Internal Server Error`
### **DELETE** `/Contacts/Unassign`
- Remove Tag For One Existing Contact
- Request Body:
  - Token
  - TagName
  - Name
- On Success:
  - Status: `200 OK`
- On Failure: 
  - Status: `401 Unauthorized`
  - Status: `409 Conflict`
  - Status: `500 Internal Server Error`
### **DELETE** `/Contacts/Remove`
- Remove Existing Contact
- Request Body:
  - Token
  - Name
- On Success:
  - Status: `200 OK`
- On Failure: 
  - Status: `401 Unauthorized`
  - Status: `409 Conflict`
  - Status: `500 Internal Server Error`
### **DELETE** `/Contacts/RemoveTag`
- Remove Existing Tag
- Request Body:
  - Token
  - TagName
- On Success:
  - Status: `200 OK`
- On Failure: 
  - Status: `401 Unauthorized`
  - Status: `409 Conflict`
  - Status: `500 Internal Server Error`