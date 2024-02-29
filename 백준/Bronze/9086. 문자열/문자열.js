var fs = require('fs'); 
const [n, ...arr] = fs.readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt").toString().trim().split(process.platform === "linux" ? "\n" : "\r\n");
arr.map((item)=>console.log(item[0]+item[item.length-1]));