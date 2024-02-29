var fs = require('fs'); 
const input = fs.readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt").toString().trim().split(process.platform === "linux" ? "\n" : "\r\n");
input.map((item)=>console.log(item));