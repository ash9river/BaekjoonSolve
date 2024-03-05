var fs = require('fs'); 
const [n,...input] = fs.readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt").toString().trim().split(process.platform === "linux" ? "\n" : "\r\n");
// const input = fs.readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt").toString().trim().split(/\s/);
let ans='';
for(let i=0;i<n;++i){
    let count=0;
    let numArray=Array.from({length:10},()=>false);
    for(let j=0;j<input[i].length;++j){
        let val=+input[i][j];
        if(!numArray[val]){
            numArray[val]=true;
            ++count;
        }
    }
    ans+=count+'\n';
}

console.log(ans);