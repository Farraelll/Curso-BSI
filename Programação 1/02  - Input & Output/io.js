const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('', (input) => {
    
  console.log(`Olá, ${input}`);
  rl.close();
});