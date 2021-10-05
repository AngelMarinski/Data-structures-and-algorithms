const username = document.getElementById('name');
const password = document.getElementById('password');
const form = document.getElementById('login');

form.addEventListener('submit', event => {
    event.preventDefault();

    const response = await fetch('http://localhost:2000/login', {
        method: 'POST',
        body: {
            username: username.value,
            password: password.value
        }
    });
})