async function main() {
    try {
        let express = require('express');

        //let port = process.env.PORT || 2000;

        //const { Client } = require('pg');
        //const client = new Client({
        //    user: 'postgres',
        //    host: 'localhost',
        //    database: 'postgres',
        //    password: 'postgres',
        //    port: 5432,
        //});
        //await client.connect();

        const database = new Map();
        const app = express();

        app.post('/register', async (request, response) => {
            const user = request.body;
            //const res = await client.query('INSERT INTO TABLE USERS(name,username,email,password) VALUES($1, $2, $3, $4)', [user.name, user.username, user.email, user.password]);
          
            database.set(user.username, user.password);
        });
        app.post('/login', async (request, response) => {
            const user = request.body;
            //const res = await client.query('INSERT INTO TABLE USERS(name,username,email,password) VALUES($1, $2, $3, $4)', [user.name, user.username, user.email, user.password]);
            if (!database.has(user.username) || database[user.username] != user.password) {
                alert('Wrong username or password!');
                return;
            }
            alert('Hello' + user.username);
        });
        app.listen(2000);
    } catch (error) {
        console.log(error);
    }

}

main();
