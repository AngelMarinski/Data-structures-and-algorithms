const name = document.getElementById('fullName');
const username = document.getElementById('username');
const email = document.getElementById('email');
const spassword = document.getElementById('spassword');
const repassword = document.getElementById('repassword');
const form = document.getElementById('registerForm');

form.addEventListener('submit', async event => {
    event.preventDefault();
    console.log('i am here');
    let messages = [];

    if (username.value.length < 6 || username.value.lenght >= 15) {
        messages.push('Username length is incorrect!');
    }
    if (spassword.value.length < 8 || spassword.value.lenght > 20) {
        messages.push('Password should be between 8 and 20 characters!');
    }
    if (spassword.value != repassword.value) {
        messages.push('Password does not match!');
    }

    if (messages.length > 0) {
        alert(messages[0]);
        return;
    }

    const response = await fetch('http://localhost:2000/register', {
        method: 'POST',
        body: {
            username: username.value,
            name: name.value,
            password: spassword.value,
            email: email.value
        }
    });
})