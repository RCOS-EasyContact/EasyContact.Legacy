# EasyContact/Backend/API
## Easy Contact API Specifications
- This API is based on libhv in C++ and will be initialized as the backend database starts, and serves as an interface between node.js and database.  The API creates an HTTP server as a RESTful API.  
- Current state: Working


## `/login`
### `POST /login/:userName/:password`
create (and encrypt?) login information

#### Parameters
All two parameters (`userName`, `password`) should be provided.

#### Return Values
- `200` Succeed login
- `400` Bad Request
- `505` Invalid information



## `/keys`
### `GET /keys/:contactName`
Get key’s information based on name 

#### Return Body
```json
application/json: 
{ "name": "string", "email": "string", ["tag": "string", ...] }
```
#### Return Values
- `200` OK
- `400` Bad Request
- `404` Not Found


### `POST|PUT /keys/:contactName`
Create/Modify a key.

#### Parameters
All two parameters (`contactName`, `email`) should be provided.

#### Return Values
- `200` OK (`PUT`)
- `201` Created (`POST`)
- `400` Bad Request
- `404` Not Found: The key cannot be updated since it does not exist. (`PUT`)
- `406` Not Acceptable: Key is not created.
- `410` Conflict: This will be returned when the key is conflicted with name.
- `500` Internal Error: The API cannot perform remove and add contact. (`PUT`)



### `DELETE /keys/:contactName`
Delete a key.

#### Parameters
Only `contactName`

#### Return Values
- `200` OK
- `400` Bad Request: empty parameter
- `404` Not Found: no specific contact



## `/tags`
### `GET /tags/:tagName`
Get tag’s information based on `tagName` 

#### Return Body
```json
application/json: 
[{"name": "string", "email": "string"}, ...]
```

#### Return Values
- `200` OK
- `400` Bad Request
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
### `POST|PUT /books/:contactName/:tagName`
Create a tag for the contactName.

#### Parameters
- Both `contactName` and `tagName` must be provided.

#### Return Values
- `200` tag `contactName` with existing tag
- `201` created a new tag and tag `contactName` with it
- `400` Bad Request
- `404` Not Found: no specific `contactName`
- `406` Not Acceptable: Tag is not created.
- `500` Internal Error: The API cannot perform remove and add tag. (`PUT`)


### `DELETE /books/:contactName/:tagName`
Delete a tag for given `contactName`.

#### Parameters
- Both `contactName` and `tagName`

#### Return Values
- `200` OK
- `400` Bad Request: empty parameter
- `404` Not Found: no specific contactName
- `405` Not Found: no specific tagName for given contactName
