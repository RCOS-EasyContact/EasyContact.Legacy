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
  - Status: `511` Network Authentication Required
  - Status: `500` Internal Server Error
### **GET** `/Contacts/AllNames`
- Retrieve All Contact Names
- Request Body:
  - Token
- On Success:
  - Status: `200 OK`
  - Body: All Existing Contact Names
- On Failure: 
  - Status: `401` Unauthorized
  - Status: `500` Internal Server Error
