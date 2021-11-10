var http = require('http');
var fs = require('fs');

const PORT=3126; 

fs.readFile('sign_in.html', function (err, html) {

    if (err) throw err;    

    http.createServer(function(request, response) {  
        response.writeHeader(200, {"Content-Type": "text/html"});  
        response.write(html);  
        response.end();  
    }).listen(PORT);
    console.log('server on' + PORT);
});