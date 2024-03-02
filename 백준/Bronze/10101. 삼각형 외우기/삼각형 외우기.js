var fs = require('fs'); 
const [...input] = fs.readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt").toString().trim().split(process.platform === "linux" ? "\n" : "\r\n");
// const input = fs.readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt").toString().trim().split(/\s/);
const [a,b,c]=input.map(Number);

let ans;
if(a+b+c!==180) ans='Error';
else{
    if(a===60&&b===60&&c===60) ans='Equilateral';
    else if(a===b||a===c||b===c) ans='Isosceles';
    else ans='Scalene';
} 

console.log(ans);