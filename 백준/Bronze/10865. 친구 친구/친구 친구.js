var fs = require('fs'); 
const [firstInput,...input] = fs.readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt").toString().trim().split(process.platform === "linux" ? "\n" : "\r\n");
// const input = fs.readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt").toString().trim().split(/\s/);
const [n,m]=firstInput.split(' ').map(Number);

const array=Array.from({length:n},()=>0);

for(let i=0;i<m;++i){
    const [a,b]=input[i].split(' ').map(Number);
    array[a-1]++;
    array[b-1]++;
}
let ans='';

array.map((item)=>ans+=item+'\n');

console.log(ans);