var fs = require('fs'); 
const input = fs.readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt").toString().trim().split(process.platform === "linux" ? "\n" : "\r\n");
// const input = fs.readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt").toString().trim().split(/\s/);
let ans='';
input.map((item)=>{
    if(item[0]!=='#'){
        let count=0;
        let p=item[0].toLowerCase();
        let c=item[0].toUpperCase();
        for(let i=1;i<item.length;++i){
            if(item[i]===c||item[i]===p){
                ++count;
            }
        }
        ans+=p+' '+count+'\n';
    }
})

console.log(ans);