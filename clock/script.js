setInterval(()=>{
    let d=new Date().toDateString()
    let y=new Date().toTimeString() 
   document.getElementById("container").innerHTML=[d,y]
 },1000)
 