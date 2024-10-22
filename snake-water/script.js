import ("math");
let t=0;
for (let i=0;i<=9;i++){
let u=Math.random()*4;
u=Math.floor(u)
let a=prompt("enter your choice \n1.snake \n2.water\n3.gun")
  
if(u==a){
  alert("match draw")
  t=t+0.5
}
else if(a==1&&u==2){
  alert("you  won with snake")
  t++
}
else if(a==1&&u==3){
  alert("you loss due to gun")
}
else if(a==2&&u==1){
  alert("you  lose due to snake")
}
else if(a==2&&u==3){
  alert("you  won with water")
  t++;
}
else if(a==3&&u==1){
  alert("you  won with gun")
  t++
}
else if(a==3&&u==2){
  alert("you  loss due to water")
}
else if(u==0)
{continue;}
else{
  break;
}
}
alert(`number of correct times ${t}`)