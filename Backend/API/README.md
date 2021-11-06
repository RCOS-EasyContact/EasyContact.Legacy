# EasyContact/Backend/API
## Easy Contact API Specifications
- This API is based on libhv in C++ and will be initialized as the backend database starts, and serves as an interface between node.js and database.  The API creates an HTTP server as a RESTful API.  
## Routes
### **POST** `/login`
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

## `/contacts`
### `POST /contacts/:contactName`
Create a contact with given `contactName`

#### Parameters
`contactName` should be provided.

#### Data Payload
`email`: string

#### Return Values
- `200` Created
- `400` Bad Request
- `406` Not Acceptable: Tag is not created.


### `DELETE /contacts/:contactName`
Delete a contact with given `contactName`

#### Parameter
`contactName` should be provided.

#### Return Values
- `200` OK
- `400` Bad Request: empty parameter
- `404` Not Found: no specific contactName


### `GET /contacts/all`
Get all contact informations

#### Return Body
```json
application/json: 
[{"name": "string", "email": "string"}, /*...*/]
```

#### Return Values
- `200` OK
- `404` Not Found (empty)


### `GET /contacts/tag/:contactName`
Get all tags associate with given `contactName`

#### Parameter
`contactName` must be provided.

#### Return Body
```json
application/json: 
[{"tag": "string"}, /*...*/]
```

#### Return Values
- `200` OK
- `400` Bad Request


### `DELETE /contacts/tag/:contactName`
Delete all tags associate with given `contactName`

#### Parameter
`contactName` must be provided.

#### Return Values
- `200` OK
- `400` Bad Request



## `/tags`
### `GET /tags/:tagName`
Get tag’s information based on `tagName` 

#### Return Body
```json
application/json: 
[{"name": "string"}, /*...*/]
```

#### Return Values
- `200` OK
- `400` Bad Request
- `404` Not Found


### `GET /tags/exist/:tagName`
Get if tag exist based on `tagName`

#### Return Values
- `200` Exist
- `404` Not Found


### `POST /tags/:tagName` 
Create a tag.

#### Parameters
only `tagName` should be provided

#### Return Values
- `200` Created 
- `400` Bad Request
- `406` Not Acceptable: Tag is not created.


### `DELETE /tags/:tagName`
Delete a tag.

#### Parameters
- Only `tagName`

#### Return Values
- `200` OK
- `400` Bad Request: empty parameter
- `404` Not Found: no specific tag



## `/books`
### `PUT /books/:contactName/:tagName`
Assign a tag for the contactName.

#### Parameters
- Both `contactName` and `tagName` must be provided.

#### Return Values
- `200` tag `contactName` with existing tag
- `400` Bad Request
- `404` Not Found: no specific `tagName`


### `DELETE /books/:contactName/:tagName`
Delete a tag for given `contactName`.

#### Parameters
- Both `contactName` and `tagName`

#### Return Values
- `200` OK
- `400` Bad Request: empty parameter
- `404` Not Found: no specific tagName for given contactName
