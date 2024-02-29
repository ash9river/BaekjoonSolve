var fs = require('fs'); 
const input = fs.readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt").toString().trim().split(process.platform === "linux" ? "\n" : "\r\n");
const maxLength = Math.max(...input.map(item => item.length));
let stringArray=Array.from({length:maxLength},()=>"");
input.map((item)=>{
    let count=0;
    for(let i=0;i<item.length;++i){
        stringArray[i]+=item[i];
    }
    ++count;
});
let ans=stringArray.join('');
console.log(ans);