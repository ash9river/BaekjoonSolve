var fs = require('fs'); 
// const input = fs.readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt").toString().trim().split(process.platform === "linux" ? "\n" : "\r\n");
const input = fs.readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt").toString().trim().split(/\s/);
let a=parseInt(input[0]);
let b=parseInt(input[1]);
let c=parseInt(input[2]);
let d=parseInt(input[3]);
let e=parseInt(input[4]);
let f=parseInt(input[5]);
for(let i=-999;i<1000;++i){
    for(let j=-999;j<1000;++j){
        if(a*i+b*j===c&&d*i+e*j===f){
            console.log(`${i} ${j}`);
        }
    }
}